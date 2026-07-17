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
template <typename K, typename V>
ostream& operator<<( ostream& os, const pair<K,V>& p );          
////////////////////////////////////////////////////////////////
OVERLOAD_OSTREAM_OPERATOR( set );
OVERLOAD_OSTREAM_OPERATOR( vector );
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////
template <typename K, typename V>
ostream& operator<<( ostream& os, const pair<K,V>& p ){
    return os << "{"
              << p.first
              << ","
              << p.second
              << "}";
}
//////////////////////////////////////////////////////
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
// Ok so the trick here is to put P1 at the origin and
// rotate P2 to align with the x-axis then remains
// only P3 if its y is positive then it's on the LEFT,
// if negative on the RIGHT and if zero TOUCH, zo the
// only thing is how to avoid floating points
// 
// so if we move coordinates origin to P1, the other
// vectors will become:
//
// υ := (x₂ - x₁, y₂ - y₁),
// ω := (x₃ - x₁, y₃ - y₁)
//
// when we rotate to coordinates such that υ aligns
// with x then the y coordinate of ω will be
// proportional to the sinus of the angle between
// υ and ω, that is to their cross product
//////////////////////////////////////////////////////
# define P pair<i64,i64>
# define X first
# define Y second
//////////////////////////////////////////////////////
i64 cross( P a, P b ){
  return a.X*b.Y - a.Y*b.X;
}
//////////////////////////////////////////////////////
void pusk() {
  auto t = loads<i32>();
  while( t-- ){
    auto p1 = loadp<i64>(); dbg( p1 );
    auto p2 = loadp<i64>(); dbg( p2 );
    auto p3 = loadp<i64>(); dbg( p3 );

    p2.X -= p1.X;
    p2.Y -= p1.Y;
    p3.X -= p1.X;
    p3.Y -= p1.Y;

    auto y = cross( p2, p3 );
    
    if( y > 0 ){
      cout << "LEFT\n";
    } else
    if( y < 0 ){
      cout << "RIGHT\n";
    } else {
      cout << "TOUCH\n";
    }
  }
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//                                  [ Primary Colors ]
//
//                               Town Square remembers
//                     the quiet paths we used to walk,
//                            like colors lost in gray.
//
//                                              Gemini
//
// 17. If p is prime and (a,b) = p, then (a²,b²) = ?   
// 
// if (a,b) = p, then a = px, b = py with (x,y) = 1,    (a,b) is gcd
// cos if d := (x,y) > 0, then pd > p divides both.     of a and b
// Zo (a²,b²) = (p²x²,p²y²) = p²(x²,y²) = p². Here we
// have to prove that (x²,y²) = 1 and that we can
// write thus: (cx,cy) = c(x,y)
// This might not look like a proper proof but if we
// write x and y with their prime factors, then
// (x,y) = 1 means they don't share common primes, and
// that holds the same if we square them. For the
// second part let k := (cx,cy) and d := (x,y), we
// have to prove that k\cd and cd\k.
//
// zo k = Acx + Bcy, and d\x, d\y zo cd\k
// similarly k\cx and k\cy so k\(cd = cCx + cDy)
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
////// Point Location Test                      //////
//////                                          //////
////// There is a line that goes through the    //////
////// points p_1=(x_1,y_1) and p_2=(x_2,y_2).  //////
////// There is also a point p_3=(x_3,y_3).     //////
////// Your task is to determine whether p_3 is //////
////// located on the left or right side of the //////
////// line or if it touches the line when we   //////
////// are looking from p_1 to p_2.             //////
//////                                          //////
////// [ Input ]                                //////
////// The first input line has an integer t:   //////
////// the number of tests.  After this, there  //////
////// are t lines that describe the            //////
////// tests. Each line has six integers: x_1,  //////
////// y_1, x_2, y_2, x_3 and y_3.              //////
//////                                          //////
////// [ Output ]                               //////
////// For each test, print "LEFT", "RIGHT" or  //////
////// "TOUCH".                                 //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 <= t <= 10^5                           //////
////// -1e9 <= x_k, y_k <= 1e9                  //////
////// x_1 != x_2 or y_1 != y_2                 //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 3                                        //////
////// 1 1 5 3 2 3                              //////
////// 1 1 5 3 4 1                              //////
////// 1 1 5 3 3 2                              //////
//////                                          //////
////// Output:                                  //////
////// LEFT                                     //////
////// RIGHT                                    //////
////// TOUCH                                    //////
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
//
// ⁰ ¹ ² ³ ⁴ ⁵ ⁶ ⁷ ⁸ ⁹
// ₀ ₁ ₂ ₃ ₄ ₅ ₆ ₇ ₈ ₉
// ⁺ ⁻ ⁼ ⁽ ⁾             
// ₊ ₋ ₌ ₍ ₎             
// ⁿʷʸᶻ                  
// ᶿ
// 
//////////////////////////////////////////////////////
