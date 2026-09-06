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
        sep = ",";                                             \
    }                                                          \
    return os << "]";                                          \
}
////////////////////////////////////////////////////////////////
template <typename K, typename V>
ostream& operator<<( ostream& os, const pair<K,V>& p );
////////////////////////////////////////////////////////////////
OVERLOAD_OSTREAM_OPERATOR( vector );
////////////////////////////////////////////////////////////////
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
// 10. Fred is working on a major project. In planning
// the project, two milestones are set up, with dates
// by which they should be accomplished. This serves
// as a way to track Fred’s progress. Let A1 be the
// event that Fred completes the first milestone on
// time, A2 be the event that he completes the second
// milestone on time, and A3 be the event that he
// completes the project on time.
// Suppose that P(Aj+1|Aj) = .8 but P(Aj+1|Ajc) = .3
// for j = 1, 2, since if Fred falls behind on his
// schedule it will be hard for him to get caught
// up. Also, assume that the second milestone
// supersedes the first, in the sense that once we
// know whether he is on time in completing the second
// milestone, it no longer matters what happened with
// the first milestone. We can express this by saying
// that A1 and A3 are conditionally independent given
// A2 and they’re also conditionally independent given
// A2c.
//
// (a) Find the probability that Fred will finish the
// project on time, given that he completes the first
// milestone on time. Also find the probability that
// Fred will finish the project on time, given that he
// is late for the first milestone.
//
// P(A3|A1) = P(A3|A1c) = ?
//
// P(A3|A1) = P(A3|A2,A1)P(A2|A1) + P(A3|A2c,A1)P(A2c|A1)
// cos A3 and A1 are conditionally independend of A2 we
// have P(A1A3|A2) = P(A1|A2)P(A3|A1,A2) =
//                 = P(A1|A2)P(A3|A2), zo
// P(A3|A1,A2) = P(A3|A2), same for Ac, zo
// P(A3|A1) = P(A3|A2)P(A2|A1) + P(A3|A2c)P(A2c|A1) =
//          = .8² + .3² = .73
//
// P(A3|A1c) = P(A3|A2,A1c)P(A2|A1c) + P(A3|A2c,A1c)P(A2c|A1c)
// Here I guess we can assume conditionally independence
// of A3 and A1c as well zo:
// = P(A3|A2)P(A2|A1c) + P(A3|A2c)P(A2c|A1c),
// P(A2c|A1c) = 1 - P(A2|A1c) = .7
// P(A3|A1c) = .8.3 + .3.7 = .3*1.5 = .45
//
// (b) Suppose that P(A1) = 0.75. Find the probability
// that Fred will finish the project on time.
//
// P(A3) = P(A3|A1)P(A1) + P(A3|A1c)P(A1c) =
//       = .73.75 + .45.25 = .5475 + .1125 = .66
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
constexpr i64 MOD = 1e9+7;
constexpr i32 N = 500;
using Rank = array<i64,N+1>;
i32 n, m;
array<Rank,N> mat;
vector<pair<i32,i32>> swapped_pairs; // columns
void anu_rank( Rank& r, i32 i, i32 j ){
  for(; i <= j; ++i ){
    cout << r[i] << sp;
  }
  cout << nl;
}
void ne_ndo_e_fini() {
  for( i32 i = 0; i < n; ++i ){
    anu_rank( mat[i], 0, m );
  }
  cout << nl;
}
# ifdef DeBug
#   define dina_rank() ne_ndo_e_fini()
# else
#   define dina_rank()
# endif
void swap( i32 i, i32 j ){
  swap( mat[i], mat[j] );
}
//////////////////////////////////////////////////////
// Fermat little theorem states that x^(m-1) mod m = 1,
// if m is prime, so the modulo inverse of x is
// x^(m-2) mod m
//////////////////////////////////////////////////////
i64 modexp( i64 x, i64 n ){
  if( !n ) return 1;
  auto z = modexp( x, n/2 );
  z = z * z % MOD;
  if( n & 1 ) z = z * x % MOD;
  return z;
}
//////////////////////////////////////////////////////
i64 invs( i64 x ){
  return modexp( x, MOD - 2 );
}
//////////////////////////////////////////////////////
// 0 ... 0 r[j] ... -> 0 ... 0 1 ...
void normalize( i32 j ){
  Rank& r = mat[j];
  if( r[j] == 1 ) return;
  const auto f = invs( r[j] );
  for(; j <= m; ++j ){
    r[j] = r[j] * f % MOD;
  }
}
//////////////////////////////////////////////////////
// j: 0 ... 0 1 ...
// i: 0 ... 0 mat[i][j] ... -> 0 ... 0 0 ...
void zerofy( i32 i, i32 j ){
  const auto f = mat[i][j];
  for( i32 k = j; k <= m; ++k ){
    mat[i][k] = (mat[i][k] - (f * mat[j][k] % MOD) + MOD) % MOD;
  }
}
//////////////////////////////////////////////////////
// swaps two colums at j and k of mat
void column_swap( i32 j, i32 k ){
  for( i32 i = 0; i < n; ++i ){
    swap( mat[i][j], mat[i][k] );
  }
  swapped_pairs.push_back({ j, k });
}
//////////////////////////////////////////////////////
// handles the case vhen mat[j][j] element is zero so
// we swap rows if there is appropirate one, otherwise
// if m > n we search a column to swap
bool do_the_swap( i32 j ){
  for( i32 i = j + 1; i < n; ++i ){
    if( mat[i][j] ){
      swap( i, j );
      return true;
    }
  } 
  for( i32 k = n; k < m; ++k ){
    if( mat[j][k] ){
      column_swap( j, k );
      return true;
    }
  }
  return false;
}
//////////////////////////////////////////////////////
void process_jth_column( i32 j ){
  if( !mat[j][j] ){
    if( !do_the_swap( j )) return;
  }
  normalize( j );
  for( i32 i = j + 1; i < n; ++i ){
    zerofy( i, j );
  }
}
//////////////////////////////////////////////////////
void nope() { cout << -1 << nl; }
//////////////////////////////////////////////////////
// Faeg i-varv dîn na lanc a nu ranc!
// Their armour is weak at the neck... and beneath the arm.
void solve() {
  vector<i64> x( m );
  for( i32 j = 0; j < n; ++j ){
    process_jth_column( j );
  }
  dina_rank();
  dbg( swapped_pairs );
  // if n > m we should have all zeroes for i = m,...
  for( i32 i = m; i < n; ++i ){
    if( mat[i][m] ) return nope();
  }
  // now we start from rear and calculate the solution
  for( i32 i = min( n, m ) - 1; i >= 0; --i ){
    // now we have to calculate the sum after the ii
    // term
    i64 sum = 0;
    for( i32 j = i + 1; j < m; ++j ){
      sum += mat[i][j] * x[j] % MOD;
      sum %= MOD;
    }
    x[i] = (mat[i][m] - sum + MOD) % MOD;
    // degenerate( yea what a word ) case
    if( !mat[i][i] ){
      if( x[i] ) return nope();
    }
  }
  // reshuffle
  for( auto [i,j]: swapped_pairs ){
    swap( x[i], x[j] );
  }
  dbg( x );
  for( auto y: x ){
    cout << y << sp;
  }
  cout << nl;
}
//////////////////////////////////////////////////////
// 2.2.31. N balls of mass m each are bouncing on a
// scale pan. What is the average force acting on the
// scale pan if the speed (magnitude) of the balls
// does not change? Does this force increase or
// decrease if the speed of each ball decreases after
// impact?
//
// Zo lets look at one ball for small period of time
// Δt it changes the directioin of the speed υ so for
// that time the force will be F = Δp/Δt = 2mυ/Δt, then
// the ball will bounce for time τ = 2υ/g and the same
// thing will repeat so the average force is:
// <F> = (FΔt + 0τ)/(Δt + τ) ≈ FΔt/τ = 2mυ/2υ/g = mg,
// for N balls this will be Nmg
//
// This is kinda sneaky question the normal answer is
// decreasing but ok the momentum transfer is
// decreasing but also the time when the force is 0
// is decreasing one can show that the average force
// for the time until the ball eventually stops is
// larger then mg which is counter intuitive but as an
// example we can consider the extreme case of plastic
// ball that sticks to the pan, then the average force
// can only increase but definitely not decrease
//////////////////////////////////////////////////////
void pusk() {
  tie( n,m ) = loadp<i32>(); dbg2( n, m );
  for( i32 i = 0; i <  n; ++i ){
  for( i32 j = 0; j <= m; ++j ){
    cin >> mat[i][j];
  }}
  solve();
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
////// System of Linear Equations               //////
//////                                          //////
////// You are given n*(m+1) coefficients Aij   //////
////// and Bi which form the following n linear //////
////// equations:                               //////
//////                                          //////
////// A11X1 + A12X2 + ... + A1mXm = B1 % MOD   //////
////// A21X1 + A22X2 + ... + A2mXm = B2 % MOD   //////
////// ...                                      //////
////// An1X1 + An2X2 + ... + AnmXm = Bn % MOD   //////
//////                                          //////
////// Your task is to find any m integers      //////
////// X1, X2, ..., Xm that satisfy the given   //////
////// equations.                               //////
//////                                          //////
////// [ Input ]                                //////
////// The first line has two integers n and m: //////
////// the number of equations and variables.   //////
////// The next n lines each have m+1 integers  //////
////// Ai1, Ai2, ..., Aim, Bi: the coefficients //////
////// of the ith equation.                     //////
//////                                          //////
////// [ Output ]                               //////
////// Print m integers X1, X2, ..., Xm: the    //////
////// values of the variables that satisfy the //////
////// equations. The values must also satisfy  //////
////// 0 ≤ Xi < MOD. You can print any valid    //////
////// solution. If no solution exists print    //////
////// only -1.                                 //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 ≤ n, m ≤ 500                           //////
////// 0 ≤ Aij, Bi < MOD = 1e9+7                //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 3 3                                      //////
////// 2 0 1 7                                  //////
////// 1 2 0 0                                  //////
////// 1 3 1 2                                  //////
//////                                          //////
////// Output:                                  //////
////// 2 1000000006 3                           //////
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
