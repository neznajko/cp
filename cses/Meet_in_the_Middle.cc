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
# define key( p ) p.first
# define val( p ) p.second
////////////////////////////////////////////////////////////////
template <typename K, typename V>
ostream& operator<<( ostream& os, const pair<K,V>& p ){
    return os << "{"
              << key( p )
              << ","
              << val( p )
              << "}";
}
////////////////////////////////////////////////////////////////
OVERLOAD_OSTREAM_OPERATOR( vector );
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
// nput: t vector of integers
//       [l,r) the range of t
// outp: s sum of all subsets
vector<i64> subsum( const vector<i64>& t, i32 l, i32 r ){
  vector<i64> s{ 0 };
  for( i32 i = l; i < r; ++i ){
    const i32 len = s.size();
    for( i32 j = 0; j < len; ++j ){
      s.push_back( t[i] + s[j] );
    }
  }
  sort( on( s ));
  return s;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//
//                                    [ The Clearing ]
//
//                               After the great storm,
//                   the quiet night sky shines bright,
//                              with a thousand lights.
//
//                                             ChatGPT
//
// 2.2.12: A shell explodes at the highest point of
// its trajectory, at a horizontal distance L from the
// cannon, into two identical fragments. One of them
// returned to the cannon along the original
// trajectory of the shell. Where did the second
// fragment land?
//
// We can look at the horizontal direction only, so
// the momentum at the highest point is mυ, then the
// shell splits into the -mυ/2 fragment that returns
// back to the cannon and the mu/2 part. We have to
// find u:
// mυ = -mυ/2 + mu/2, u = 3υ, so the second fragment
// will land at a distance 4L from the cannon.
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
void pusk() {
  i32 n = loads<i32>(); dbg( n );
  i64 x = loads<i64>(); dbg( x );
  auto t = loadv<i64>( n ); dbg( t );
  auto L = subsum( t, 0, n/2 );
  auto R = subsum( t, n/2, n );
  dbg( L );
  dbg( R );
  i64 tot = 0;
  for( auto l: L ){
    auto y = x - l;
    auto range = equal_range( on( R ), y );
    tot += range.second - range.first;
  }
  cout << tot << nl;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//
//                             [ Cannonball Airlines ]
// 
//                                 The old baron flies
//                     with the wind in his wild beard
//                              as the camp grows near.
//
//                                            DeepSeek
//
// 2.2.13. An artilleryman fires a cannonball of mass
// m from a cannon so that it falls in the enemy camp.
// Baron Münchhausen, whose mass is 5m, sits on the
// cannonball as it leaves the cannon. What fraction
// of the way to the enemy camp will he have to walk?
//
// So let υ is the speed of the cannonball necessary
// to reach the camp at a distance L, after the Baron
// rides the cannonball we have mυ = (m + 5m)u, that
// is he flies with speed u = υ/6. The horizontal
// distance is proportional to the square of the
// initial velocity: L ~ υ²; so he will fly 1/36 and
// walk 35/36 fraction of the path:)
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
//                                    [ Null Horizon ]
//
//                                   Vanishing in mist,
//                    lone boats sail to shores unseen,
//                                  far beyond the sea.
//
//                                              Gemini
//
// 6 Some of the regions defined by n lines in the
// plane are infinite, while others are bounded.
// What's the maximum possible number of bounded
// regions?
//
// This is the pizza cut problem: In how many slices
// we can split a pizza with n straight cuts? In the
// book they make the pizza infinite and solve the
// equation recursively: Lₙ = Lₙ₋₁ + n, the key moment
// here is that one slice can intersect at most n - 1
// previous lines, so along its path it will split n
// slices and as a result will add n more pieces. To
// solve this problem we can return back to the finite
// shape of the pizza. Here we distinguish two types
// of slices ones that touches the crust at the outer
// rim of the pizza( cornicione ) and the completely
// internal ones. n lines will have 2n intersections
// with the rim, that means there will be 2n infinite
// slices so the total bounded slices are:
// Lₙ - 2n = Lₙ₋₁ - n.
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////                                          ////// 
////// Meet in the Middle                       //////
//////                                          //////
////// You are given an array of n numbers. In  //////
////// how many ways can you choose a subset of //////
////// the numbers with sum x?                  //////
//////                                          //////
////// [ Input ]                                //////
////// The first input line has two numbers n   //////
////// and x: the array size and the required   //////
////// sum. The second line has n integers      //////
////// t_1,t_2,...,t_n: the numbers in the      //////
////// array.                                   //////
//////                                          //////
////// [ Output ]                               //////
////// Print the number of ways you can create  //////
////// the sum x.                               //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 <= n <= 40                             //////
////// 1 <= x <= 1e9                            //////
////// 1 <= t_i <= 1e9                          //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 4 5                                      //////
////// 1 2 3 2                                  //////
//////                                          //////
////// Output:                                  //////
////// 3                                        //////
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
