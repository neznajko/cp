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
// 012345
// ABCABD, s=5
//     ^
// ...ABCABc... c=D -> s=6( match )
//        ^     c=C -> s=3
//              otr -> s=0
// so the state s transaction depends entirely on the
// KMP failure function
constexpr i32 MOD = 1e9+7;
i32 n; // text length
i32 m; // pattern length
string P; // ze pattern
vector<i32> pi; // 3.14...
vector<vector<i32>> next_state;
vector<vector<i32>> dp;
void kmp() {
  m = siz( P ); dbg( m );
  pi.resize( m );
  for( i32 i = 1; i < m; ++i ){
    auto j = pi[i-1];
    while( j and P[i] != P[j] ){
      j = pi[j-1];
    }
    pi[i] = j + (P[i] == P[j]);
  }
  dbg( pi );
}
// input state s is ranging from 0 to m-1, inclusive
// say we have a prefix T[0..i-1] of lenght i, s will
// be the largest suffix size of that substring that
// matches the prefix of P, basically we wanna avoid
// the state s=m, c represent the next character T[i]
i32 get_next_state( i32 s, char c ){
  for(;;) {
    if( P[s] == c ) return s + 1;
    if( s == 0 ) break;
    s = pi[s-1];
  } 
  return 0;
}
void dbg_next_state() {
# ifdef DeBug
  for( i32 i = 0; i < m; ++i ){
    cout << i << sp << next_state[i] << nl;
  }
# endif
}
void preprocess() {
  kmp();
  next_state.resize( m, vector<int>( 26 ));
  for( i32 s = 0; s < m; ++s ){
    for( char c = 'A'; c <= 'Z'; ++c ){
      next_state[s][c-'A'] = get_next_state( s, c );
    }
  }
  dbg_next_state();
}
void dbg_dp() {
# ifdef DeBug
  for( i32 i = 0; i <= n; ++i ){
    cout << i << sp << dp[i] << nl;
  }
# endif
}
void process() {
  dp.resize( n + 1, vector<i32>( m ));
  dp[0][0] = 1;
  for( i32 i = 0; i < n; ++i ){
    for( i32 s = 0; s < m; ++s ){
      for( i32 c = 0; c < 26; ++c ){
        i32 s1 = next_state[s][c];
        if( s1 < m ){
          dp[i+1][s1] += dp[i][s];
          dp[i+1][s1] %= MOD;
        }
      }
    }
  }
  dbg_dp();
}
i64 modexp( i64 x, i64 y ){
  if( !y ) return 1;
  auto z = modexp( x, y/2 );
  z = z * z % MOD;
  if( y & 1 ) z = z * x % MOD;
  return z;
}
i32 calculate() {
  i32 total = modexp( 26, n );
  i32 avoid = 0;
  for( i32 s = 0; s < m; ++s ){
    avoid += dp[n][s];
    avoid %= MOD;
  }
  return (total - avoid + MOD) % MOD;
}
void pusk() {
  n = loads<i32>(); dbg( n );
  P = loads<string>(); dbg( P );
  preprocess();
  process();
  cout << calculate() << nl;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
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
////// Required Sub string                      //////
//////                                          //////
////// Your task is to calculate the number of  //////
////// strings of length n having a given       //////
////// pattern of length m as their sub string. //////
////// All strings consist of characters A–Z.   //////
//////                                          //////
////// [ Input ]                                //////
////// The first input line has an integer n:   //////
////// the length of the final string. The      //////
////// second line has a pattern of length m.   //////
//////                                          //////
////// [ Output ]                               //////
////// Print the number of strings modulo       //////
////// 1e9+7.                                   //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 ≤ n ≤ 1000                             //////
////// 1 ≤ m ≤ 100                              //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 6                                        //////
////// ABCDB                                    //////
//////                                          //////
////// Output:                                  //////
////// 52                                       //////
//////                                          //////
// <> 2.2.33*. Inside a sphere of radius R, a particle
// of mass m moves w i t h speed υ, undergoing elastic
// collisions with i t s walls. The particle' velocity
// makes an angle α with the radius drawn to the point
// of impact. W h a t i s the magnitude of the average
// force exerted by the walls of t h e sphere on t h e
// particle? W h a t is the average force acting o n a
// unit a r e a of the s p h e r e if there are N such
// particles per u n i t volume? The particles d o not
// collide with one another.
//
// ok the momentum transfer is 2pcosα = 2mυcosα,
// the distance between two hits is x = 2Rcosα, zo
// for time Δt the force exchange is Δp/Δt, the
// average is <f> = (Δp/Δt + 0*t)/(Δt + t), where t is
// the time of flight: t = x/υ, zo
// <f> = 2mυcosα/2Rcosα/υ = mυ²/R
// for the second question the number of all balls is
// N4πR³/3, zo the average force applied to whole
// surface is N4πR³/3*mυ²/R = N4πR²mυ²/3, and per unit
// surface we have to divide by 4πR² zo we get Nmυ²/3
//////////////////////////////////////////////////////
///////////////////////////////////////////########///
///////////////////////////////////////////########///
///////////////////////////////////////////########///
// log:                                    ########
//                                         ### ####
//                                        ###  ### 
//                                       ##   ##   
//                                       #     #
