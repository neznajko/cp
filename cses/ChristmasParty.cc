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
// We can use inclusion-exclusion principle for this
// problem its funny that those permutations that
// doesn't have numbers on the same positions have
// their own name, they are called Derangement:)
constexpr i64 MOD = 1e9 + 7;
constexpr i32 N = 1e6;
vector<i64> f( N + 1 );
vector<i64> i( N + 1 );
i64 modexp( i64 x, i64 y ){
  if( y == 0 ) return 1LL;
  auto z = modexp( x, y/2 );
  i64 r = z * z % MOD;
  if( y & 1 ){
    r = r * x % MOD;
  }
  return r;
}
i64 inv( i64 x ){
  return modexp( x, MOD - 2 );
}
void bld() {
  i[0] = i[1] = f[0] = f[1] = 1;
  for( i32 j = 2; j <= N; ++j ){
    f[j] = f[j-1] * j % MOD;
    i[j] = inv( f[j] );
  }
}
void pusk() {
  auto n = loads<i32>(); dbg( n );
  bld();
  i64 tot = 0;
  for( i32 j = 2; j <= n; j += 2 ){
    tot = (tot + f[n] * i[j] % MOD) % MOD;
  }
  for( i32 j = 3; j <= n; j += 2 ){
    tot = (tot - f[n] * i[j] % MOD + MOD) % MOD;
  }
  cout << tot << nl;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//                                      [ Night Tide ]
//
//                                The old fishing boat
//                            Lonely at the quiet dock
//                                Settles in for sleep
//
//                                          チャットGPT
//
// <> 2.2.24*. Two bodies of masses m₁ and m₂ are
// connected by a taut string of length l and move
// along a smooth horizontal surface. At some moment
// in time, it turns out that the first body is
// stationary, while the velocity of the second body,
// equal to υ, is perpendicular to the string.
// Determine the tension in the string.
//
//                 υ  Yea of course we have cm again. 
//                 |  Lets put ORIG at m₁; then cm 
//                 |  speed is u = m₂υ/(m₁+m₂). In cm
//           cm    |  system m₁ will move with u along
// m₁--------------m₂ a circle with radius l₁:
// <   l₁   ><  l₂  > l₁ = lm₂/(m₁+m₂), so we can 
// write for the tension force:
// T = m₁u²/l₁ = m₁[m₂υ/(m₁+m₂)]²(m₁+m₂)/lm₂ =
//   = m₁m₂υ²/(m₁+m₂)l
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
////// Christmas Party                          //////
//////                                          //////
////// There are n children at a Christmas      //////
////// party, and each of them has brought a    //////
////// gift. The idea is that everybody will    //////
////// get a gift brought by someone else. In   //////
////// how many ways can the gifts be           //////
////// distributed?                             //////
//////                                          //////
////// [ Input ]                                //////
////// The only input line has an integer n:    //////
////// the number of children.                  //////
//////                                          //////
////// [ Output ]                               //////
////// Print the number of ways modulo 1e9+7.   //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 <= n <= 1e6                            //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 4                                        //////
//////                                          //////
////// Output:                                  //////
////// 9                                        //////
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
