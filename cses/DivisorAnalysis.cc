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
OVERLOAD_OSTREAM_OPERATOR( set );
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
//                                  [ Internal Force ]
//
//                            Two small bundled shapes
//                        on the frozen ice, one spins,
//                            one falls, both laughing.
//
//                                            DeepSeek
//
// 2.2.6. Two sisters are standing on skates on smooth
// ice. The older sister pushes the younger one. Both
// start to glide, but the younger one moves
// noticeably faster than the older one. "Okay, now
// I'll push you", says the younger sister. Contrary
// to what she expects, she again rolls away with
// greater speed than her older sister — and by
// exactly the same factor as before. Why does this
// happen?
//
// The force between them is internal to the system
// so to speak, zo the center of mass is not changing,
// that is as vectors (mυ + Mu)/(m + M) = 0, and the
// speed is υ = (M/m)u
//
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
constexpr i64 MOD = 1'000'000'007;
//////////////////////////////////////////////////////
// Theory Section( Caro-Konn ):
//
// Let's have primary factorization of n:
// 
//      α₁ α₂ ... αₖ
// n = p₁ p₂ ... pₖ
//
// The number of all divisors of n is:
//
// τ(n) = Π (αᵢ + 1) = (α₁ + 1)(α₂ + 1)...(αₖ + 1),
//
// becooz a prime pᵢ can participate in the divisors 
// as 1, pᵢ, pᵢ², ..., or pᵢ^αᵢ, that is in αᵢ + 1
// ways, so for each of the (α₁ + 1) choices of the
// fyorst factor we have (α₂ + 1) for the second and
// so forth.
//
// Similarly the sum of all divisors is:
//
// σ(N) = Π (1 + pᵢ + pᵢ² + ... + pᵢ^αᵢ), using the
// formula x^(n+1)-1 = (x-1)(1 + x + ... + x^n) this
// equals to:
// σ(N) = Π (pᵢ^(αᵢ + 1) - 1)/(pᵢ - 1)
//
// For the product, let's look at the prime pᵢ;
// as before, it enters with one of these:
// 1, pᵢ, pᵢ², ..., or pᵢ^αᵢ, all other combos not
// including pᵢ are τ(n)/(αᵢ + 1), so every term  
// should end up with a power of τ(n)/(αᵢ + 1), zo pᵢ
// contribution is:
// pᵢ^τ(n)/(αᵢ + 1) * pᵢ²^τ(n)/(αᵢ + 1) * ...
// = pᵢ^αᵢ(αᵢ+1)/2^τ(n)/(αᵢ + 1) = pᵢ^αᵢτ(n)/2,
// if we take all products then:
// π(n) = (p₁^α₁)(p₂^α₂)...(pₖ^αₖ))^τ(n)/2 = n^τ(n)/2
// which turns out quite simple the only problem is
// how to calculate it modulo 1e9 + 7
//
//////////////////////////////////////////////////////
i32 k;
vector<i64> p, a;
//////////////////////////////////////////////////////
i64 cotau() { // compute tau
  i64 tau = 1;
  for( i32 i = 0; i < k; ++i ){
    tau *= a[i] + 1;
    tau %= MOD;
  }
  return tau;
}
//////////////////////////////////////////////////////
// x^y mod m
// y = 2(y/2) + [odd(y)], zo
// x^y = (x^(y/2))^2 * x^[odd(y)]
i64 modexp( i64 x, i64 y, i64 m ){
  if( !y ){ return 1; }
  i64 e = modexp( x, y/2, m );
  i64 e2 = e * e % m;
  if( y & 1 ){
    return e2 * x % m;
  }
  return e2;
}
//////////////////////////////////////////////////////
// thats tricky we have to calculate this:
// σ(N) = Π (pᵢ^(αᵢ + 1) - 1)/(pᵢ - 1) mod 1e9 + 7, but
// there is a denominator. Here we use the Fermat
// Little Theorem( yea modulo arithmetic is quite
// annoying :)
//
// x^(m-1) mod m = 1 mod m, vhere m is prime, from
// here the inverse of y mod m is y^(m-2) mod m
i64 cosigma() {
  i64 sigma = 1;
  for( i32 i = 0; i < k; ++i ){
    i64 A = modexp( p[i], a[i] + 1, MOD );
    i64 B = modexp( p[i] - 1, MOD - 2, MOD );
    sigma *= (A - 1 + MOD) % MOD * B % MOD;
    sigma %= MOD;
        }
  return sigma;
}
//////////////////////////////////////////////////////
// If previous was tricky that is evil, first the τ(n)
// can be quite large and second it is divided by two.
// For large exponents we can use a formula from the
// Fermat Little Theorem: a^p mod p = a mod p, which
// is equivalent to a^(p-1) mod p = 1 mod p, so if we
// have to compute a^n mod p, then we represent n as:
// n = q(p-1) + n mod (p-1), zo
//
// a^n mod p = a^(n mod (p-1)) mod p,
//
// that way we can reduce large n. The second issue is
// that the formula is:
//
// π(n) = n^τ(n)/2, where:
// n = Π pᵢ^αᵢ
// τ(n) = Π (αᵢ + 1), now we have to consider two
// scenarios:
// a) all αᵢ are even, then
//    π(n) = (Π pᵢ^αᵢ)^τ(n)/2 = (Π pᵢ^(αᵢ/2))^τ(n)
// b) if some αᵢ is odd say a₁, then we have to
//    redefine τ(n) as ((α₁ + 1)/2)(α₂ + 1)...(αₖ + 1)
i64 copi_odd() {
  i64 A = 1;
  for( i32 i = 0; i < k; ++i ){
    A *= modexp( p[i], a[i], MOD );
    A %= MOD;
  }
  i64 tau = (a[0] + 1) / 2;
  for( i32 i = 1; i < k; ++i ){
    tau = tau * (a[i] + 1) % (MOD - 1);
  }
  return modexp( A, tau, MOD );
}
i64 copi_even() {
  i64 A = 1;
  for( i32 i = 0; i < k; ++i ){
    A *= modexp( p[i], a[i]/2, MOD );
    A %= MOD;
  }
  i64 tau = 1;
  for( i32 i = 0; i < k; ++i ){
    tau = tau * (a[i] + 1) % (MOD - 1);
  }
  return modexp( A, tau, MOD );
}
i64 copi() {
  bool odd = false;
  for( i32 i = 0; i < k; ++i ){
    if( a[i] & 1 ){
      swap( a[i], a[0] );
      swap( p[i], p[0] );
      odd = true;
      break;
    }
  }
  return odd ? copi_odd() : copi_even();
}
//////////////////////////////////////////////////////
void pusk() {
  k = loads<i32>();
  p.resize( k );
  a.resize( k );

  for( i32 j = 0; j < k; ++j ){
    tie( p[j], a[j] ) = loadp<i64>();
  }
  dbg( k );
  dbg2( p, a );
  cout << cotau() << sp
       << cosigma() << sp
       << copi() << nl;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//                            [ Voices from the Void ]
//
//                               Beyond our reach, far
//                            across the endless ocean,
//                                  only shadows speak.
//
//                                             ChatGPT
//
// 2.2.7. During observations from Earth, it is
// possible to determine only the radial velocity of
// the companion stars that make up a binary star
// system (i.e., the projection of the velocity onto
// the line connecting Earth and the star).
// Measurements give the radial velocities υ₁ and u₁
// of the two companion stars of the binary system.
// During repeated measurements carried out one year
// later, the values of these velocities were found to
// be υ₂ and u₂. Find the ratio of the masses of the
// companion stars that make up this binary system.
// Why do the calculations need to be changed if the
// repeated measurement is carried out after one month
// or six months?
//
// zo as vectors we have mυ + Mu = const, thats
// true for their projections as well, zo:
// mυ₁ + Mu₁ = mυ₂ + Mu₂, 
// m/M(υ₁ - υ₂) = u₂ - u₁,
// m/M = (u₂ - u₁)/(υ₁ - υ₂),
// for the second question the Earth should be at the
// same position after one year cos its speed is
// changing while orbiting the Sun, so the measuring
// labs should have identical velocities
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
////// Divisor Analysis                         //////
//////                                          //////
////// Given an integer, your task is to find   //////
////// the number, sum and product of its       //////
////// divisors. As an example, let us consider //////
////// the number 12:                           //////
//////                                          //////
////// the number of divisors is 6              //////
////// (they are 1, 2, 3, 4, 6, 12)             //////
////// the sum of divisors is 1+2+3+4+6+12=28   //////
////// the product of divisors is               //////
////// 1*2*3*4*6*12 = 1728                      //////
//////                                          //////
////// Since the input number may be large, it  //////
////// is given as a prime factorization.       //////
//////                                          //////
////// [ Input ]                                //////
////// The first line has an integer k: the     //////
////// number of parts in the prime             //////
////// factorization. After this, there are k   //////
////// lines that describe the                  //////
////// factorization. Each line has two numbers //////
////// p and α where p is a prime and α is its  //////
////// power.                                   //////
//////                                          //////
////// [ Output ]                               //////
////// Print three integers modulo 1e9+7: the   //////
////// number, sum and product of the divisors. //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 <= k <= 1e5                            //////
////// 2 <= p <= 1e6                            //////
////// each p is a distinct prime               //////
////// 1 <= α <= 1e9                            //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 2                                        //////
////// 2 2                                      //////
////// 3 1                                      //////
//////                                          //////
////// Output:                                  //////
////// 6 28 1728                                //////
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
//
// ⁰ ¹ ² ³ ⁴ ⁵ ⁶ ⁷ ⁸ ⁹
// ₀ ₁ ₂ ₃ ₄ ₅ ₆ ₇ ₈ ₉
// ⁺ ⁻ ⁼ ⁽ ⁾             
// ₊ ₋ ₌ ₍ ₎             
// ⁿʷʸᶻ                  
// ᶿ
// 
//////////////////////////////////////////////////////
