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
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// 2.2.1. A particle of mass m moves with velocity υ,
// and a particle of mass 2m moves with velocity 2υ in
// a direction perpendicular to the direction of the
// first particle. Identical forces begin to act on
// each particle. After the forces cease to act, the
// first particle moves with velocity 2υ in the
// direction opposite to its original direction. 
// Determine the velocity of the second particle.
//
//  m ---> υ  F  2υ <------- m   Zo from F = ma we 
//  2m        O  2m ?            have FΔt = Δp as
//   |        R                  vectors zo, 
//   |        C                  FΔt = 3mυ directed on
//   |        E                  left, zo for the
//   |        S                  second particle we 
//   v 2υ                        have the vector sum
//                               of these:
//   3mυ       
//   <-------+  ,that is 2mu = 5mυ, u = 5υ/2
//           |
//           |
//           |
//           |
//       4mυ v
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////
//              1
//    01234567890123456
// s: ABCDABCDABCDABCD
//        1
// z: -000200080004000
//
//    01234567
// s: ABCABCA
//
// z: -004001
//////////////////////////////////////////////////////
constexpr int N = 1e6;
//////////////////////////////////////////////////////
char s[N+1];
int n;
//////////////////////////////////////////////////////
int z[N];
//////////////////////////////////////////////////////
void period() {
  int y = 0;
  for( int k = 1; k < n; ++k ){
    if( k < y + z[y] ){
      z[k] = min( y + z[y] - k, z[k - y] );
    }
    for(; s[z[k]] == s[k + z[k]]; ++z[k] )
      ;
    if( k + z[k] > y + z[y] ){ y = k; }
    // check for period
    if( k + z[k] == n ){ cout << k << sp; }
  }
  cout << n << nl;
}
//////////////////////////////////////////////////////
//
// [ pun intended! ]
// 
// Z-algorithm spins
// Suffixes meet prefixes
// Periods revealed
//                                         -- DeepSeek
//////////////////////////////////////////////////////
void pusk() {
  cin >> s;
  n = strlen( s );
  dbg2( n, s );
  period();
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// 3. Show that, in the process of transferring a
// tower under the restrictions of the preceding
// exercise, we will actually encounter every properly
// stacked arrangement of n disks on three pegs.
//
// I'm not very good at math proofs, but this seems
// like an induction, so lets look at few examples
// for n = 1 and 2:
//            
//            A       C       B
// n = 1: | =     |   =   |     = |
//
// n = 2: |  =          |             |             |
//        | ===         | ===  =      | ===      =  |
//
//        |             |      =      |             |
//        |     ===  =  |     ===     |  =  ===     |
//
//        |             |             |          =  |
//        |  =      === |      =  === |         === |
//
// Let's assume we have all proper arrangements when
// transferring tower of size n from A to B and vice
// versa. For n + 1 we have three positions for the
// base disk; when it is on A we transfer the above n
// disks to B with all arrangements on the n disks by
// induction, then we move the base disk to C and then
// again the n disks from B to A, finally we move the
// base disk from C to B and the n disks from A to B
// going through all possible arrangements, blah blah
// blah ...
//
// [ Hanoi Complete ]
//
// Gray code's gentle dance
// Through the pegs the disks all turn
// No state left untouched
//                                         -- DeepSeek
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
////// Finding Periods                          //////
//////                                          //////
////// A period of a string is a prefix that    //////
////// can be used to generate the whole string //////
////// by repeating the prefix. The last        //////
////// repetition may be partial. For example,  //////
////// the periods of abcabca are abc, abcabc   //////
////// and abcabca. Your task is to find all    //////
////// period lengths of a string.              //////
//////                                          //////
////// [Input]                                  //////
////// The only input line has a string of      //////
////// length n consisting of characters a–z.   //////
//////                                          //////
////// [Output]                                 //////
////// Print all period lengths in increasing   //////
////// order.                                   //////
//////                                          //////
////// [Constraints]                            //////
////// 1 <= n <= 1e6                            //////
//////                                          //////
////// [Example]                                //////
////// Input:                                   //////
////// abcabca                                  //////
//////                                          //////
////// Output:                                  //////
////// 3 6 7                                    //////
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
