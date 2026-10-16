// -*- c-file-style: "gnu" -*-
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
# include <bits/stdc++.h>
//////////////////////////////////////////////////////
// 33. Let p > 1. If 2^p - 1 is prime, prove that p is
// prime. [Hint: Prove the contrapositive: If p is
// composite, so is 2^p - 1.]
// Note: The converse is false by Exercise 2(b).
//
// The converse is I guess is if 2^p - 1 is composite
// then p is composite yea zo Exercise 2(b) is: show
// that 2^11 - 1 is not prime.
// Ok if we have this statement:
// if a then b, the contrapositive is
// if not b then not a, and logically they are
// equivalent, example is if it rains it will be wet,
// it is not wet so it wasn't raining THATS!, nevamind
// Let p is composite
// x^2 - 1 = (x-1)(x+1)
// x^3 - 1 = (x-1)(x^2 + x + 1), zo
// x^n - 1 = (x-1)(x^n-1 + ... + 1)
// if p is composite say p = m*n then 2^p = 2^{mn} =
// = {2^m}^n =: x^n, zo 2^p - 1 = (x-1)(x^[n-1}+...+1)
// that is composite number
//////////////////////////////////////////////////////
# undef DeBug
//////////////////////////////////////////////////////
// 30. (a) Prove that there are no nonzero integers
// a, b such that a² = 2b².
// [Hint: Use the Fundamental Theorem of Arithmetic.]
//
// This kinda looks true for any prime p that is
// a² = pb² is not true, cos of the powers parity so
// to speak in the prime factorization of a and b,
// clearly there is nothing to balance the p factor
//
// (b) Prove that √2 is irrational. [Hint: Use proof
// by contracfution (Appendix.A). Assume that √2 = a/b
// (with a, b ∈ Z) and use part (a) to reach a
// contradiction.]
//
// Hence √p can't be represented as a/b, zo it is not
// a rational number
//
//////////////////////////////////////////////////////
// 32. (Euclid) Prove that there are infinitely many
// primes. [Hint: Use proof by contradiction
// (Appendix A). Assume there are only finitely many
// primes p1, p2, ..., pk and reach a contradiction by
// showing that the number p1p2...pk + 1 is not
// divisible by any of p1,p2,...,pk]
//
// ok lets
// p1p2...pk + 1 is divisible by pi then,
// p1p2...pk + 1 = αpi, zo 1 = piβ for some number β,
// which looks impossible cos pi is prime > 1
//
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
using state_t = i32;
// state is an offset to a record array
constexpr state_t N = 2e5;
constexpr state_t t0 = 0;
struct Record { // not very original
  i32 len = 0; // sub string max len
  i32 cntr = 1; // endpos counter
  state_t prev = t0; // points to t0 by default
  array<state_t,26> next{};
} rec[ N ];
state_t AVAIL = t0;
state_t last = AVAIL;

inline state_t NEWSTATE() { return ++AVAIL; }
inline i32 OFF( char c ){ return c - 'a'; }
inline i32& len( state_t j ){ return rec[ j ].len;  }
inline i32& cntr( state_t j ){ return rec[ j ].cntr;  }
inline state_t& prev( state_t j ){ return rec[ j ].prev; }
inline state_t& next( state_t j, char c ){ 
  return rec[ j ].next[ OFF( c )];
}

state_t CLONE( state_t p, state_t q ){
  state_t clone = NEWSTATE();
  rec[ clone ] = rec[ q ];
  len( clone ) = len( p ) + 1; // THATS'
  cntr( clone ) = 0;           //
  return clone;
}
void addchar( char c ){
  auto curr = NEWSTATE();
  len( curr ) = len( last ) + 1;
  //
  state_t p = last;
  do {
    next( p, c ) = curr;
    p = prev( p );
  } while( p != -1 and !next( p, c ));
  if( p != -1 ){
    auto q = next( p, c );
    if( len( p ) + 1 == len( q )){
      prev( curr ) = q;
    } else {
      state_t clone = CLONE( p, q );
      prev( curr ) = prev( q ) = clone;
      do {
        next( p, c ) = clone;
        p = prev( p );
      } while( p != -1 and next( p, c ) == q );
    }
  }
  last = curr;
}
void count() {
  // Zooo we have states from 0 to AVAIL, inclusive
  // and we have to sort them with respect to len
  // in decreasing order
  vector<state_t> states( AVAIL );
  // lets consider [1..AVAIL] only
  iota( on( states ), 1 );
  dbg( states );
  sort( on( states ), []( state_t u, state_t v ){
    return len( u ) > len( v );
  });
  dbg( states );
  for( auto v: states ){
    cntr( prev( v )) += cntr( v );
  }
}
void bld( const string& T ){
  prev( t0 ) = -1;
  for( auto c: T ){
    addchar( c );
  }
  count();
}
i32 query( const string& P ){
  state_t p = t0;
  for( auto c: P ){
    if( !next( p, c )) return 0;
    p = next( p, c );
  }
  return cntr( p );
}
void pusk() {
  auto T = loads<string>(); dbg( T );
  bld( T );
  auto k = loads<i32>();
  while( k-- ){
    auto P = loads<string>(); dbg( P );
    cout << query( P ) << nl;
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
//////////////////////////////////////////////////////　良い
//////////////////////////////////////////////////////　書く
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////　単体
//////                                          //////　たんたい  
////// Counting Patterns                        //////
//////                                          //////
////// Given a string and patterns, count for   //////
////// each pattern the number of positions     //////
////// where it appears in the string.          //////
//////                                          //////
////// [ Input ]                                //////
////// The first input line has a string of     //////
////// length n. The next input line has an     //////
////// integer k: the number of patterns.       //////
////// Finally, there are k lines that describe //////
////// the patterns. The string and the         //////
////// patterns consist of characters a–z.      //////
//////                                          //////
////// [ Output ]                               //////
////// For each pattern, print the number of    //////
////// positions.                               //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 ≤ n ≤ 1e5                              //////
////// 1 ≤ k ≤ 5e5                              //////
////// the total length of the patterns is at   //////
////// most 5e5                                 //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// aybabtu                                  //////
////// 3                                        //////
////// bab                                      //////
////// abc                                      //////
////// a                                        //////
//////                                          //////
////// Output:                                  //////
////// 1                                        //////
////// 0                                        //////
////// 2                                        //////
//////                                          //////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
///////////////////////////////////////////########///
///////////////////////////////////////////########///
// log: One of the positive things bout ai ########
// is that the number of professors will   ### ####
// disappear, there are too many of them  ###  ### 
//                                       ##   ##   
//                                       #     #
