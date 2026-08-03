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
constexpr i64  MOD = 1e9+7;
constexpr i32 MAXA = 1e6;
vector<i64> f(MAXA + 1); // factorial
// x^y % MOD
i64 modexp( i64 x, i64 y ){
  if( y == 0 ){ return 1LL; }
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
  f[0] = 1;
  for( i32 i = 1; i <= MAXA; ++i ){
    f[i] = i * f[i-1] % MOD;
  }
}
i64 C( i64 n, i64 k ){
  return f[n] * inv( f[k] * f[n - k] % MOD ) % MOD;
}
void pusk() {
  bld();
  auto n = loads<i32>();
  while( n-- ){
    auto [a,b] = loadp<i64>();
    cout << C( a, b ) << nl;
  }
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//                                [ Echoes of Korhal ]
// 
//                              Zergs advance in waves
//                      Heavy Tanks hold back the tide
//                                Squad 3 fights alone
//
//                                             ジェミニ
//
// 61-3-1 Let a and b be coprime numbers. Prove that
// among all prime numbers whose square does not
// divide the number a+b, only the square of the
// number 3 can simultaneously divide the numbers
// (a+b)² and a³+b³.
//
// Yea I'm not very good at math, but let's assume we
// have a prime p:
//
// p²|(a+b)²                                       (1)
// p²|a³+b³ = (a+b)(a²-ab+b²)                      (2)
// 
// From (1) we have (a+b)² = π²p² for some integer π,
// zo a+b = πp and becoz p² doesn't divide (a+b), we
// have gcd of π and p equals to one:
//
// a+b = πp ( p|a+b )                              (3)
// (π,p) = 1                                       (4)
//
// Substituting (3) in (2) we get:
//
// p²|(a+b)(a²-ab+b²) = πp(a²-ab+b²), that is
// p|π(a²-ab+b²), now becoz of (4) we have
//
// p|a²-ab+b²                                      (5)
//
// This is actually a theorem:
//
// Theorem 1.4: If a|bc and (a,b) = 1, then a|c.
// » The proof is using the extended Euclid on (a,b):
// aζ + bυ = 1, for some integers ζ and υ, multiplying
// by c gives acζ + bcυ = c, now becoz a|bc we can
// write bc = aρ for some integer ρ:
// acζ + aρυ = a(cζ + ρυ) = c, that is a|c «
//
// in (5) we can represent the right side as:
// (a+b)² - 3ab, so we have:
//
// p|a+b                                           (6)
// p|3ab                                           (7)
//
// Now if a is prime and a|bc then a|b or a|c or both,
// becoz if we look at (a,b) it must be either a or 1,
// if it is a then a|b, if it is 1 then by Theorem 1.4
// a|c, zo from (7) we have p|3 or p|a or p|b. If p|a
// then from (6) p|b as well, but becoz a and b are
// coprimes this is not possible zo p|3, that is p = 3
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
////// Binomial Coefficients                    //////
//////                                          //////
////// Your task is to calculate n binomial     //////
////// coefficients modulo 10^9+7. A binomial   //////
////// coefficient C(a,b) can be calculated     //////
////// using the formula a!/b!(a-b)!. We assume //////
////// that a and b are integers, 0 <= b <= a   //////
//////                                          //////
////// [ Input ]                                //////
////// The first input line contains an integer //////
////// n: the number of calculations.  After    //////
////// this, there are n lines, each of which   //////
////// contains two integers a and b.           //////
//////                                          //////
////// [ Output ]                               //////
////// Print each binomial coefficient modulo   //////
////// 10^9+7.                                  //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 <= n <= 1e5                            //////
////// 0 <= b <= a <= 1e6                       //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 3                                        //////
////// 5 3                                      //////
////// 8 1                                      //////
////// 9 5                                      //////
//////                                          //////
////// Output:                                  //////
////// 10                                       //////
////// 8                                        //////
////// 126                                      //////
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
