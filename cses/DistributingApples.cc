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
//                             [ The Sum of All Bets ]
//
//                                Winter dawn, no wind,
//                       twelve paces measured in snow,
//                             one shot writes the end.
//
//                                        ディープシーク
//
// Example 2.7.3 (Gambler’s ruin). Two gamblers, A and
// B, make a sequence of $1 bets. In each bet, gambler
// A has probability p of winning, and gambler B has
// probability q = 1 − p of winning. Gambler A starts
// with i dollars and gambler B starts with N − i
// dollars; the total wealth between the two remains
// constant since every time A loses a dollar, the
// dollar goes to B, and vice versa. We can visualize
// this game as a random walk on the integers between
// 0 and N, where p is the probability of going to the
// right in a given step: imagine a person who starts
// at position i and, at each time step, moves one
// step to the right with probability p and one step
// to the left with probability q = 1 − p. The game
// ends when either A or B is ruined, i.e., when the
// random walk reaches 0 or N. What is the probability
// that A wins the game (walking away with all the
// money)?
//
// Conditioning on the fyorst bet:
// P(A) = P(A|W)P(W) + P(A|L)P(L), P(W) = p, P(L) = q
// if P(A|W) the number of dollars increase by one, so
// we can write in terms of i:
// P(i) = P(i+1)p + P(i-1)q             <<< solve this
// the initial conditions are P(0) = 0, P(N) = 1;
// P(i) = pP(i) + qP(i) = P(i+1)p + P(i-1)q;
// p(P(i) - P(i+1)) = q(P(i-1) - P(i));
// P(i+1) - P(i) = q/p(P(i) - P(i-1))
//
// P(2) - P(1) = (q/p)(P(1) - P(0));
// P(2) = P(1)(1 + q/p)
// P(3) - P(2) = q/p(P(2) - P(1)) = (q/p)²P(1),
// P(3) = P(1)(1 + q/p + (q/p)²)
// ..., zo
// P(i) = P(1)(1 - (q/p)^i)/(1 - q/p), to get P(1)
// we use the fact that
// P(N) = P(1)(1 - (q/p)^N)/(1 - q/p) = 1, zo
// P(i) = (1 - (q/p)^i)/(1 - (q/p)^N)
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
constexpr i64 MOD = 1e9 + 7;
constexpr i32 N = 2e6;
vector<i64> f( N + 1 );
vector<i64> i( N + 1 );
i64 modexp( i64 x, i64 y ){
  if( y == 0 ) return 1LL;
  auto z = modexp( x, y/2 );
  i64 r = z * z % MOD;
  if( y & 1 ){
    r = r * x % MOD;
  }
  return r;
}
i64 inv( i64 x ){
  return modexp( x, MOD - 2 );
}
void bld() {
  f[0] = i[0] = f[1] = i[1] = 1;
  for( i32 j = 2; j <= N; ++j ){
    f[j] = f[j-1] * j % MOD;
    i[j] = inv( f[j] );
  }
}
i64 C( i64 n, i64 k ){
  return f[n] * i[k] % MOD * i[n-k] % MOD;
}
void pusk() {
  bld();
  auto [n,m] = loadp<i32>();
  cout << C( n + m - 1, n - 1 ) << nl;
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
////// Distributing Apples                      //////
//////                                          //////
////// There are n children and m apples that   //////
////// will be distributed to them. Your task   //////
////// is to count the number of ways this can  //////
////// be done.  For example, if n=3 and m=2,   //////
////// there are 6 ways: [0,0,2], [0,1,1],      //////
////// [0,2,0], [1,0,1], [1,1,0] and [2,0,0].   //////
//////                                          //////
////// [ Input ]                                //////
////// The only input line has two integers n   //////
////// and m.                                   //////
//////                                          //////
////// [ Output ]                               //////
////// Print the number of ways modulo 1e9+7.   //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 <= n,m <= 10^6                         //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 3 2                                      //////
//////                                          //////
////// Output:                                  //////
////// 6                                        //////
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
