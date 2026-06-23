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
OVERLOAD_OSTREAM_OPERATOR( unordered_set );
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
constexpr i32 CAP = 200001;
// ===================================================
i32 n;
i32 color[CAP];
vector<i32> adj[CAP];
// ---------------------------------------------------
i32 distinct[CAP];
unordered_set<i32> d[CAP];
//////////////////////////////////////////////////////
// <> 2.1.61*. A circular chain of mass m is fitted
// around the rim of a horizontal disk of radius
// R. The tension in the chain is T. Determine the
// coefficient of friction between the disk and the
// chain, given that the chain flies/slides off the
// disk when the disk is rotated with angular velocity
// ω or greater.
//                     2Tsin(dα/2) - N = (dm)ω²R, zo -
//       __===__       if ω increase the reaction of -
//     ==  dm   ==.    the disk N will decrease, the -
//     `         `  `.    critical value being:      -
//      `       `      `. μN = (dm)g, now we have to -
//       ` dα  `       T  express dm as a function   -
//     R  `   `           of dα and cancel it        -
//         ` `            dm = (m/2πR)ds =           -
//          `             =(m/2πR)Rdα,               -
//                        dm = (m/2π)dα              -
// for small x sinx ≈ x, zo                          -
// N = Tdα - (dm)ω²R = (T2π/m)dm - (dm)ω²R =         -
//   = dm(T2π/m - ω²R), zo                           -
// μ = mg/(2πT - mω²R)                               -
//////////////////////////////////////////////////////
void dfs( i32 u, i32 t ){
  for( auto v: adj[u] ){
    if( v == t ){ continue; }
    dfs( v, u );
    distinct[v] = d[v].size();
    if( d[v].size() > d[u].size()){
      swap( d[v], d[u] );
    }
    for( auto c: d[v] ){
      d[u].insert( c );
    }
  }
}
//////////////////////////////////////////////////////
void bld() {
  dmp( d, n + 1 );
  dfs( 1, 0 );
  dmp( d, n + 1 );
  distinct[1] = d[1].size();
  dmp( distinct, n + 1 );
}
//////////////////////////////////////////////////////
// Example 2.2.7 (A girl born in winter). A family has
// two children. Find the probability that both
// children are girls, given that at least one of the
// two is a girl who was born in winter. In addition
// to the assumptions from Example 2.2.5, assume that
// the four seasons are equally likely and that gender
// is independent of season.  (This means that knowing
// the gender gives no information about the
// probabilities of the seasons, and vice versa; see
// Section 2.5 for much more about independence.)
//
// B - at least one of the two is a girl who was born
//     in winter
// A - both children are girls
//
//    (G1,B2) - first child is girl born in spring
//              second child is boy born in summer
// B: a) (G4,G4)         - 1
//    b) (G4,G[1,2,3])   - 3
//    c) (G4,B[1,2,3,4]) - 4
//    d) (G[1,2,3],G4)   - 3
//    e) (B[1,2,3,4],G4) - 4, Total = 15
//
//    P(A|B) = a) + b) + d)/15 = 7/15
//
//////////////////////////////////////////////////////
void pusk()
{
  n = loads<i32>(); dbg( n );
  
  for( i32 k = 1; k <= n; ++k ){
    cin >> color[k];
    d[k].insert( color[k] );
  } dmp( color, n + 1 );

  for( i32 k = 1; k < n; ++k ){
    auto [a,b] = loadp<i32>();
    adj[a].push_back( b );
    adj[b].push_back( a );
  } dmp( adj, n + 1 );

  bld();
  for( i32 k = 1; k <= n; ++k ){
    cout << distinct[k] << sp;
  }
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//
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
////// Distinct Colors                          //////
//////                                          //////
////// You are given a rooted tree consisting   //////
////// of n nodes. The nodes are numbered       //////
////// 1,2,...,n, and node 1 is the root. Each  //////
////// node has a color. Your task is to        //////
////// determine for each node the number of    //////
////// distinct colors in the subtree of the    //////
////// node.                                    //////
//////                                          //////
////// [Input]                                  //////
////// The first input line contains an integer //////
////// n: the number of nodes. The nodes are    //////
////// numbered 1,2,...,n. The next line        //////
////// consists of n integers c_1,c_2,...,c_n:  //////
////// the color of each node. Then there are   //////
////// n-1 lines describing the edges. Each     //////
////// line contains two integers a and b:      //////
////// there is an edge between nodes a and b.  //////
//////                                          //////
////// [Output]                                 //////
////// Print n integers: for each node          //////
////// 1,2,...,n, the number of distinct        //////
////// colors.                                  //////
//////                                          //////
////// [Constraints]                            //////
////// 1 <= n <= 2e5                            //////
////// 1 <= a,b <= n                            //////
////// 1 <= c_i <= 1e9                          //////
//////                                          //////
////// [Example]                                //////
////// Input:                                   //////
////// 5                                        //////
////// 2 3 2 2 1                                //////
////// 1 2                                      //////
////// 1 3                                      //////
////// 3 4                                      //////
////// 3 5                                      //////
//////                                          //////
////// Output:                                  //////
////// 3 1 2 1 1                                //////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// log:
//
