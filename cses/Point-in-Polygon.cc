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
template <typename K, typename V>
istream& operator>>( istream& s, pair<K,V>& p ){
  return s >> p.first >> p.second;
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
ostream& operator<<( ostream& os, const pair<K,V>& p ){
    return os << "{"
              << p.first
              << ","
              << p.second
              << "}";
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
vector<pair<i64,i64>> poly;
// Here I'm following the book, zo if we activate the
// lasers from point P it will cross even number of
// poligon line segments if outside and odd if inside.
//
// For simplicity we take the ORIG at p and the ray to
// be the positive axis, then using the formula for a
// line passing through two points and the value it
// has for y = 0 we can figure whether the ray crosses
// the poligon segment. The following function returns
// -1, 0 or 1 if the segment (x1,y1) (x2,y2) is not
// crossing the positive axis, pass through the orig
// or is crossing the positive axis respectively
//
// y = f(x) = ax + b
// y2 = ax2 + b
// y1 = ax1 + b,
// y2 - y1 = a(x2 - x1); a = (y2 - y1)/(x2 - x1)
// b = y2 - ax2 = y2 - (y2 - y1)x2/(x2 - x1) =
//   = (y2x2 - y2x1 - y2x2 + y1x2)/(x2 - x1) =
//   = (y1x2 - y2x1)/(x2 - x1)
// y = 0 = ax + b, x = -b/a
// x = (x1y2 - x2y1)/(y2 - y1)
//////////////////////////////////////////////////////
i32 cross( i64 x1, i64 y1, i64 x2, i64 y2 ){
  // that's quite bugy part here, the idea is to avoid
  // counting vertices twice if they lie on the x >= 0
  // axis, but there is a scenario like two segments 
  // ----0--------> having common vertex at (0,0) with
  //    / \         other points having negative y,
  //   /   \        that I've missed and had to dig it
  //  A     B       in a 100 points polygon:)
  if( y1 <= 0 and y2 <= 0 ){
    if( !x1 and !y1 or !x2 and !y2 ) return 0; // thats 
    if( !y1 and !y2 ){
      if( x1 > x2 ) swap( x1, x2 );
      if( x1 <= 0 and x2 >= 0 ) return 0;
    }
    return -1;
  }
  if( y1 > 0 and y2 > 0 ) return -1;
  if( x1 == x2 ){
    if( x1 < 0 ) return -1;
    if( x1 == 0 ) return 0;
    return 1;
  }
  i64 c = x1*y2 - x2*y1;
  i64 d = y2 - y1;
  // x = c/d should be positive for cross
  if( c == 0 ) return 0;
  if( c < 0 and d < 0 ) return 1;
  if( c > 0 and d > 0 ) return 1;
  return -1;
}
void check_point( const pair<i64,i64>& p ){
  i32 cnt = 0;
  const i32 n = poly.size() - 1;
  for( i32 i = 0; i < n; ++i ){
    auto [x1,y1] = poly[i];
    auto [x2,y2] = poly[i+1];
    i32 ck = cross( x1 - p.first, y1 - p.second,
                    x2 - p.first, y2 - p.second );
    if( ck == 0 ){
      cout << "BOUNDARY" << nl;
      return ;
    }
    if( ck == 1 ) ++cnt;
  }
  if( cnt & 1 ){
    cout << "INSIDE" << nl;
  } else {
    cout << "OUTSIDE" << nl;
  }    
}
void pusk() {
  auto [n,m] = loadp<i32>(); dbg2( n, m );
  poly = loadv<pair<i64,i64>>( n );
  poly.push_back( poly.front()); dbg( poly );
  while( m-- ){
    auto p = loadp<i64>();
    check_point( p );
  }
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
//////  Point in Polygon                        //////
//////                                          //////
////// You are given a polygon of n vertices    //////
////// and a list of m points. Your task is to  //////
////// determine for each point if it is        //////
////// inside, outside or on the boundary of    //////
////// the polygon. The polygon consists of n   //////
////// vertices (x1,y1),(x2,y2),...,(xn,yn).    //////
////// The vertices (xi,yi) and (x{i+1},y{i+1}) //////
////// are adjacent for i=1,2,...,n-1, and the  //////
////// vertices (x1,y1) and (xn,yn) are also    //////
////// adjacent.                                //////
//////                                          //////
////// [Input]                                  //////
////// The first input line has two integers n  //////
////// and m: the number of vertices in the     //////
////// polygon and the number of points. After  //////
////// this, there are n lines that describe    //////
////// the polygon. The ith such line has two   //////
////// integers xi and yi. You may assume that  //////
////// the polygon is simple, i.e., it does not //////
////// intersect itself. Finally, there are m   //////
////// lines that describe the points. Each     //////
////// line has two integers x and y.           //////
//////                                          //////
////// [Output]                                 //////
////// For each point, print "INSIDE",          //////
////// "OUTSIDE" or "BOUNDARY".                 //////
//////                                          //////
////// [Constraints]                            //////
////// 3 ≤ n ≤ 1000                             //////
////// 1 ≤ m ≤ 1000                             //////
////// -1e9 ≤ xi, yi ≤ 1e9                      //////
////// -1e9 ≤ x, y ≤ 1e9                        //////
//////                                          //////
////// [Example]                                //////
////// Input:                                   //////
////// 4 3                                      //////
////// 1 1                                      //////
////// 4 2                                      //////
////// 3 5                                      //////
////// 1 4                                      //////
////// 2 3                                      //////
////// 3 1                                      //////
////// 1 3                                      //////
//////                                          //////
////// Output:                                  //////
////// INSIDE                                   //////
////// OUTSIDE                                  //////
////// BOUNDARY                                 //////
//////                                          //////
// 19. Explain the following Sherlock Holmes saying in
// terms of conditional probability, c a r e f u l l y
// dstinguishing between prior a n d p o s t e r i o r
// probabilities: "It is an old m a x i m of mine that
// when y o u have excluded t h e impossible, whatever
// remains, however improbable, must be the truth."
//
// I'm not very sure but lets A, B, C, and D are the
// suspects and initially the probability P(A) of A
// being guilty is very small, if later there are some
// additional evidences E the posterior probability
// P(A|E) might become very large regardless how small
// a priory it was
//
//////////////////////////////////////////////////////
// 20. The Jack of Spades (with cider), Jack of Hearts
// (w i t h tarts), Queen of Spades (with a wink), and
// Queen of Hearts (without tarts) are taken f r o m a
// deck of cards. These four cards are shuffled, a n d
// then two are dealt. N o t e: Literary references to
// c i d e r, tarts, and w i n k s do n o t need to be
// considered when solving this problem.
//
// Js, Jh, Qs, Qh ( tarts and cider wtf )
//
// (a) Find the probability that both of these two
// cards are queens, given that the first card dealt
// is a queen.
//
// { QsJs QsJh QsQh,
//   QhJs QhJh QhQs }, P = 2/6 = 1/3
// 
//
// (b) Find the probability that both are queens,
// given that at least one is a queen.
//
// { JsQs JsQh
//   JhQs JhQh
//   QsJs QsJh QsQh
//   QhJs QhJh QhQs } P = 2/10 = 1/5
//
// (c) Find the probability that both are queens,
// given that one is the Queen of Hearts.
// { JsQh
//   JhQh
//   QsQh
//   QhJs QhJh QhQs } P = 2/6 = 1/3
//
//////////////////////////////////////////////////////
// 21. A fair coin i s f l i p p e d 3 times. The toss
// results are recorded on separate s l i p s of paper
// (writing "H" i f Heads and "T" if Tails), and the 3
// slips of paper are thrown into a hat.
//
// (a) Find the probability that all 3 tosses landed
// Heads, given that at least 2 were Heads.
//
// { THH,
//   HTH,
//   HHT,
//   HHH } P = 1/4
//
// (b) Two of the slips of paper are randomly drawn
// from the hat, and both show the letter H. Given
// this information, what is the probability that all
// 3 tosses landed Heads?
//
// Ok lets E is the event that two slips randomly
// chosen from the hat are H, we wanna
// P(HHH|E) = P(HHH ∩ E)/P(E) = P(HHH)/P(E) = 1/8P(E)
// all possible outcomes are:
//
// TTT HTT P(E) = P(E|TTT)P(TTT) + ..., for outcomes
// TTH HTH with one or zero heads P(E|.) is zero zo
// THT HHT P(E) = P(E|THH)P(THH) + P(E|HTH)P(HTH) +
// THH HHH        P(E|HHT)P(HHT) + P(E|HHH)P(HHH) =
//
// Lets take THH and mark each H like TH₁H₂ if we pick
// two slips at random the all outcomes are:
// TH₁ TH₂ H₁T H₁H₂ H₂T H₂H₁ so the prob of picking
// 2 heads is 2/6 = 1/3, zo
// P(E|THH) = P(E|HTH) = P(E|HHT) = 1/3, and of course
// P(E|HHH) = 1, zo P(E) = 2/8 = 1/4, thats
// P(HHH|E) = 1/2
//
//////////////////////////////////////////////////////
// 22. A bag contains one marble which is either green
// or blue w i t h equal probabilities. A green marble
// is put in the bag (so there are 2 marbles now), and
// then a random marble is taken out. The marble taken
// out is g r e e n. What i s the probability that the
// remaining marble is also green?
//
// R - the remaining marble is green
// B - fyorst marble is blue
// G - fyorst marble is green
// T - the marble taken out is green
//
// P(R|T) = P(R|TB)P(B|T) + P(R|TG)P(G|T) =
//
// P(R|TB) if the fyorst is Blue and we draw Green
// then the remaining is blue zo P(R|TB) = 0
// similarly P(R|TG) = 1, zo P(R|T) = P(G|T)
//`P(G|T) = P(T|G)P(G)/P(T) = P(G)/P(T)
// P(G) = 1/2
// P(T) = P(T|G)P(G) + P(T|B)P(B) =
//      = (1/2)(1 + 1/2) = 3/4
// zo P(R|T) = P(G|T) = 1/2/3/4 = 2/3
//////////////////////////////////////////////////////
///////////////////////////////////////////########///
///////////////////////////////////////////########///
///////////////////////////////////////////########///
// log:                                    ########
//                                         ### ####
//                                        ###  ### 
//                                       ##   ##   
//                                       #     #
