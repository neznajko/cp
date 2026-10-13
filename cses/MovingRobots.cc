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
// 29. If n ∈ Z and n ≠ 0, prove that n can be written
// uniquely in the form n = (2^k)m, where k ≥ 0 and m
// is odd.
//
// Vell accoriding to Theorem 1.8 every number n has
// unique factorization n = p1^a1 p2^a2 ..., where
// pi are primes zo from here it's kinda obvious that
// m is the product of all primes except 2, vhich is
// odd and n = (2^k)m
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
// 25. A crime is committed by one of two suspects, A
// and B. Initially, there is equal evidence against
// both of them. In further investigation at the crime
// scene, it is found that the guilty party had a
// blood type found in 10% of the population. Suspect
// A does match this blood type, whereas the blood
// type of Suspect B is unknown.
//
// (a) Given this new information, what is the
// probability that A is the guilty party?
//
// A - A is guilty( why party? )
// B - B is guilty
// T - the guilty has the given blood type
//
// P(A|T) = P(T|A)P(A)/P(T)
// P(T|A) = 1, P(A) = .5
// P(T) = P(T|A)P(A) + P(T|B)P(B) = .5(1 + P(T|B))
// P(A|T) = 1/(1 + P(T|B)), P(T|B) = .1, zo
// P(A|T) = 1/1.1 = .9091
//
// (b) Given this new information, what is the
// probability that B’s blood type matches that found
// at the crime scene?
//
// M - matches
// P(M|T) = P(T|M)P(M)/P(T)
// P(T|M) = 1
// P(M) = .1
// P(T) = .5(1 + P(T|B)) = .5*1.1,
// P(M|T) = .1/.5*1.1 = .1/.55 = .1818
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
// . . . . . . . . 8  N
// . . . . . . . . 7 W E
// . . . . . . . . 6  S
// . . . . . . . . 5
// . . . . . . . . 4                  ^ r
// . . . . . . . . 3                  | a
// . . . . . . . . 2  8 9 .... offset | n
// . . . . . . . . 1  0 1 2 3 4 5 6 7 | k
// a b c d e f g h    ----> file
constexpr i32 W = 8;
constexpr i32 H = W;
constexpr i32 N = W * H;
array<vector<i32>,N> nbor;
//
inline i32 getoff( i32 rank, i32 file ){
  return (rank << 3) + file;
}
i32 getoff( const string& sq ){
  i32 file = sq[0] - 'a';
  i32 rank = sq[1] - '1';
  return getoff( rank, file );
}
inline i32 NORTH( i32 i ){ return i + 1; }
inline i32 EAST(  i32 j ){ return j + 1; }
inline i32 SOUTH( i32 i ){ return i - 1; }
inline i32 WEST(  i32 j ){ return j - 1; }
void initialize_nbors() {
  for( i32 i = 0; i < H; ++i ){
    for( i32 j = 0; j < W; ++j ){
      auto off = getoff( i, j );
      if( NORTH( i ) <  H ){
        nbor[ off ].push_back( getoff( NORTH( i ), j ));
      }
      if( EAST(  j ) <  W ){
        nbor[ off ].push_back( getoff( i, EAST(   j )));
      }
      if( SOUTH( i ) >= 0 ){
        nbor[ off ].push_back( getoff( SOUTH( i ), j ));
      }
      if( WEST(  j ) >= 0 ){
        nbor[ off ].push_back( getoff( i, WEST(   j )));
      }
    }
  }
}
void initialize() {
  initialize_nbors();
}
using brd_t = array<double,N>;
ostream& operator<<( ostream& s, const brd_t& brd ){
  for( i32 i = H - 1; i >= 0; --i ){
    for( i32 j = 0; j < W; ++j ){
      auto off = getoff( i, j );
      s << fixed << setprecision( 1 ) << brd[ off ] << sp;
    }
    s << nl;
  }
  return s;
}
brd_t getbrd( i32 k, i32 off ){
  brd_t curr, prev{};
  prev[ off ] = 1;
  while( k-- ){
    for( off = 0; off < N; ++off ){
      double p = 0;
      for( auto on: nbor[ off ]){
        p += prev[ on ] / siz( nbor[ on ]);
      }
      curr[ off ] = p;
    }
    prev = curr;
  }
  return curr;
}
array<brd_t,N> getp( i32 k ){
  array<brd_t,N> p;
  for( i32 i = 0; i < N; ++i ){
    p[i] = getbrd( k, i );
  }
  return p;
}
void pusk() {
  initialize();
  auto k = loads<i32>();
  auto p = getp( k );
  double e = 0;
  for( i32 off = 0; off < N; ++off ){
    double t = 1;
    for( i32 i = 0; i < N; ++i ){
      t *= 1 - p[i][ off ];
    }
    e += t;
  }
  cout << fixed << setprecision( 6 ) << e << nl;
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
//////////////////////////////////////////////////////　本体
//////////////////////////////////////////////////////　ほんたい
//////////////////////////////////////////////////////　ホンタイ
//////////////////////////////////////////////////////　main unit
//////                                          //////
////// Moving Robots                            //////　ベクトル
//////                                          //////　vector
////// Each square of an 8x8 chessboard has a   //////
////// robot. Each robot independently moves k  //////　検索
////// steps, and there can be many robots on   //////　ケンサク
////// the same square. On each turn, a robot   //////　けんさく
////// moves one step left, right, up or down,  //////　search
////// but not outside the board. It randomly   //////
////// chooses a direction among those where it //////　拡張
////// can move. Your task is to calculate the  //////　カクチョウ
////// expected number of empty squares after k //////　かくちょう
////// turns.                                   //////　extension
//////                                          //////
////// [ Input ]                                //////　やってきた
////// The only input line has an integer k.    //////　has arrived
//////                                          //////
////// [ Output ]                               //////
////// Print the expected number of empty       //////
////// squares rounded to six decimal places    //////
////// (rounding half to even).                 //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 ≤ k ≤ 100                              //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 10                                       //////
//////                                          //////
////// Output:                                  //////
////// 23.120740                                //////
//////                                          //////
//////////////////////////////////////////////////////
///////////////////////////////////////////########///
///////////////////////////////////////////########///
///////////////////////////////////////////########///
// log: If the Russians take the World,    ########
// there will be no one to buy their oil:) ### ####
//                                        ###  ### 
//                                       ##   ##   
//                                       #     #
