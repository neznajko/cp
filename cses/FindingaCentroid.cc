// -*- c-file-style: "gnu" -*-
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
# include <bits/stdc++.h>
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
# undef DeBug
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
using namespace std;
//////////////////////////////////////////////////////
using i32 =  int32_t;
using u32 = uint32_t;
using i64 =  int64_t;
using u64 = uint64_t;
//////////////////////////////////////////////////////
constexpr char  nl = '\n';
constexpr char  sp =  ' ';
constexpr char tab = '\t';
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
template <typename T>
inline T loads() {
    T y; cin >> y;
    return y;
}
//////////////////////////////////////////////////////
template <typename T>
istream& operator>>( istream& s, vector<T>& v ){
    for( auto& y: v ){ s >> y; }
    return s;
}
//////////////////////////////////////////////////////
template <typename T>
inline vector<T> loadv( u32 n ){
    vector<T> y( n ); cin >> y;
    return y;
}
//////////////////////////////////////////////////////
template <typename T>
inline vector<vector<T>> loadt( u32 n, u32 m ){
    vector<vector<T>> y( n, vector<T>( m )); cin >> y;
    return y;
}
//////////////////////////////////////////////////////
template <typename T>
inline pair<T,T> loadp() {
    pair<T,T> y;
    cin >> get<0>( y ) >> get<1>( y );
    return y;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
inline void vrooom() {
  cin.tie( nullptr )->sync_with_stdio( false );
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
# define OVERLOAD_OSTREAM_OPERATOR( Container )                \
template <typename... T>                                       \
ostream& operator<<( ostream& os, const Container<T...>& con ){\
    os << "[";                                                 \
    string sep = "";                                           \
    for( const auto& y: con ){                                 \
        os << sep << y;                                        \
        sep = " ";                                             \
    }                                                          \
    return os << "]";                                          \
}
////////////////////////////////////////////////////////////////
OVERLOAD_OSTREAM_OPERATOR( vector );
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////
# ifdef DeBug
  template<typename T>
  inline void debug( string name, T x, string sep="\n" ){
    cerr << name << "=" << x << sep;
  }
# define dbg( x, ... ) debug( #x, x, ##__VA_ARGS__ )
# else
# define dbg( x, ... )
# endif
//####################################################
//////////////////////////////////////////////////////
# define dbg2(a,b) dbg(a,","); dbg(b)
# define on( x ) ( x ).begin(),( x ).end()
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
enum { BLACK, WHITE, GRAY, RED, 
       BLUE, ORANGE, MAGENTA, BROWN };
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////................
//////////////////////////////////////................
//////////////////////////////////////................
//////////////////////////////////////................
//####################################################
///////////////////////////////////////// /  /////////
//////////////////////////////////////// /  //////////
/////////////////////////////////////// /  ///////////
////////////////////////////////////// /  ////////////
template <typename T>
vector<T> vec( T* p, i32 n ){
  return vector<T>( p, p + n );
}
# ifdef DeBug
# define dmp( p, n ) cerr << #p << "=" << vec( p, n ) << nl;
# else
# define dmp( p, n )
# endif
///////////////////////////////////// /  /////////////
//////////////////////////////////// /  //////////////
/////////////////////////////////// /  ///////////////
////////////////////////////////// /  ////////////////
//
// 2.1.63. A horizontal disk is spun up about its axis
// so that its angular velocity increases linearly
// with time according to ω=εt. Determine the angular
// velocity at which a body situated at a distance r
// from the axis starts to slip relative to the disk,
// given that the coefficient of friction is μ.
constexpr i32 N = 2e5;
vector<i32> adj[N + 1];
i32 subs[N + 1];
i32 n;
i32 centroid = 0;
i32 mcentroid = 0;
// So the trick here is that there are two 
// accelerations cos the angular velocity is not
// constant ds = rdφ, ds/dt = rdφ/dt, υ = rω
// aτ = dυ/dt = rε
// an = ω²r, zo ma = μmg, gives the moment it will
// start slipping (rε)² + (ω²r)² = (μg)²
// r²ε²(1 + ε²t⁴) = (μg)²,
// ε² + (εt)⁴ = (μg/r)², 
// (εt)⁴ = (μg/r)² - ε²,
// εt = √⁴((μg/r)² - ε²), if μg/r > ε, else 0
//////////////////////////////////////////////////////
void update( i32 m, i32 u ){
  if( m <= n/2 ){
    if( m >= mcentroid ){
      mcentroid = m;
      centroid = u;
    }}}
//////////////////////////////////////////////////////
void dfs( i32 u, i32 t ){
  i32 m = 0;
  for( auto v: adj[u] ){
    if( v == t ){ continue; }
    dfs( v, u );
    subs[u] += subs[v];
    if( subs[v] > m ){ m = subs[v]; }
  }
  update( m, u );
  update( subs[u] - 1, u );
}
//////////////////////////////////////////////////////
// Example 2.4.4 (Random coin, continued). Continuing
// with the scenario from Example 2.3.7, suppose that
// we have now seen our chosen coin land Heads three
// times. If we toss the coin a fourth time, what is
// the probability that it will land Heads once more?
//
// M - flips heads once more
//
// P(M|H) = P(M|F,H)P(F|H) + P(M|B,H)P(B|H)
// P(B|H) = 1 - P(F|H) = 1 - 8/35 = 27/35
// P(M|F,H) = 1/2
// P(M|B,H) = 3/4
// P(M|H) = (1/2)(8/35) + (3/4)(27/35) =
//        = (16 + 3*27)/(4*35) = (16 + 81)/140 =
//        = 97/140
//
// Example 2.3.7 (Random coin). You have one fair
// coin, and one biased coin which lands Heads with
// probability 3/4. You pick one of the coins at
// random and flip it three times. It lands Heads all
// three times. Given this information, what is the
// probability that the coin you picked is the fair
// one?
//
// F - fair coin     | P(F|H) = ?
// B - biased coin   |
// H - ahead 3 times |
//
// P(F|H) = P(H|F)P(F)/P(H)
// P(H) = P(H|F)P(F) + P(H|B)P(B)
//
// P(F) = P(B) = 1/2
// P(H|F) = (1/2)³ = 1/8
// P(H|B) = (3/4)³ = 27/64
//
// P(H) = (1/8)(1/2) + (27/64)(1/2) = 35/128
// P(F|H) = (1/8)(1/2)/(35/128) = 8/35
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
void pusk() {
  n = loads<i32>();
  for( i32 j = 1; j < n; ++j ){
    auto [a,b] = loadp<i32>();
    adj[a].push_back( b );
    adj[b].push_back( a );
  }
  dbg( n );
  dmp( adj, n + 1 );
  // + calculate subtree sizes( subs )
  // + find centroid
  for( i32 k = 1; k <=n; ++k ){
    subs[k] = 1;
  }
  dfs( 1, 0 );
  dmp( subs, n + 1 );
  cout << centroid << nl;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//
// 2.1.64. What is the maximum speed at which a
// motorcyclist can ride on a horizontal surface while
// moving along a circular path of radius R, if the
// coefficient of friction is μ?  By what angle from
// the vertical must he lean while doing so?  By what
// factor will the maximum permissible speed of the
// motorcyclist increase when riding on a banked track
// inclined at an angle α to the horizontal, compared
// with the maximum permissible speed when riding on a
// horizontal track with the same turning radius and
// the same coefficient of friction?
//
// All right bring them on! Yea this problem is a bit
// of mess cos there was some similar problem smth
// like if we push a pencil no matter the force at
// some angle it will start slipping and that seems
// like exactly the same but in that case the reaction
// of the surface was at some angle while here the
// reaction is always vertical so the angle at which
// the motorcyclist should ride is due to its center
// of mass relative to the total reaction angle
// positioning dodging the angular momentum stuff but
// thats not in this chapter so its a bit unfair
//
// N = mg, the funny part is that the force that is
// responsible for the bending is the force of
// friction: f = μN = μmg = mυ²/R, υ² = μgR
//
// if the surface is on some angle we should look at
// force projections on xy plane
// Nsinα + μNcosα = mυ²/R
// Ncosα = μNsinα + mg, after long thinking ...
//
// u²/υ² = (tgα + μ)/μ(1 - μtgα)
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
int main() {
  vrooom();
  if( 0 ){
  } else {
    pusk();
  }}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////                                          //////  
////// Finding a Centroid                       //////
//////                                          //////
////// Given a tree of n nodes, your task is to //////
////// find a centroid, i.e., a node such that  //////
////// when it is appointed the root of the     //////
////// tree, each subtree has at most n/2 nodes //////
//////                                          //////
////// [Input]                                  //////
////// The first input line contains an integer //////
////// n: the number of nodes. The nodes are    //////
////// numbered 1,2,...,n.  Then there are n-1  //////
////// lines describing the edges. Each line    //////
////// contains two integers a and b: there is  //////
////// an edge between nodes a and b.           //////
//////                                          //////
////// [Output]                                 //////
////// Print one integer: a centroid node. If   //////
////// there are several possibilities, you can //////
////// choose any of them.                      //////
//////                                          //////
////// [Constraints]                            //////
////// 1 <= n <= 2e5                            //////
////// 1 <= a,b <= n                            //////
//////                                          //////
////// [Example]                                //////
////// Input:                                   //////
////// 5                                        //////
////// 1 2                                      //////
////// 2 3                                      //////
////// 3 4                                      //////
////// 3 5                                      //////
//////                                          //////
////// Output:                                  //////
////// 3                                        //////
//////                                          //////
//////////////////////////////////////////////////////
///////////////////////////////////////////########///
///////////////////////////////////////////########///
///////////////////////////////////////////########///
// log:                                    ########
// - yea i mean single pass is single pass ### ####
//                                        ###  ### 
// - Exactly — one DFS to rule them all. ##   ## 😄
//                                       #     #
//
