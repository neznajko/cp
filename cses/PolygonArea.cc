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
ostream& operator<<( ostream& os, const pair<K,V>& p );
////////////////////////////////////////////////////////////////
OVERLOAD_OSTREAM_OPERATOR( vector );
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
using P = pair<i64,i64>;
# define X first
# define Y second
i64 cross( P a, P b ){
  return a.X * b.Y - b.X * a.Y;
}
void pusk() {
  auto n = loads<i32>(); dbg( n );
  auto p = loadv<P>( n ); dbg( p );
  p.push_back( p.front() );
  i64 total = 0;
  for( i32 i = 0; i < n; ++i ){
    total += cross( p[i], p[i + 1] );
  }
  cout << abs( total ) << nl;
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
////// Polygon Area                             //////
//////                                          //////
////// Your task is to calculate the area of a  //////
////// given polygon. The polygon consists of n //////
////// vertices (x1,y1),(x2,y2),...,(xn,yn).    //////
////// The vertices (xi,yi) and (x{i+1},y{i+1}) //////
////// are adjacent for i=1,2,...,n-1, and the  //////
////// vertices (x1,y1) and (xn,yn) are also    //////
////// adjacent.                                //////
//////                                          //////
////// [Input]                                  //////
////// The first input line has an integer n:   //////
////// the number of vertices. After this,      //////
////// there are n lines that describe the      //////
////// vertices. The ith such line has two      //////
////// integers xi and yi. You may assume that  //////
////// the polygon is simple, i.e., it does not //////
////// intersect itself.                        //////
//////                                          //////
////// [Output]                                 //////
////// Print one integer: 2a where the area of  //////
////// the polygon is a (this ensures that the  //////
////// result is an integer).                   //////
//////                                          //////
////// [Constraints]                            //////
////// 3 ≤ n ≤ 1000                             //////
////// -1e9 ≤ xi, yi ≤ 1e9                      //////
//////                                          //////
////// [Example]                                //////
////// Input:                                   //////
////// 4                                        //////
////// 1 1                                      //////
////// 4 2                                      //////
////// 3 5                                      //////
////// 1 4                                      //////
//////                                          //////
////// Output:                                  //////
////// 16                                       //////
//////                                          //////
// 25. Let p be prime and 1 ≤ k < p. Prove that p
// divides the binomial coefficient C(p,k)
//
// Zo C(p,k) = p!/k!(p-k)! = (p-k+1)...(p-1)p/k!,
// k! divides (p-k+1)...(p-1)p, but cos p is prime
// (k!,p) = 1 and by Theorem 1.4 if not mistaken k!
// divides (p-k+1)...(p-1) zo C(p,k) = αp for some
// integer α
//
// 12. Alice is trying to communicate with Bob, by
// sending a message (encoded in binary) across a
// channel.
//
// (a) Suppose for this part that she sends only one
// bit (a 0 or 1), with equal probabilities. If she
// sends a 0, there is a 5% chance of an error
// occurring, resulting in Bob receiving a 1; if she
// sends a 1, there is a 10% chance of an error
// occurring, resulting in Bob receiving a 0. Given
// that Bob receives a 1, what is the probability that
// Alice actually sent a 1?
//
// Ai - Alice sends i
// Bi - Bob receives i
// P(B1|A0) = .05
// P(B0|A1) = .1
//
// P(A1|B1) = P(B1|A1)P(A1)/P(B1)
// P(B1|A1) = 1 - P(B0|A1) = 1 - .1 = .9
// P(A1) = P(A0) = .5
// P(B1) = P(B1|A0)P(A0) + P(B1|A1)P(A1) =
//       = .5( .05 + .9 ) = .5*.95
// P(A1|B1) = .9*.5/.5*.95 = .9/.95 ≈ .9474
// 
// (b) To reduce the chance of miscommunication, Alice
// and Bob decide to use a repetition code. Again
// Alice wants to convey a 0 or a 1, but this time she
// repeats it two more times, so that she sends 000 to
// convey 0 and 111 to convey 1. Bob will decode the
// message by going with what the majority of the bits
// were. Assume that the error probabilities are as in
// (a), with error events for different bits
// independent of each other. Given that Bob receives
// 110, what is the probability that Alice intended to
// convey a 1?
//
// P(A111|B110) = P(B110|A111)P(A111)/P(B110),
// P(B110|A111) = P(B1|A1)²P(B0|A1) = .9²*.1
// P(A111) = P(A000) = .5
// P(B110) = P(B110|A000)P(A000) + P(B110|A111)P(A111)
// P(B110|A000) = P(B1|A0)²P(B0|A0) = .05²*.9
// P(B110) = .5(.05²*.9 + .9²*.1 ) =
//         = .5*.9(.05² + .9*.1)
// P(A111|B110) = .9²*.1*.5/.5*.9(.05² + .9*.1) =
//              = .9*.1/(.05² + .9*.1) =
//              =  1(1 + .05²/.9*.1) = .9729
//
// - Oscar, did you say tedious problem?
//
//////////////////////////////////////////////////////
///////////////////////////////////////////########///
///////////////////////////////////////////########///
///////////////////////////////////////////########///
// log: Thats problem namba 200, there are ########
// only 200 more problems to be solved     ### ####
//                                        ###  ### 
//                                       ##   ##   
//                                       #     #
