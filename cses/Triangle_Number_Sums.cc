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
// The nth triangular number has the form
// x = 1+2+...+n = n(n+1)/2, so 2x = n² + n,
// 8x = 4n² + 4n = 4n² + 4n + 1 - 1 = (2n+1)² - 1, zo
// (2n+1)² = 8x+1, and x is a triangular number if
// 8x+1 is perfect square, if x is sum of two
// triangular numbers n(n+1)/2 and m(m+1)/2 similarly
// (2n+1)² + (2m+1)² = 8x+2, the equation x²+y²=n has
// solutions if prime factors p of n with p mod 4 = 3,
// have even powers, this fact according to GPT is
// known from 1640 by Pierre de Fermat and later
// proved by Leonhard Euler in 1749( why I'm writing,
// those dates :). In Gauss' log there is some famous
// note: ΕΥΡΗΚΑ! num = Δ + Δ + Δ, that is every number
// can be represented as a sum of most 3 triangular
// numbers. The problem basically reduces to finding
// if we can represent 8n+2 as sum of squares cos if
// 8n+1 is not a perfect square, then we check if 8n+2
// is a sum of squares, if not dump 3( without Eureka )
// Funny enough we can make prime factorization of
// number n using only primes ≤ √n, cos any number
// can't have two prime factors > √n, so the number of
// primes between 2 and 1e6 is bout 1e4 so with 100
// test cases that results in 1e6 total running time
bool is_perfect_square( i64 n ){
  i64 x = sqrt( n );
  return x * x == n;
}
constexpr i32 N = 1e6;
vector<bool> sieve( N + 1 );
vector<i64> primes;
void bld() {
  for( i32 j = 2; j <= N; ++j ){
    if( sieve[j] ) continue;
    primes.push_back( j );
    for( i32 x = j + j; x <= N; x += j ){
      sieve[x] = true;
    }
  }
}
bool two_squares( i64 n ){
  i64 q = sqrt( n );
  for( auto p: primes ){
    if( p > q ) break;
    i32 pover = 0;
    while( n % p == 0 ){
      ++pover;
      n /= p;
    }
    if( p % 4 == 3 and ( pover & 1 )){
      return false;
    }
  }
  return n % 4 != 3;
}
i32 triangle( i64 n ){
  if( is_perfect_square( 8*n+1 )) return 1;
  if( two_squares( 8*n+2 )) return 2;
  return 3;
}
void pusk() {
  bld();
  auto t = loads<i32>();
  while( t-- ){
    auto n = loads<i64>(); dbg( n );
    cout << triangle( n ) << nl;
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
////// Triangle Number Sums                     //////
//////                                          //////
////// A triangle number is a positive integer  //////
////// of the form 1+2+...+k. The first         //////
////// triangle numbers are 1, 3, 6, 10 and 15. //////
////// Every positive integer can be            //////
////// represented as a sum of triangle         //////
////// numbers. For example, 42=21+21 and       //////
////// 1337=1326+10+1. Given a positive         //////
////// integer n, determine the smallest number //////
////// of triangle numbers that sum to n.       //////
//////                                          //////
////// [Input]                                  //////
////// The first line has an integer t: the     //////
////// number of tests.  After that, each line  //////
////// has a positive integer n.                //////
//////                                          //////
////// [Output]                                 //////
////// For each test, print the smallest number //////
////// of triangle numbers.                     //////
//////                                          //////
////// [Constraints]                            //////
////// 1 ≤ t ≤ 100                              //////
////// 1 ≤ n ≤ 1e12                             //////
//////                                          //////
////// [Example]                                //////
////// Input:                                   //////
////// 5                                        //////
////// 1                                        //////
////// 2                                        //////
////// 3                                        //////
////// 42                                       //////
////// 1337                                     //////
//////                                          //////
////// Output:                                  //////
////// 1                                        //////
////// 2                                        //////
////// 1                                        //////
////// 2                                        //////
////// 3                                        //////
//////                                          //////
// (16 / 74). S h o w that P(A|B) ≤ P(A) i m p l i e s
// P(A|¬B) ≥ P(A), a n d give an intuitive explanation
// of why this makes sense.
//
// P(A| B) = P( B|A)P(A)/P( B)
// P(A|¬B) = P(¬B|A)P(A)/P(¬B)
//
// P(A| B)/P(A) = P( B|A)/P( B) ≤ 1,
// P( B|A) ≤ P( B)
// 1 - P(¬B|A) ≤ 1 - P(¬B)
// P(¬B|A) ≥ P(¬B)
// P(¬B|A)/P(¬B) ≥ 1
// P(¬B|A)P(A)/P(¬B) ≥ P(A)
// P(A|¬B) ≥ P(A), makes no sense
//
//////                                          //////
// (17/74) In deterministic l o g i c, t h e statement
// "A implies B" is equivalent to i t s contrapositive,
// "not B implies n o t A". In t h i s problem we will
// consider analogous statements in probability, t h e
// logic of uncertainty. Let A and B be events w i t h
// probabilities not equal to 0 or 1.
//
// (a) Show that if P(B|A) = 1, then P(Ac|Bc) = 1.
// Hint: Apply Bayes’ rule and LOTP.
// 
// P(Bc|A) = 1 - P(B|A) = 0 = P(A|Bc)P(Bc)/P(A), zo
// P(A|Bc) = 0, cos P(A) and P(B) are not 0 or 1,
// P(Ac|Bc) = 1 - P(A|Bc) = 1
// 
// (b) Show however that the result in (a) does not
// hold in general if = is replaced by ≈. In
// particular, find an example where P(B|A) is very
// close to 1 but P(Ac|Bc) is very close to 0.
// Hint: What happens if A and B are independent?
//
// P(B|A) = 1 - ε, P(Bc|A) = ε = P(A|Bc)P(Bc)/P(A)
// P(A|Bc) = P(A)ε/P(Bc), P(Ac|Bc) = 1 - P(A)ε/P(Bc)
// if P(B|A) = P(B) = 1 - P(Bc), then P(Bc) = ε, and
// P(Ac|Bc) = 1 - P(A), abd this can be close ot 0, if
// we chose P(A) to be close to 1
//
//////                                          //////
// (18/74) Show that if P(A) = 1, then P(A|B) = 1 for
// any B with P(B) > 0. Intuitively, this says that if
// someone dogmatically believes something with
// absolute certainty, then no amount of evidence will
// change their mind. The principle of avoiding
// assigning probabilities of 0 or 1 to any event
// (except for mathematical certainties) was named
// Cromwell’s rule by the statistician Dennis Lindley,
// due to Cromwell saying to the Church of Scotland,
// "Think it possible you may be mistaken."
//
// If P(A) = 1 then A is the sample space so AB = B,
// and P(A|B) = P(AB)/P(B) = P(B)/P(B) = 1
//
//////                                          //////
// 11/16 A Double Tower of Hanoi contains 2n disks of
// n different sizes, two of each size. As usual,
// we're required to move only one disk at a time,
// without putting a larger one over a smaller one.
//
// a  How many moves does it take to transfer a
//    double tower from one peg to another, if disks
//    of equal size are indistinguishable from each
//    other?
//
//    T(n+2) = T(n) + 2 + T(n) = 2T(n) + 2
//
//    T(0) = 0
//    T(n+2) = 2T(n) + 2, n = 0,2,4,6,...
//    T(n+2) = 2T(n) + 4 - 2,
//    T(n+2) + 2 = 2(T(n) + 2),
//    U(n) := T(n) + 2
//    U(n+2) = 2U(n), U(0) = 2
//    n := 2k
//    U(2(k+1)) = 2U(2k) = 2^2U(2(k-1)) =
//    = 2^3U(2(k-2)) = ... = 2^(k+1)U(2(k-k)) =
//    = 2^(k+1)U(0) = 2*2^(k+1)
//    T(2(k+1)) = 2(2^(k+1) - 1)
//
// b  What if we are required to reproduce the
//    original top-to-bottom order of all the
//    equal-size disks in the final arrangement?
//
//    T(n+2) = T(n) + 2 + T(n) + 2 + T(n)
//
//    T(0) = 0
//    T(n+2) = 3T(n) + 4, n = 0,2,4,6,8,...
//    T(n+2) = 3T(n) + 6 - 2
//    T(n+2) + 2 = 3(T(n) + 2), similarly we get
//    T(2(k+1)) = 2(3^(k+1) - 1)
//
//////                                          //////
// 2.2.34/47. Two carts, each of mass M, move parallel
// to each other with initial velocities v₁ and v₂. A
// load of mass m, initially lying on the first cart
// with almost zero velocity relative to that cart, is
// thrown onto the second cart. Then, with almost zero
// velocity relative to the second cart, it is thrown
// back onto the first cart. What will the difference
// between the velocities of the carts be after N such
// transfers of the load back and forth? Try to
// qualitatively explain viscous friction that arises
// when layers of gas slide relative to one another.
//
// m leaves v₁: (m+M)v₁ = mv₁ + Mv₁
// m enters v₂: mv₁ + Mv₂ = (m+M)v₂'               (1)
//
// m leaves v₂': (m+M)v₂' = mv₂' + Mv₂'
// m enters v₁: mv₂' + Mv₁ = (m+M)v₁'              (2)
//
// from (1) and (2) follows that:
// v₁ - v₁' = mM(v₁ - v₂)/(m + M)²
// v₂ - v₂' = m(v₂ - v₁)/(m + M), zo after one round
// of m going here and there:
// v₁' - v₂' = (v₁ - v₂)(M/(M+m))² and we are back in
// the same positon, zo after n rounds:
// v₁(n) - v₂(n) = (v₁ - v₂)(M/(M+m))^2n 
// 
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
