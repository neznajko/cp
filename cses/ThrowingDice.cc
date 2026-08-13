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
// 6. A hat contains 100 coins, where 99 are fair but
// one is double-headed (always landing Heads). A coin
// is chosen uniformly at random. The chosen coin is
// flipped 7 times, and it lands Heads all 7 times.
// Given this information, what is the probability
// that the chosen coin is double-headed? (Of course,
// another approach here would be to look at both
// sides of the coin—but this is a metaphorical coin.)
//
// H - 7 consecutive heads
// F - fair coin
// D - double headed
//
// P(D|H) = P(H|D)P(D)/P(H)
//
// P(H) = P(H|F)P(F) + P(H|D)P(D)
//
// P(F) = 99/100
// P(D) = 1/100
// P(H|F) = (1/2)⁷
// P(H|D) = 1
//
// P(H|D)P(D) = 1/100
// P(H) = (1/2)⁷99/100 + 1/100,
// P(D|H) = 1/(1 + 99/2⁷) = 128/(99 + 128) = 0.5639
//
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// f[-5] = ... = f[-1] = 0
// f[0] = 1
//
// f[-4] = [0 1 0 0 0 0] f[-5] 
// f[-3]   [0 0 1 0 0 0] f[-4] 
// f[-2]   [0 0 0 1 0 0] f[-3] 
// f[-1]   [0 0 0 0 1 0] f[-2] 
// f[ 0]   [0 0 0 0 0 1] f[-1] 
// f[ 1]   [1 1 1 1 1 1] f[ 0] 
//////////////////////////////////////////////////////
template <typename T,size_t N>
using mat_t = array<array<T,N>,N>;
//////////////////////////////////////////////////////
constexpr i64 MOD = 1e9 + 7;
constexpr size_t SIX = 6;
constexpr size_t FIVE = SIX - 1;
using mat6 = mat_t<i64,SIX>;
mat6 I = {{
  {1,0,0,0,0,0},
  {0,1,0,0,0,0},
  {0,0,1,0,0,0},
  {0,0,0,1,0,0},
  {0,0,0,0,1,0},
  {0,0,0,0,0,1}    
}};
//////////////////////////////////////////////////////
template<typename T, size_t N>
ostream& operator<<( ostream& s, const mat_t<T,N>& mat ){
  for( i32 i = 0; i < N; ++i ){
    for( i32 j = 0; j < N; ++j ){
      s << mat[i][j] << sp;
    }
    s << nl;
  }
  return s;
}
//////////////////////////////////////////////////////
template<typename T, size_t N>
mat_t<T,N> operator*( const mat_t<T,N>& a,
                      const mat_t<T,N>& b ){ 
  mat_t<T,N> c = {};
  for( i32 i = 0; i < N; ++i ){
    for( i32 j = 0; j < N; ++j ){
      for( i32 k = 0; k < N; ++k ){
        c[i][j] += a[i][k] * b[k][j];
      }
      c[i][j] %= MOD;
    }
  }
  return c;       
}
//////////////////////////////////////////////////////
mat6 modexp( mat6 x, i64 n ){
  if( !n ) return I;
  auto z = modexp( x, n/2 );
  z = z * z;
  if( n & 1 ) z = z * x;
  return z;
}
//////////////////////////////////////////////////////
void pusk() {
  auto n = loads<i64>(); dbg( n );
  mat6 X = {{
    {0,1,0,0,0,0},
    {0,0,1,0,0,0},
    {0,0,0,1,0,0},
    {0,0,0,0,1,0},
    {0,0,0,0,0,1},
    {1,1,1,1,1,1}    
  }};
  auto Y = modexp( X, n );
  cout << Y[FIVE][FIVE] << nl;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// <> 2.2.28*. A cylindrical vessel with a cross
// section S, filled with a liquid of density ρ, is
// mounted on a cart. A long, thin horizontal tube
// extends from the vessel parallel to the floor, with
// a short section near its end bent vertically
// downward. The distance from the central axis of the
// vessel to the tube's outlet is L. The liquid level
// inside the vessel lowers with a constant
// acceleration a. What horizontal force F is required
// to hold the cart in place?
//
// Let's put the ORIG at the vessel's axis after time
// Δt the mass that will pop out from the tube is
// ρSuΔt that is cm will shift at Δx = ρSuΔt L/m zo
// Δx/Δt = v = ρSuL/m, and the acceleration of the cm
// is w = ρSaL/m zo the corresponding external force
// is mw = ρSaL
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
////// Throwing Dice                            //////
//////                                          //////
////// Your task is to calculate the number of  //////
////// ways to get a sum n by throwing dice.    //////
////// Each throw yields an integer between     //////
////// 1 ... 6. For example, if n=10, some      //////
////// possible ways are 3+3+4, 1+4+1+4 and     //////
////// 1+1+6+1+1.                               //////
//////                                          //////
////// [ Input ]                                //////
////// The only input line contains an integer  //////
////// n.                                       //////
//////                                          //////
////// [ Output ]                               //////
////// Print the number of ways modulo 1e9+7.   //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 ≤ n ≤ 1e18                             //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 8                                        //////
//////                                          //////
////// Output:                                  //////
////// 125                                      //////
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
