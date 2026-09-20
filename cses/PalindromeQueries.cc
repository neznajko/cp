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
constexpr i64 A = 911382323;
constexpr i64 B = 972663749;
// s[0]A^(n-1)+s[1]A^(n-2)+...+s[n-1]A^0 mod B
struct Node {
  i32 size;
  i64 str8; // hash
  i64 revs; // reverse hash
};
ostream& operator<<( ostream& s, const Node& node ){
  return s << node.size << "("
           << node.str8 << ","
           << node.revs << ")";
}
vector<Node> t; // se gu men to
vector<i64> p; // powers
i32 resize( i32 n ){
  if( n & (n - 1)){
    return 1 << (32 - __builtin_clz( n ));
  }
  return n;
}
Node merge( const Node& a, const Node& b ){
  return { 
    a.size + b.size,
    ((a.str8 * p[ b.size ] % B) + b.str8) % B,
    ((b.revs * p[ a.size ] % B) + a.revs) % B
  };
}
void bld( const string& s ){
  auto m = siz( s );
  dbg2( m, s );
  p.resize( m );
  p[0] = 1;
  for( i32 i = 1; i < m; ++i ){
    p[i] = p[i-1] * A % B;
  }
  auto n = resize( m ); dbg( n );
  t.resize( 2*n );
  for( i32 i = 0; i < m; ++i ){
    t[n+i] = {1,s[i],s[i]};
  }
  for( i32 j = 2*n - 1; j > 1; j -= 2 ){
    t[j/2] = merge( t[j-1],t[j] );
  }
  dbg( p );
  dbg( t );
}
void preprocess( const string& s ){
  bld( s );
}
void write( i32 k, char x ){
  auto n = siz( t )/2;
  i32 j = n + k;
  t[j] = {1,x,x};
  for( j /= 2; j > 0; j /= 2 ){
    t[j] = merge( t[2*j],t[2*j+1] );
  }  
}
Node read( i32 x, i32 y, i32 a, i32 b, i32 j ){
  if( y < a or x > b ) return {};
  if( a <= x and y <= b ) return t[j];
  i32 d = (x+y)/2;
  return merge( read( x, d, a, b, 2*j ),
                read( d + 1, y, a, b, 2*j + 1 ));
}
void handle_update( i32 k, char x ){
  dbg2( k, x );
  write( k, x );
}
void handle_query( i32 a, i32 b ){
  dbg2( a, b );
  auto n = siz( t )/2;
  auto node = read( 0, n - 1, a, b, 1 );
  if( node.str8 == node.revs ){
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
void pusk() {
  auto [n,m] = loadp<i32>();
  auto s = loads<string>();
  preprocess( s );
  while( m-- ){
    auto mode = loads<i32>();
    if( mode == 1 ){
      auto k = loads<i32>();
      auto x = loads<char>();
      handle_update( k - 1, x );
    } else {
      auto a = loads<i32>();
      auto b = loads<i32>();
      handle_query( a - 1, b - 1 );
    }
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
////// Palindrome Queries                       //////
//////                                          //////
////// You are given a string that consists of  //////
////// n characters between a–z. The positions  //////
////// of the string are indexed 1,2,...,n.     //////
////// Your task is to process m operations of  //////
////// the following types:                     //////
//////                                          //////
////// Change the character at position k to x  //////
////// Check if the substring from position a   //////
////// to position b is a palindrome            //////
//////                                          //////
////// [Input]                                  //////
////// The first input line has two integers n  //////
////// and m: the length of the string and the  //////
////// number of operations. The next line has  //////
////// a string that consists of n characters.  //////
////// Finally, there are m lines that describe //////
////// the operations. Each line is of the form //////
////// "1 k x" or "2 a b".                      //////
//////                                          //////
////// [Output]                                 //////
////// For each operation 2, print YES if the   //////
////// substring is a palindrome and NO         //////
////// otherwise.                               //////
//////                                          //////
////// [Constraints]                            //////
////// 1 ≤ n, m ≤ 2e5                           //////
////// 1 ≤ k ≤ n                                //////
////// 1 ≤ a ≤ b ≤ n                            //////
//////                                          //////
////// [Example]                                //////
////// Input:                                   //////
////// 7 5                                      //////
////// aybabtu                                  //////
////// 2 3 5                                    //////
////// 1 3 x                                    //////
////// 2 3 5                                    //////
////// 1 5 x                                    //////
////// 2 3 5                                    //////
//////                                          //////
////// Output:                                  //////
////// YES                                      //////
////// NO                                       //////
////// YES                                      //////
//////                                          //////  
//////////////////////////////////////////////////////
///////////////////////////////////////////########///
///////////////////////////////////////////########///
///////////////////////////////////////////########///
// log: Love is allowed for all losers,    ########
// hate is privilege only for the winners  ### ####
//                                        ###  ### 
//                                       ##   ##   
//                                       #     #
