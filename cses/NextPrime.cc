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
//
// So we are given some large number n ≈ 1e12 and want
// to find the next prime after it. There is one
// theorem that states that the number of primes <= n
// is ≈ n/ln(n) so on average the distance between
// primes is ln(n) for 1e12 that means we can expect
// the next prime to be found in the next 27 numbers
// or so. That is we can try prime testing on those
// numbers using the normal O(√n) method, cos the
// total running time should be around 1e6
//
//////////////////////////////////////////////////////
vector<bool> sieve;
vector<i64> primes;
//////////////////////////////////////////////////////
void bld_sieve( const i64 maxn = 1e6 ){
  sieve.resize( maxn + 1 );
  for( i64 x = 2; x <= maxn; ++x ){
    if( sieve[x] ) continue;
    primes.push_back( x );
    for( i64 y = x * x; y <= maxn; y += x ){
      sieve[ y ] = true;
    }}}
//////////////////////////////////////////////////////
void initialize() {
  bld_sieve();
}
//////////////////////////////////////////////////////
bool prime_test( i64 n ){
  for( auto p: primes ){
    if( p * p > n ) break;
    if( n % p == 0 ) return false;
  }
  return true;
}
//////////////////////////////////////////////////////
i64 next_prime( i64 n ){
  while( !prime_test( ++n ))
    ;
  return n;
}
//////////////////////////////////////////////////////
void pusk() {
  initialize();
  auto t = loads<i32>();
  while( t-- ){
    auto n = loads<i64>();
    dbg( n );
    cout << next_prime( n ) << nl;
  }
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//                               [ Research Facility ]
//
//                                      Goliath online
//                    Streaming data fills the screens
//                                   Systems now align
//
//                                          チャットGPT
//
// <> 2.2.22*. A vessel filled with water of density
// ρ₀​ and volume V₀ rests on a smooth horizontal floor.
// A beetle of volume V and density ρ, initially lying
// on the bottom of the vessel, begins after some time
// to crawl along the bottom with speed u relative to
// the vessel. At what speed will the vessel move
// along the floor? Neglect the mass of the vessel.
// Assume that the surface of the water remains
// horizontal at all times.
//
// After the beetle is dropped at the vessel the water
// appears to have volume V₀ + V so we can split them
// by representing the water as ρ₀(V₀ + V) and the
// beetle as (ρ - ρ₀)V, zo relative to the vessel
// the cm will shift for time τ at a distance:
// x = (ρ - ρ₀)Vuτ/(ρV + ρ₀V₀), if we put the center
// of the vessel at ORIG, in lab system cm will stay
// the same and the center of the vessel will shift
// with -x zo υ = u(ρ₀ - ρ)V/(ρ₀V₀ + ρV)
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
////// Next Prime                               //////
//////                                          //////
////// Given a positive integer n, find the     //////
////// next prime number after it.              //////
//////                                          //////
////// [ Input ]                                //////
////// The first line has an integer t: the     //////
////// number of tests.  After that, each line  //////
////// has a positive integer n.                //////
//////                                          //////
////// [ Output ]                               //////
////// For each test, print the next prime      //////
////// after n.                                 //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 <= t <= 20                             //////
////// 1 <= n <= 1e12                           //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 5                                        //////
////// 1                                        //////
////// 2                                        //////
////// 3                                        //////
////// 42                                       //////
////// 1337                                     //////
//////                                          //////
////// Output:                                  //////
////// 2                                        //////
////// 3                                        //////
////// 5                                        //////
////// 43                                       //////
////// 1361                                     //////
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
