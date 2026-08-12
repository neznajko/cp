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
// <> 2.2.27. In a vessel filled with water of density
// ρ, an air bubble of volume V rises with
// acceleration a. Find the force exerted by the
// vessel on its support. The mass of the vessel
// together with the water is m.
//
// This is an interesting problem, and the solution is
// kinda unexpected, so we can represent the system as
// superposition of a vessel with mass m and a bubble
// with mass -ρV, let the bubble crosses the center of
// the vessel at t = 0, then after time Δt it will be
// at distance uΔt and if we put the ORIG at the
// center of the vessel the cm of the system will
// shift at:
// Δx = -ρVuΔt/(m - ρV), with velocity:
// v = Δx/Δt = -ρVu/(m - ρV), cos u is accelerating
// cm will accelerate as well with w = -ρVa/(m - ρV),
// that means that the system is not closed and there
// is an external force acting equal to the mass of
// the system times the acceleration: (m - ρV)w = -ρVa,
// so the reaction of the surface is mg - ρVa
//////////////////////////////////////////////////////
constexpr i64 MOD = 1e9 + 7;
//////////////////////////////////////////////////////
// G = { r⁰, r¹, r², r³ }, where r is rotation 90°,
// again we use the Burnside's Lemma:
// a) n is even
//   N := n*n,
//   Ø := number of orbits
//   4Ø = 2^N + 2^(N/4) + 2^(N/2) + 2^(N/4)
// b) n is odd, here we have to detach the center
//   4Ø = 2^N + 2*2^(1+(N-1)/4) + 2^(1+(N-1)/2)
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
// 4Ø = 2^N + 2*2^(N/4) + 2^(N/2)
i64 even_grid( i64 N ){
  i64 s = ( modexp( 2, N ) +
            2 * modexp( 2, N/4 ) +
            modexp( 2, N/2 )) % MOD;
  return s * invs( 4 ) % MOD;
}
//////////////////////////////////////////////////////
// 4Ø = 2^N + 2*2^(1+(N-1)/4) + 2^(1+(N-1)/2)
i64 odd_grid( i64 N ){
  i64 s = ( modexp( 2, N ) +
            2 * modexp( 2, 1 + (N-1)/4 ) +
            modexp( 2, 1 + (N-1)/2 )) % MOD;
  return s * invs( 4 ) % MOD ;
}
//////////////////////////////////////////////////////
void pusk() {
  auto n = loads<i64>(); dbg( n );
  auto N = n * n;
  if( n & 1 ){
    cout << odd_grid( N ) << nl;
  } else {
    cout << even_grid( N ) << nl;
  }
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// 4. Fred is answering a multiple-choice problem on
// an exam, and has to choose one of n options
// (exactly one of which is correct). Let K be the
// event that he knows the answer, and R be the event
// that he gets the problem right (either through
// knowledge or through luck). Suppose that if he
// knows the right answer he will definitely get the
// problem right, but if he does not know then he will
// guess completely randomly. Let P(K) = p.
//
// K - he knows the answer
// R - he gets the problem right
// C - he has no clue
//
// (a) Find P(K|R) (in terms of p and n).
//
// P(K|R) = P(R|K)P(K)/P(R)
// P(R) = P(R|K)P(K) + P(R|C)P(C)
// P(K) = p, P(C) = 1 - p, P(R|C) = 1/n, P(R|K) = 1
// P(R) = p + (1 - p)/n
// P(K|R) = p/(p + (1-p)/n) = np/(1 + (n-1)p)
//
// (b) Show that P(K|R) ≥ p, and explain why this
// makes sense intuitively. When (if ever) does P(K|R)
// equal p?
//
// Basically to my intuition this makes no sense
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
////// Counting Grids                           //////
//////                                          //////
////// Your task is to count the number of      //////
////// different nxn grids whose each square is //////
////// black or white. Two grids are considered //////
////// to be different if it is not possible to //////
////// rotate one of them so that they look the //////
////// same.                                    //////
//////                                          //////
////// [ Input ]                                //////
////// The only input line has an integer n:    //////
////// the size of the grid.                    //////
//////                                          //////
////// [ Output ]                               //////
////// Print one integer: the number of grids   //////
////// modulo 1e9+7.                            //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 ≤ n ≤ 1e9                              //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 4                                        //////
//////                                          //////
////// Output:                                  //////
////// 16456                                    //////
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
