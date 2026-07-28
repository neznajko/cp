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
//
//                             [ Center of Stillness ]
//
//                                Black on ochre light,
//                    Ink lines flow smoothly and wide.
//                            The brush knows the rest.
//
//                                            DeepSeek
//
// <> 2.2.18. Two charged particles of masses m and
// 2m, having momenta of equal magnitude, fly toward
// each other from points A and B. The particles
// interact only with each other. Using the trajectory
// of the particle of mass 2m shown in the figure,
// reconstruct the trajectory of the other particle.
//       _    _          _      _   
// becoz p₁ + p₂ = 0 = m₁υ₁ + m₂υ₂, the cm will stay
// in place
// _      _      _
// x = (m₁x₁ + m₂x₂)/(m₁ + m₂) = const
//
// +=======+===========+  we also have for the lengths
// x₁      x           x₂
//
// l₁ := |x - x₁|,                       l₂/l₁ = m₁/m₂
// l₂ := |x - x₂|, so this gives us a hint how to
// build the missing part: so we find the cm point by
// connecting A and B and splitting in ratio 1:2 then
// for each point from the known trajectory we connect
// it with the cm then the length to the corresponding
// point will be twice as large
//
// ###############################|###################
// ###############################|###################
// ### d r a w   t h i s #########|###################
// ###############################|###################
// ###############################|###################
// A #############################|###################
// -------------------------------+-------------------
// ###############################|##########        B 
// ###############################|####      #########
// ###############################|#    ##############
// ###############################|##  ###############
// ###############################|###  ##############
// ###############################|#####  ############
///////////////////////////////////////// /  /////////
//////////////////////////////////////// /  //////////
/////////////////////////////////////// /  ///////////
////////////////////////////////////// /  ////////////
template <typename T>
vector<T> vec( T* p, i32 n ){
  return vector<T>( p, p + n );
}
# ifdef DeBug
#  define dmp( p, n ) cerr << #p<<"="<<vec(p,n) << nl;
# else
#  define dmp( p, n )
# endif
///////////////////////////////////// /  /////////////
//////////////////////////////////// /  //////////////
/////////////////////////////////// /  ///////////////
////////////////////////////////// /  ////////////////
using P = pair<i64,i64>;
# define x(a) ((a).first)
# define y(b) ((b).second)
//////////////////////////////////////////////////////
P operator-( const P& a, const P& b ){
  return { x(a) - x(b), y(a) - y(b) };
}
//////////////////////////////////////////////////////
i64 cross( P a, P b ){
  return x(a)*y(b) - x(b)*y(a);
}
enum { LEFT=1, MID_RAPIDITY=0, RYTE=-1 };
//////////////////////////////////////////////////////
//                                    LEFT
//                               s1---------------->s2
//                                             RYTE        
// there is a line going from s1 to s2 and a point p,
// p is either left ryte or mid-rapidity, zo let's put
// orig at s1 and use cross
i32 point_location( P s1, P s2, P p ){
  auto c = cross( s2 - s1, p - s1 );
  if( c > 0 ) return LEFT;
  if( c < 0 ) return RYTE;
  return MID_RAPIDITY;
}
//////////////////////////////////////////////////////
bool intersection( P a, P b, P c, P d ){
  if( a > b ) swap( a, b ); dbg2( a, b );
  if( c > d ) swap( c, d ); dbg2( c, d );
  auto lc = point_location( a, b, c );
  auto ld = point_location( a, b, d );
  if( !lc and !ld ){
    vector<pair<P,i32>> loc = {
      { a, 0 },
      { b, 1 },
      { c, 2 },
      { d, 3 }
    };
    sort( on( loc ));
    dbg( loc );
    // 0 1 2 3 - NOPE unless 1 == 2
    // 2 3 0 1 - NOPE    and 3 == 0
    if( loc[1].second == 1 or loc[1].second == 3 ){
      if( loc[1].first != loc[2].first ) return false;
    }
    return true;
  }
  auto la = point_location( c, d, a );
  auto lb = point_location( c, d, b );
  //
  if( !la ){
    if( c <= a and a <= d ) return true;
    else return false;
  }
  if( !lb ){
    if( c <= b and b <= d ) return true;
    else return false;
  }
  if( !lc ){
    if( a <= c and c <= b ) return true;
    else return false;
  }
  if( !ld ){
    if( a <= d and d <= b ) return true;
    else return false;
  }
  //
  if( la != lb and lc != ld ) return true;
  return false;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
void pusk() {
  auto t = loads<i32>();
  while( t-- ){
    auto a = loadp<i64>(); dbg( a );
    auto b = loadp<i64>(); dbg( b );
    auto c = loadp<i64>(); dbg( c );
    auto d = loadp<i64>(); dbg( d );
    if( intersection( a, b, c, d )){
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//
//                          [ INTERSTELLAR ADVENTURE ]
//
//                                He walks on his star,
//                          The rose watches from afar,
//                                 Tickets now on sale.
//
//                                              Gemini
//
// 2.2.19. A space station is a cylinder of radius R
// and mass m₂. An astronaut of mass m₁ begins walking
// around the station along its surface in a circle.
// Determine the trajectory of the astronaut and the
// trajectory of the center of the station. Initially,
// the astronaut and the station are at rest.
//
// Here we use the saaame thing as in the previous
// problem:                m₂--------+--------------m₁
//                           <- l₂ -> <-    l₁    ->
// the ratio of the distances is opposite to masses:
// l₂/l₁ = m₁/m₂, plus l₁ + l₂ = R, zo they both will
// circle around the cm with radii:
// l₁ = m₂R/(m₁+m₂) and l₂ = m₁R/(m₁+m₂) respectively
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
////// Line Segment Intersection                //////
//////                                          //////
////// There are two line segments: the first   //////
////// goes through the points (x_1,y_1) and    //////
////// (x_2,y_2), and the second goes through   //////
////// the points (x_3,y_3) and (x_4,y_4).      //////
////// Your task is to determine if the line    //////
////// segments intersect, i.e., they have at   //////
////// least one common point.                  //////
//////                                          //////
////// [ Input ]                                //////
////// The first input line has an integer t:   //////
////// the number of tests. After this, there   //////
////// are t lines that describe the tests.     //////
////// Each line has eight integers x_1, y_1,   //////
////// x_2, y_2, x_3, y_3, x_4 and y_4.         //////
//////                                          //////
////// [ Output ]                               //////
////// For each test, print "YES" if the line   //////
////// segments intersect and "NO" otherwise.   //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 <= t <= 10^5                           //////
////// -10^9 <= x_i, y_i <= 10^9                //////
////// (x_1,y_1) != (x_2,y_2)                   //////
////// (x_3,y_3) != (x_4,y_4)                   //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 5                                        //////
////// 1 1 5 3 1 2 4 3                          //////
////// 1 1 5 3 1 1 4 3                          //////
////// 1 1 5 3 2 3 4 1                          //////
////// 1 1 5 3 2 4 4 1                          //////
////// 1 1 5 3 3 2 7 4                          //////
//////                                          //////
////// Output:                                  //////
////// NO                                       //////
////// YES                                      //////
////// YES                                      //////
////// YES                                      //////
////// YES                                      //////
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
