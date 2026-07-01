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
//
// 2.1.65*. A speed skater on an ice track tries to
// take a turn as close as possible to the inner edge
// of the track. A cyclist on a velodrome, on the
// other hand, takes the turn as far as possible from
// the inner edge. How can this difference in
// cornering strategy be explained? The banking of
// the velodrome becomes progressively steeper with
// increasing distance from its inner edge.
//
// Inclined plane turning:
//     . N        x: Nsinα + μNcosα = mu²/R
//      .         y: Ncosα - μNsinα = mg
//       .
//    f  .+      Ncosα(tgα + μ) = mu²/R
//     .  .      Ncosα(1 - μtgα) = mg
//        .       
//        .      u²/Rg = (tgα + μ)/(1 - μtgα)
//        . mg   u²/μRg = (tgα + μ)/μ(1 - μtgα)
//               u²/υ² = (tgα + μ)/μ(1 - μtgα),
// where υ is the speed at α=0
//
//        ######         for simplicity we can
//     ###      ###      assume a profile like this:
//   ##            ##                 
//  #     ######     #       .       with
// #    ##      ##    #      . .   # R = r(1 + sinα)
// #   #          #   #    r .   .#
//           ---r--          . ###
// ----R-----            ###### 
// [TOP VIEW]               r            [REAR VIEW]
//                       -----R---
// if t is the time to turn:
// t = πr/υ, and T = πR/u, so
// T/t = (R/r)(υ/u) = r(1 + sinα)√μ(1 - μtgα)/(tgα + μ)
// it can be shown that the right hand side is decreasing
// as a function of α so counter intuitively the turn
// on the larger radius takes less time
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
constexpr i32 N = 1e6;
i32 sieve[N + 1];
i32 counter[N + 1];
i32 mdivisor = 1;
//////////////////////////////////////////////////////
void initialize() {
  for( i32 x = 2; x <= N; ++x ){
    if( sieve[x] ){ continue; }
    for( i32 y = x; y <= N; y += x ){
      if( !sieve[y] ){ sieve[y] = x; }
    }
  }
}
//////////////////////////////////////////////////////
vector<i32> factorize( i32 x ){
  vector<i32> factors;
  while( x > 1 ){
    factors.push_back( sieve[x] );
    x /= sieve[x];
  }
  return factors;
}
//////////////////////////////////////////////////////
void count_divisors( const vector<i32>& factors ){
  i32 lastfactor = 1;
  vector<i32> divisors{1};
  i32 prevsize = 0;
  for( auto factor: factors ){
    i32 currsize = divisors.size();
    i32 j = ( factor == lastfactor ) ? prevsize : 0;
    do {
      i32 divisor = factor*divisors[j];
      if( ++counter[divisor] > 1 ){
        if( divisor > mdivisor ){
          mdivisor = divisor;
        }
      }
      divisors.push_back( divisor );
    } while( ++j < currsize );
    prevsize = currsize;
    lastfactor = factor;
  }
}
//////////////////////////////////////////////////////
void pusk() {
  initialize();
  auto n = loads<i32>();
  auto x = loadv<i32>( n );
  dbg2( n, x );
  for( auto y: x ){
    count_divisors( factorize( y ));
  }
  cout << mdivisor << nl;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//
// <> 2.1.66*. In a circus attraction, a motorcyclist
// moves along the inner surface of a sphere of radius
// R. After gaining speed, he begins to describe a
// horizontal circle in the upper hemisphere. Then,
// for greater effect, the lower hemisphere is
// removed. Determine the minimum speed of the
// motorcyclist if the coefficient of friction between
// the tires and the spherical surface is μ, and the
// angle between the vertical and the direction from
// the center of the sphere to the motorcyclist is α.
//         `f 
//       `     Nsinα + μNcosα = mυ²/Rsinα
//    +`       μNsinα - Ncosα = mg
//    ``
//    `  `  N      Ncosα(tgα + μ) = mυ²/Rsinα
//    `    `       Ncosα(μtgα - 1) = mg
//    `      `
//    ` mg       υ²/gRsinα = (tgα + μ)/(μtgα - 1)
//               υ = √[gRsinα(tgα + μ)/(μtgα - 1)]
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
////// Common Divisors                          //////
//////                                          //////
////// You are given an array of n positive     //////
////// integers. Your task is to find two       //////
////// integers such that their greatest        //////
////// common divisor is as large as possible.  //////
//////                                          //////
////// [Input]                                  //////
////// The first input line has an integer n:   //////
////// the size of the array.  The second line  //////
////// has n integers x_1,x_2,...,x_n: the      //////
////// contents of the array.                   //////
//////                                          //////
////// [Output]                                 //////
////// Print the maximum greatest common        //////
////// divisor.                                 //////
//////                                          //////
////// [Constraints]                            //////
////// 2 <= n <= 2e5                            //////
////// 1 <= x_i <= 1e6                          //////
//////                                          //////
////// [Example]                                //////
////// Input:                                   //////
////// 5                                        //////
////// 3 14 15 7 9                              //////
//////                                          //////
////// Output:                                  //////
////// 7                                        //////
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
