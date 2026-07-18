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
//////////////////////////////////////////////////////
//
//                                   [ Problem 2.2.8 ]
//
//                      Sweat drops fall straight down.
//                         The world rushes underneath,
//                             yet she gains no ground.
//
//                                              Gemini
//
// 2.2.8. A person decides to run along a rubber belt
// stretched over two horizontal rollers whose axles
// have zero friction. At first glance, this seems
// impossible: the person cannot transfer momentum to
// either the belt or the rollers, since their total
// momentum is zero. Does it follow from this that the
// person will remain in place?
//
// We can ignore the gravitation as an external force
// cos the motion take place only in horizontal
// direction. So the system rubber band + runner is
// closed, for closed systems we have conservaton of
// the momentum and since the total momentum of the
// rubber band is null we have P_runner = const, so
// we will remain in place only if our initial
// velosity is zero.
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
i64 n;
i32 k;
vector<i64> p;
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// If we have one prime only, say p, then the numbers
// less then or equal to n having p as factor are
// p 2p 3p ... (n/p)p, that is p divides n/p numbers,
// but if we take two primes p1 and p2 the answer is
// not simply n/p1 + n/p2 cos we are overcounting the
// numbers that have p1 and p2 both as factors so we
// have to substract n/p1p2, this is known as the
// inclusion exclusion principle for example for
// three primes it loosk smht like:
// n/p1 + n/p2 + n/p3 - n/p1p2 - n/p1p3 - n/p2p2 +
// + n/p1p2p3, so we need a function that calculates
// the above combinations
i64 combo( i32 i, i32 depth, i64 product ){
  if( depth == 0 ){
    return n / product;
  }
  i64 tot = 0;
  for( i32 j = i + 1; j + depth <= k; ++j ){
    // this avoids overflow
    if( p[j] <= n / product ){
      tot += combo( j, depth - 1, product * p[j] );
    }
  }
  return tot;  
}

void pusk() {
  n = loads<i64>(); dbg( n );
  k = loads<i32>(); dbg( k );
  p = loadv<i64>( k ); dbg( p );
  
  i64 tot = 0;
  for( i32 depth = 1; depth <= k; ++depth ){
    if( depth & 1 ){
      tot += combo( -1, depth, 1 );
    } else {
      tot -= combo( -1, depth, 1 );
    }
  }
  cout << tot << nl;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//
//                                  [ The Last Fight ]
//
//                                 Forests bow to wind.
//                        Stars vanish before the dawn.
//                                 Two dragons collide.
//
//                                             ChatGPT
//
// 2.2.9*. A body of mass m₁ flying at velocity v
// collides with a resting body of mass m₂. The force
// arising from the interaction of the bodies, which
// depends linearly on time, increases from zero to a
// value F₀ over a time interval t₀, and then
// uniformly decreases to zero over the same time
// interval t₀. Determine the velocity of the bodies
// after the interaction, assuming that all motion
// occurs along a single straight line.
//
// dp = F(t)dt, zo Δp = ∫F(t)dt = F₀t₀,
// v₂ = F₀t₀/m₂,
// m₁v - m₁v₁ = F₀t₀, v₁ = v - F₀t₀/m₁
//
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
////// Prime Multiples                          //////
//////                                          //////
////// You are given k distinct prime numbers   //////
////// a_1,a_2,...,a_k and an integer n. Your   //////
////// task is to calculate how many of the     //////
////// first n positive integers are divisible  //////
////// by at least one of the given prime       //////
////// numbers.                                 //////
//////                                          //////
////// [ Input ]                                //////
////// The first input line has two integers n  //////
////// and k. The second line has k prime       //////
////// numbers a_1,a_2,...,a_k.                 //////
//////                                          //////
////// [ Output ]                               //////
////// Print one integer: the number integers   //////
////// within the interval 1,2,...,n that are   //////
////// divisible by at least one of the prime   //////
////// numbers.                                 //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 <= n <= 1e18                           //////
////// 1 <= k <= 20                             //////
////// 2 <= a_i <= n                            //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 20 2                                     //////
////// 2 5                                      //////
//////                                          //////
////// Output:                                  //////
////// 12                                       //////
//////                                          //////
////// Explanation: the 12 numbers are          //////
////// 2,4,5,6,8,10,12,14,15,16,18,20.          //////
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
