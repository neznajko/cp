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
// 5. Three cards are dealt from a standard,
// well-shuffled deck. The first two cards are flipped
// over, revealing the Ace of Spades as the first card
// and the 8 of Clubs as the second card. Given this
// information, find the probability that the third
// card is an ace in two ways: using the definition of
// conditional probability, and by symmetry.
//
// If first two cards are fixed then we have 3 aces in
// 50 cards so P = 3/50
//////////////////////////////////////////////////////
constexpr i64 MOD = 1e9 + 7;
//////////////////////////////////////////////////////
// [ a, b ]
// [ c, d ]
struct Matrix {
  i64 a, b, c, d;
  Matrix operator*( const Matrix& other ) const {
    return {
      (a * other.a + b * other.c) % MOD,
      (a * other.b + b * other.d) % MOD,
      (c * other.a + d * other.c) % MOD,
      (c * other.b + d * other.d) % MOD
    };
  }
} I = {1, 0, 0, 1};
ostream& operator<<( ostream& s, const Matrix& mat ){
  return s << "\n[" << mat.a << sp << mat.b << "]"
           << "\n[" << mat.c << sp << mat.d << "]";
}
//////////////////////////////////////////////////////
Matrix modexp( Matrix x, i64 y ){
  if( !y ) return I;
  auto z = modexp( x, y/2 );
  z = z * z;
  if( y & 1 ) z = z * x;
  return z;
}
//////////////////////////////////////////////////////
void pusk() {
  auto n = loads<i64>();
  auto f = modexp({ 0, 1, 1, 1 }, n );
  cout << f.b << nl;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// 9. Sometimes it's possible to use induction
// backwards, proving things from n to n — 1 instead
// of vice versa! For example, consider the statement
//
// P(n): x₁...xₙ ≤ [(x₁+...+xₙ)/n]ⁿ, if x₁,...,xₙ ≥ 0
//
// This is true when n = 2, since
// (x₁ + x₂)² — 4x₁x₂ = (x₁ — x₂)² ≥ 0
//
// a) By setting xₙ = (x₁+...+xₙ₋₁)/(n — 1), prove
// that P(n) implies P(n — 1) whenever n > 1
//
// b) Show that P(n) and P(2) imply P(2n)
//
// c) Explain why this implies the truth of P(n) for
// all n.
//
// This induction looks like the Dirty Chess Tricks
// Series against Sicilian! It was introduced by
// Cauchy to prove the arithmetic mean-geometric mean
// inequality, that is this problem and is known as 
// forward-backward induction or Cauchy induction. So
// let's start from (b) we can group x₁x₂...x₂ₙ₋₁x₂ₙ
// as (x₁x₂)...(x₂ₙ₋₁x₂ₙ), now we can use P(2):
// (x₁x₂)...(x₂ₙ₋₁x₂ₙ) ≤ [(x₁+x₂)/2]²...[(x₂ₙ₋₁+x₂ₙ)/2]²
// ≤ [(x₁+x₂)...(x₂ₙ₋₁+x₂ₙ)]²/2²ⁿ, here we use P(n),
// ≤ {[(x₁+x₂+...+x₂ₙ₋₁+x₂ₙ)/n]ⁿ}²/2²ⁿ =
// = {(x₁+x₂+...+x₂ₙ₋₁+x₂ₙ)/2n]²ⁿ
// Ok now lets figure out a) we have P(n) and wanna
// prove P(n-1), by setting xₙ = (x₁+...+xₙ₋₁)/(n — 1)
// let's Aₙ := (x₁+...+xₙ)/n, then nAₙ = x₁+...+xₙ =
// = x₁+...+xₙ₋₁ + xₙ = (n-1)Aₙ₋₁ + xₙ =
// = (n-1)Aₙ₋₁ + Aₙ₋₁ = nAₙ₋₁, so Aₙ = Aₙ₋₁, now from
// x₁...xₙ ≤ [(x₁+...+xₙ)/n]ⁿ = Aₙⁿ it follows that
// x₁...xₙ₋₁xₙ = x₁...xₙ₋₁Aₙ₋₁ ≤ Aₙⁿ = Aₙⁿ⁻¹Aₙ =
// = Aₙ₋₁ⁿ⁻¹Aₙ₋₁, zo
// x₁...xₙ₋₁ ≤ Aₙ₋₁ⁿ⁻¹ = [(x₁+...+xₙ₋₁)/(n — 1)]ⁿ⁻¹,
// ok so the strategy is we prove smth for powers of 2
// like P(2),P(4),P(8),... and that P(n) implies 
// P(n-1), then we can prove P(n) for all n > 1 say
// P(5) by going backwards from P(8)
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
////// Fibonacci Numbers                        //////
//////                                          //////
////// The Fibonacci numbers can be defined as  //////
////// follows:                                 //////
////// F₀ = 0                                   //////
////// F₁ = 1                                   //////
////// Fₙ = Fₙ₋₁ + Fₙ₋₂                         //////
////// Your task is to calculate the value of   //////
////// Fₙ for a given n.                        //////
//////                                          //////
////// [ Input ]                                //////
////// The only input line has an integer n.    //////
//////                                          //////
////// [ Output ]                               //////
////// Print the value of Fₙ modulo 1e9+7.      //////
//////                                          //////
////// [ Constraints ]                          //////
////// 0 ≤ n ≤ 1e18                             //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 10                                       //////
//////                                          //////
////// Output:                                  //////
////// 55                                       //////
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
