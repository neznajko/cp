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
// Ok this requires a bit of group theory, thought I'm
// not the right person to give lectures on that
// topic, but lets consider for example a square ABCD:
//
// A---P---B  What symmetries we have here?
// |   |   |  If we take an axis perpendicular to the
// S---O---Q  square passing through O we can rotate
// |   |   |  at 0, π/2, π, 3π/2, 4 rotations, then 
// D---R---C  we can take π rotations around PR, SQ,
//            AC and BD axis totally 8 transformations
// that leaves the square the same, this rotations
// form a group G, with |G| = 8
//
// Now we go further and wanna color the sides of the
// square (AB,BC,CD,DA) with 3 colors, how many
// different squares we have. Naturally we can answer
// 81, right for each side 3 colors = 3x3x3x3 = 81,
// but the problem is that some of those squares are
// the same for example (R,R,B,B) and (B,B,R,R) we
// need just to rotate at π around AC. There is a
// formula called Burnside's Lemma which gives an
// answer how to do that, but to understand why it
// works we need another theorem known as the
// Orbit-Stabilizer Theorem:
//
// let X is some set in our case this will be the set
// of all 81 squares, and a group G( the 8 rotations ),
// we define the orbit of x ∈ X as:
// Orb(x) = { g⋅x | g ∈ G }, for example what is the
// orbit of (R,R,B,B), now we have to apply all
// transformations of G:
// 0    | (R,R,B,B) =  So as we can see we have applied
// π/2  | (B,R,R,B) <  8 transformations, but the
// π    | (B,B,R,R) -  resulting set consist of only 4
// 3π/2 | (R,B,B,R) +  different elements, cos multiple
// PR   | (R,B,B,R) +  different group transformations
// SQ   | (B,R,R,B) <  result in same squares like the
// AC   | (B,B,R,R) -  identity 0 and the BD rotations,
// BD   | (R,R,B,B) =  these are called stabilizers:
//
// Stab(x) = { g ∈ G | g⋅x = x }, from here it
// should be somehow clear that the size of the group
// |G| is equal to the size of the stabilizer times
// the size of the orbit:
// |G| = |Orb(x)||Stab(x)|, and this is true for all
// x ∈ X, if you need more rigorous proof please refer
// to the Theory Section:), anyway basically this is
// the core of the Orbit-Stabilizer Theorem.
//
// Now lets consider this set:
// {(g,x) | g ∈ G, x ∈ X and g⋅x = x}, we can
// calculate the size of this set in two different
// ways:
// 1) fix g and take the size of the set:
//    X(g) := {x ∈ X | g⋅x = x}, then sum over all g
//    Sum{g∈G}(|X(g)|), just for curiosity what is
//    the set X(π); the square (R,B,R,B) after
//    rotation around O axis at π will transform into
//    (R,B,R,B), so X(π) = { RBRB, RGRG, BRBR, BGBG,
//    GRGR, GBGB } and |X(π)| = 6
// 2) fix x and take the size of the set:
//    G(x) := {g ∈ G | g⋅x = x } and sum over all x,
//    but as we can see G(x) is exactly the
//    stabilizer Stab(x) and as we know:
//    |Stab(x)| = |G|/|Orb(x)| so summing will give:
//    |G|n where n is the number of orbits, zo we 
//    have arrived at the Burnside's Lemma:
//
//    n = Sum{g∈G}(|X(g)|)/|G|,
// 
// so the number of different colored squares is the
// number of different orbits n. By the way the
// Burnside's Lemma is famous that it is not the
// Burnside's Lemma at the same time, cos it was
// discovered by Cauchy and latter generalized by
// Frobenius, before 200 years or smth, just wondering
// will the competitive programmers after 200 years
// solve problems using the current modern math?
//////////////////////////////////////////////////////
constexpr i64 MOD = 1e9 + 7;
//////////////////////////////////////////////////////
i64 modexp( i64 x, i64 y ){
  if( !y ) return 1;
  auto z = modexp( x, y/2 );
  z = z * z % MOD;
  if( y & 1 ) z = z * x % MOD;
  return z;
}
//////////////////////////////////////////////////////
i64 invs( i64 x ){
  return modexp( x, MOD - 2 );
}
//////////////////////////////////////////////////////
i64 gcd( i64 n, i64 m ){
  if( !m ) return n;
  return gcd( m, n % m );
}
//////////////////////////////////////////////////////
void pusk() {
  auto n = loads<i32>(); dbg( n );
  auto m = loads<i32>(); dbg( m );
  i64 tot = 0;
  for( i32 k = 0; k < n; ++k ){
    tot += modexp( m, gcd( n, k ));
    tot %= MOD;
  }
  tot = tot * invs( n ) % MOD;
  cout << tot << nl;
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
////// Counting Necklaces                       //////
//////                                          //////
////// Your task is to count the number of      //////
////// different necklaces that consist of n    //////
////// pearls and each pearl has m possible     //////
////// colors. Two necklaces are considered to  //////
////// be different if it is not possible to    //////
////// rotate one of them so that they look the //////
////// same.                                    //////
//////                                          //////
////// [ Input ]                                //////
////// The only input line has two numbers n    //////
////// and m: the number of pearls and colors.  //////
//////                                          //////
////// [ Output ]                               //////
////// Print one integer: the number of         //////
////// different necklaces modulo 1e9+7.        //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 ≤ n,m ≤ 1e6                            //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 4 3                                      //////
//////                                          //////
////// Output:                                  //////
////// 24                                       //////
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
