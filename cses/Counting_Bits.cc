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
# define siz( a ) ((i32) a.size())
////////////////////////////////////////////////////////////////
template <size_t S>
string hex( u64 n ){ // it's binary
  return bitset<S>( n ).to_string();
}
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
//                                  [ The Sky Allows ]
//
//                               War ships float above
//                Their sails full of still blue light
//                               The earth doesn't ask
//
//                                          デープシーク
//
// 2.2.21. On an initially stationary cart, two
// vertical cylindrical vessels are installed,
// connected by a thin tube. The cross-sectional area
// of each vessel is S, and the distance between their
// axes is l. One of the vessels is filled with a
// liquid of density ρ. The valve on the connecting
// tube is opened. Find the velocity of the cart at
// the moment when the velocity of the liquid levels
// is υ. The total mass of the entire system is m.
//
// This problem looks quite complex at first and it's
// strange that it has a simple solution based on cm.
// First the cm is entirely on the vessel filled with
// the liquid, then after the valve is open it kinda
// moves towards the other vessel, but becoz the
// system is closed it must not change, that's why the
// whole system start moving. So ok lets put the ORIG
// at the initially full vessel then after a time Δt
// the other vessel will have liquid of mass:
// Δm = ρΔV = ρSυΔt, so the cm will shift with:
// Δx = ρSυΔtl/m, zo the speed of cm is: u = ρSυl/m
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// ok if we have a number n like 7 or 15 where all
// bets are off, then we can use the formula:
// N = Sum kC(n,k) = n2^(n-1), becoz we can choose k
// bits in C(n,k) ways, the sum is from k = 1 up to n,
// and can be calculated using the formula:
// kC(n,k) = nC(n-1,k-1)
//
// Say n is 101101 we can split the sum from 1 to
// 011111 and from 100000 to 101101, so in the first
// term we use the formula in the second term we knock
// out the msb and then we have the saaaame problem
// with smaller size 1101
//////////////////////////////////////////////////////
i32 msb( i64 n ){
  return 63 - __builtin_clzll( n );
}
//////////////////////////////////////////////////////
i64 all_bets_are_off( i64 n ){
  if( n < 2 ) return n;
  auto m = msb( n );
  i64 N1 = m*(1LL << (m-1));
  n -= 1LL << m;
  i64 N2 = n + 1; // knock knock
  i64 N3 = all_bets_are_off( n );
  return N1 + N2 + N3;
}
//////////////////////////////////////////////////////
void pusk() {
  auto n = loads<i64>(); dbg( n );
  cout << all_bets_are_off( n ) << nl;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//                                   [ Self Portrait ]
//
//                              She holds her own face
//                               In a box within a box
//                                  Waiting to be seen
//
//                                          チャットGPT
//
// 60-3-6 A sphere is inscribed in a cone. Then a
// second sphere is inscribed, which touches the first
// sphere and the lateral surface of the cone. Then a
// third sphere is inscribed, which touches the second
// sphere and the lateral surface of the cone, and so
// on. Find the sum of the surface areas of all
// spheres if the height of the cone is h and the
// angle at the vertex of its axial cross-section is α.
//
// Ok let's look at an angle α = 2β in 2D and inscribe
// a circle with radius R and center O that touches
// the two rays say in points A and B, next we draw
// second circle (r,O') that touches the rays in C and
// D. Lets look at the trapezoid OO'CA or OO'DB we can
// drop a perpendicular from O' to OA and write:
// sinβ = (R - r)/(R + r), zo
// r = R(1 - sinβ)/(1 + sinβ) we can continue this
// process and in general we have:
// rₙ = rₙ₋₁ϰ, n > 1 and ϰ = (1 - sinβ)/(1 + sinβ),
// we can express rₙ as: rₙ = ϰⁿr₀
// Now if we return back to the problem and wanna
// calculate the sum of spheres we have:
// S = Sum 4πrₙ² = 4πR² Sum qⁿ = 4πR²/(1 - q), where
// R := r₀ and q := ϰ², if we replace R with h we get
// S = πh²sin(α/2)
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
//
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////                                          //////  
////// Counting Bits                            //////
//////                                          //////
////// Your task is to count the number of one  //////
////// bits in the binary representations of    //////
////// integers between 1 and n.                //////
//////                                          //////
////// [ Input ]                                //////
////// The only input line has an integer n.    //////
//////                                          //////
////// [ Output ]                               //////
////// Print the number of one bits in the      //////
////// binary representations of integers       //////
////// between 1 and n.                         //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 <= n <= 1e15                           //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 7                                        //////
//////                                          //////
////// Output:                                  //////
////// 12                                       //////
//////                                          //////
////// Explanation: The binary representations  //////
////// of 1 ... 7 are 1, 10, 11, 100, 101,      //////
////// 110, and 111, so there are a total of 12 //////
////// one bits.                                //////
//////                                          //////
//////////////////////////////////////////////////////
///////////////////////////////////////////########///
///////////////////////////////////////////########///
///////////////////////////////////////////########///
// log:                                    ########
// + input                                 ### ####
// + 2.2.21.                              ###  ### 
// + algorithm                           ##   ##   
// + 60-3-6                              #     #
// + Haiku いち
// + Haiku に
