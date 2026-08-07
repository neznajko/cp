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
# define siz( a ) (i32) (a).size()
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
// 1. A spam filter is designed by looking at commonly
// occurring phrases in spam. Suppose that 80% of
// email is spam. In 10% of the spam emails, the
// phrase “free money” is used, whereas this phrase is
// only used in 1% of non-spam emails. A new email has
// just arrived, which does mention “free money”. What
// is the probability that it is spam?
//
// S - spam
// F - free money
// P(S) = 0.8
// P(¬S) = 0.2
// P(F|S) = 0.1
// P(F|¬S) = 0.01
//
// P(S|F) = P(F|S)P(S)/P(F),
// P(F) = P(F|S)P(S) + P(F|¬S)P(¬S)
//      = 0.1*0.8 + 0.01*.0.2 = 0.08 + 0.002 = 0.082
// P(S/F) = 0.1*0.8/0.082 ≈ 0.9756
//////////////////////////////////////////////////////
constexpr i32 N = 20;
vector<i64> f( N + 1 );
//////////////////////////////////////////////////////
void bld() {
  f[0] = 1;
  for( i32 i = 1; i <= N; ++i ){
    f[i] = f[i-1] * i;
  }
}
//////////////////////////////////////////////////////
// 1 1 2 2 3 3
// 2 3 1 3 1 2
// 3 2 3 1 2 1
vector<i32> getp( i32 n, i64 k ){
  vector<i32> p;
  vector<i32> ns( n ); // 1 2 ... n
  iota( on( ns ), 1 ); // the Greek letter iota
  while( !ns.empty() ){
    auto g = f[ siz( ns ) - 1 ];
    auto q = (k - 1) / g;
    auto r = (k - 1) % g;
    p.push_back( ns[ q ]);
    ns.erase( ns.begin() + q );
    k = r + 1;
  }
  return p;
}
//////////////////////////////////////////////////////
vector<i32> getinvs( const vector<i32>& p ){
  const auto n = siz( p );
  vector<i32> invs( n );
  for( i32 i = 0; i < n; ++i ){
    for( i32 j = i + 1; j < n; ++j ){
      if( p[j] < p[i] ) ++invs[i];
    }    
  }
  return invs;
}
//////////////////////////////////////////////////////
i64 getk( const vector<i32>& p ){
  dbg( p );
  const auto n = siz( p );
  auto invs = getinvs( p );
  dbg( invs );
  i64 k = 0;
  i32 g = n - 1;
  for( i32 i = 0; i < n; ++i ){
    k += invs[i] * f[g--];
  }
  return k + 1;
}
//////////////////////////////////////////////////////
void pusk() {
  bld();
  auto t = loads<i32>();
  while( t-- ){
    auto [q,n] = loadp<i32>();
    dbg( n );
    if( q == 1 ){
      auto k = loads<i64>();
      dbg( k );
      auto p = getp( n, k );
      for( auto y: p ) cout << y << sp;
      cout << nl;
    } else {
      auto p = loadv<i32>( n );
      dbg( p );
      cout << getk( p ) << nl;
    }
  }
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// 2.2.25*. A space station consists of two
// compartments of masses m₁ and m₂, connected by a
// long uniform cable of length L. The station rotates
// about an axis perpendicular to the cable. What is
// the angular velocity of rotation if the tension in
// the cable near the first compartment is T₁, and
// near the second is T₂? What is the mass of the
// cable?
//
// Lets put ORIG at m₁, the cm will be at distance l₁:
// l₁ = [ m(l/2) + m₂l ]/( m₁ + m₂ + m ) =
//    = l[ m/2 + m₂ ]/{ m₁ + m₂ + m }, this will be
// the radius of m₁ in cm the radius of m₂ is:
// l₂ = l - l₁ = l( 1 - [ m/2 + m₂ ]/{ m₁ + m₂ + m })
//    = l( m₁ + m₂ + m - m/2 - m₂ )/{ m₁ + m₂ + m } =
//    = l( m₁ + m/2 )/{ m₁ + m₂ + m }, zo
//
// m₁ω²l₁ = T₁
// m₂ω²l₂ = T₂, l₂/l₁ = ( m₁ + m/2 )/[ m/2 + m₂ ] =
// = T₂m₁/T₁m₂,
// T₁m₂m₁ + T₁m₂m/2 = T₂m₁m/2 + T₂m₁m₂
// (T₁ - T₂)m₂m₁ = (T₂m₁ - T₁m₂)m/2,
// m = 2m₁m₂(T₁ - T₂)/(T₂m₁ - T₁m₂), from here after
// long thinking ... we get the answer for ω:
// ω = √[( m₂T₁ + m₁T₂ )/Lm₁m₂ ]
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
////// Permutation Order                        //////
//////                                          //////
////// Let p(n,k) denote the kth permutation    //////
////// (in lexicographical order) of 1 ... n.   //////
////// For example, p(4,1)=[1,2,3,4] and        //////
////// p(4,2)=[1,2,4,3]. Your task is to        //////
////// process two types of tests:              //////
//////                                          //////
////// Given n and k, find p(n,k)               //////
////// Given n and p(n,k), find k               //////
//////                                          //////
////// [ Input ]                                //////
////// The first line has an integer t: the     //////
////// number of tests. Each test is either     //////
////// "1 n k" or "2 n p(n,k)".                 //////
//////                                          //////
////// [ Output ]                               //////
////// For each test, print the answer          //////
////// according to the example.                //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 <= t <= 1000                           //////
////// 1 <= n <= 20                             //////
////// 1 <= k <= n!                             //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 6                                        //////
////// 1 4 1                                    //////
////// 1 4 2                                    //////
////// 2 4 1 2 3 4                              //////
////// 2 4 1 2 4 3                              //////
////// 1 5 42                                   //////
////// 2 5 2 4 5 3 1                            //////
//////                                          //////
////// Output:                                  //////
////// 1 2 3 4                                  //////
////// 1 2 4 3                                  //////
////// 1                                        //////
////// 2                                        //////
////// 2 4 5 3 1                                //////
////// 42                                       //////
//////                                          //////
//////////////////////////////////////////////////////
///////////////////////////////////////////########///
///////////////////////////////////////////########///
///////////////////////////////////////////########///
// log:                                    ########
//                                         ### ####
//                                        ###  ### 
//                                       ##   ##   
//                                       #     #
