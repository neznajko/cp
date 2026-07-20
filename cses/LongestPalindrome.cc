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
//                                   [ Into the Blue ]
//                 
//                                Engines wait outside,
//                             the trajectory locks in,
//                                all lights turn blue.
//
//                                             ChatGPT
//
// 2.2.10. Before the separation of the final stage of
// the launch vehicle, the spacecraft had a velocity
// of υ. After the final stage was discarded, the
// spacecraft's velocity increased to 1.01υ, while
// the separated stage moves away relative to the
// spacecraft at a speed of 0.04υ. What is the mass
// of the final stage if the mass of the spacecraft is
// m₀?
//
// The only thing we have to consider before writing
// the momentum conservation law is this: What is the
// absolute velocity of the final stage?
//
// (m + m₀)υ = m₀1,01υ + m(1.01 - 0.04)υ
// 0.03m = 0.01m₀, m = m₀/3
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// This algorithm is from 1975 and it doesn't require
// hashing or binary search, it's quite beautiful and
// looks very similar to the z-function algorithm, the
// idea is that palindomes are mirrored around their
// centers and palindromes within palindromes will be
// identical:  
// ..abcbdbcba.. So lets say we currently are at j and
//     i   j     this is the rightmost palindrome
// we've found so far, its center is d and we can
// find immediately the corresponding palindrome at i,
// thus we don't need to recalculate it unless we
// wanna extend it beyound the current scope. There is
// also a trick that let us consider only odd sized 
// palindromes like bab tscst boomoob etcte.
//////////////////////////////////////////////////////
pair<i32,i32>  manacher_odd( const string& s ){
  const i32 n = s.size();
  vector<i32> d( n, 1 );
  i32 l = 0, r = 0;
  i32 ml = 0;
  i32 md = 0;
  for( i32 i = 1; i < n - 1; ++i ){
    if( i < r ){
      d[i] = min( r - i, d[ l + ( r - i )]);
    }
    for(; s[i + d[i]] == s[i - d[i]]; ++d[i] )
      ;
    // don't forget these
    if( i + d[i] > r ){
      l = i - d[i];
      r = i + d[i];
    }
    if( d[i] > md ){
      ml = i - d[i];
      md = d[i];
    }
  }
  dbg( d );
  return { ml, md };
}
//////////////////////////////////////////////////////
void pusk() {
  const auto s = loads<string>(); dbg( s );
  const i32 n = s.length();
  auto t = string( 2*n + 3, '#' );
  for( i32 j = 0; j < n; ++j ){
    t[2*j + 2] = s[j];
  }
  t.front() = '^';
  t.back() = '$';
  dbg( t );
  auto [l,d] = manacher_odd( t );
  dbg2( l, d );
  cout << s.substr( l/2, d - 1 ) << nl;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//                                       [ One Fifth ]
//
//                              Before the first touch,
//                             they have already given
//                                     everything away.
//
//                                            DeepSeek
//
// 2.2.11. A proton with an initial velocity υ flies
// directly toward a initially stationary helium
// nucleus. What is the velocity of the particles at
// their point of closest approach? The mass of the
// helium nucleus is approximately four times the mass
// of the proton.
//
// Ok let's look from the center of mass, cm velocity
// for masses m₁ and m₂ is:
// u = (m₁υ₁ + m₂υ₂)/(m₁ + m₂) the total momentum is
// m₁(υ₁ - u) + m₂(υ₂ - u) = 0, so the picture from
// cm will look like:
//
// ----->   <-----, when they are closest to each
// P             P  other their momentum will be 0, so
// the lab velocity at this moment will be exactly the
// cm velocity:
// u = (mυ + 0 )/(m + 4m) = 1/5υ
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
//                               [ The Fourth Circle ]
//
//                                 As the borders blur,
//                      gentle spirits cross the lines.
//                                  Where it all began.
//
//                                              Gemini
//
// 5 A "Venn diagram" with three overlapping circles
// is often used to illustrate the eight possible
// subsets associated with three given sets: Can the
// sixteen possibilities that arise with four given
// sets be illustrated by four overlapping circles?
//
// This is kinda hard problem, and I don't think I can
// give a proof, but is interesting what are these
// subsets anyway cos with three circles we have eight
// subsets, and with four sixteen? Logically with 0
// circles we must have one subset, 2 to the power of
// the circles, so it seems that this is the omega
// space, like in probability, one circle splits omega
// in two: all events inside the circle and all events
// outside it. It turns out that 16 split can be
// achieved with ellipses, but not with circles, the
// reason being that two ellipses can intersect in 4
// places while 2 circles can intersect at most 2
// places, so no matter how we try we can achieve
// maximum of only 14 subsets.
//
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////                                          ////// 
////// Longest Palindrome                       //////
//////                                          //////
////// Given a string your task is to determine //////
////// the longest palindromic substring of the //////
////// string. For example, the longest         //////
////// palindrome in aybabtu is bab.            //////
//////                                          //////
////// [ Input ]                                //////
////// The only input line contains a string of //////
////// length n. Each character is one of a–z.  //////
//////                                          //////
////// [ Output ]                               //////
////// Print the longest palindrome in the      //////
////// string. If there are several solutions,  //////
////// you may print any of them.               //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 <= n <= 1e6                            //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// aybabtu                                  //////
//////                                          //////
////// Output:                                  //////
////// bab                                      //////
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
