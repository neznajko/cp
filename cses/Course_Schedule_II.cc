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
// 27. If p > 3 is prime, prove that p² + 2 is
// composite.
//
// This seems true for every p not divisible by 3, cos
// in that case p = 3q + r, r = 1,2
// p² = 9q² + 6qr + r²
// a) r = 1
//   p² + 2 = 9q² + 6q + 1 + 2 = 3(3q² + 2q + 1)
// b) r = 2
//   p² + 2 = 9q² + 12q + 4 + 2 = 3(3q² + 4q + 2)
// in both cases divisible by 3 
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
// 2.2.35. A rocket with a cross-sectional area S,
// moving through space at a velocity u, enters a
// cloud of stationary dust with density ρ. What
// thrust must the rocket's engines produce so that it
// can continue moving at the same constant velocity?
// Assume that collisions between dust particles and
// the rocket are perfectly inelastic. Neglect changes
// in the mass of the rocket.
//
// Δp = Δmu = ρΔVu = ρ(SuΔt)u = ρSu²Δt, zo Δp/Δt = ρSu²
// 
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
//     8      5      8 7 5 6 4 2 3 1
//  2     7     6
//   3   1 4      
//                
using vi32 = vector<i32>;

void pusk() {
  auto [n,m] = loadp<i32>();
  vector<vi32> adj( n + 1 );
  vi32 indeg( n + 1 );
  while( m-- ){
    auto [a,b] = loadp<i32>(); // a < b
    adj[b].push_back( a );
    ++indeg[a];
  }
  dbg( adj );
  dbg( indeg );
  priority_queue<i32> pq;
  vi32 revs;
  for( i32 u = 1; u <= n; ++u ){
    if( !indeg[u] ) pq.push( u );
  }
  while( !pq.empty() ){
    auto u = pq.top(); pq.pop();
    revs.push_back( u );
    for( auto v: adj[u] ){
      if( !--indeg[v] ) pq.push( v );
    }
  }
  for( i32 i = siz( revs ) - 1; i >= 0; --i ){
    cout << revs[i] << sp;
  }
}
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
////// Course Schedule II                       //////
//////                                          //////  
////// You want to complete n courses that have //////
////// requirements of the form "course a has   //////
////// to be completed before course b". You    //////
////// want to complete course 1 as soon as     //////
////// possible. If there are several ways to   //////
////// do this, you want then to complete       //////
////// course 2 as soon as possible, and so on. //////
////// Your task is to determine the order in   //////
////// which you complete the courses.          //////
//////                                          //////  
////// [ Input ]                                //////
////// The first input line has two integers n  //////
////// and m: the number of courses and         //////
////// requirements. The courses are numbered   //////
////// 1,2,...,n. Then, there are m lines       //////
////// describing the requirements. Each line   //////
////// has two integers a and b: course a has   //////
////// to be completed before course b. You     //////
////// can assume that there is at least one    //////
////// valid schedule.                          //////
//////                                          //////  
////// [ Output ]                               //////
////// Print one line having n integers: the    //////
////// order in which you complete the courses. //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 ≤ n ≤ 1e5                              //////
////// 1 ≤ m ≤ 2e5                              //////
////// 1 ≤ a,b ≤ n                              //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 4 2                                      //////
////// 2 1                                      //////
////// 2 3                                      //////
//////                                          //////
////// Output:                                  //////
////// 2 1 3 4                                  //////
//////                                          //////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
///////////////////////////////////////////########///
///////////////////////////////////////////########///
// log:                                    ########
//                                         ### ####
//                                        ###  ### 
//                                       ##   ##   
//                                        #     #
