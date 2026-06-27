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
// Example 2.3.9 (Testing for a rare disease). A
// patient named Fred is tested for a disease called
// conditionitis, a medical condition that afflicts 1%
// of the population. The test result is positive,
// i.e., the test claims that Fred has the
// disease. Let D be the event that Fred has the
// disease and T be the event that he tests positive.
// Suppose that the test is "95% accurate"; there are
// different measures of the accuracy of a test, but
// in this problem it is assumed to mean that
// P(T|D) = 0.95 and P(¬T|¬D) = 0.95. The quantity
// P(T|D) is known as the «sensitivity» or «true
// positive rate» of the test, and P(¬T|¬D) is known
// as the «specificity» or «true negative rate». Find
// the conditional probability that Fred has
// conditionitis, given the evidence provided by the
// test result
//
// P(D|T) = ?
// P(D|T) = P(T|D)P(D)/P(T)
// P(T|D) = 0.95
// P(D) = 1% = 0.01
// P(T) = P(T|D)P(D) + P(T|¬D)P(¬D)
// P(T|¬D) + P(¬T|¬D) = 1, zo
// P(T) = P(T|D)P(D) + (1 - P(¬T|¬D))P(¬D)
// P(¬T|¬D) = 0.95
// P(¬D) = 0.99
// P(T) = 0.95*0.01 + (1 - 0.95)*0.99 =
//      = (95 + 5*99)/10000 = 0.059
// P(D|T) = 0.95*0.01/0.059 ≈ 0.1610
//////////////////////////////////////////////////////
constexpr i32 N = 1'000'000;
i32 z[N];
i32 n;
string s;
//////////////////////////////////////////////////////
void conz() { // thaaaats tricky
  s.push_back( '#' ); // guard
  i32 x = 0;
  i32 y = 0;
  for( i32 k = 1; k < n; ++k ){ // s[n] = #
    if( k <= y ){
      if( k + z[k - x] <= y ){
        z[k] = z[k - x];
      } else {
        const i32 w = z[k - x];
        i32 j = 0;
        while( s[y + 1 + j] == s[w + j] ){
          ++j;
        }
        x = k;
        y += j;
        z[k] = y - x + 1;
      }
    } else {
      i32 j = 0;
      while( s[j] == s[j + k] ){ ++j; }
      if( j ){
        z[k] = j;
        x = k;
        y = k + z[k] - 1;
      }
    }
  }
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
void pusk() {
  s = loads<string>(); dbg( s );
  n = s.length(); dbg( n );
  conz();
  dmp( z, n );
  for( i32 k = n - 1; k > 0; --k ){
    if( k + z[k] == n ){
      cout << z[k] << sp;
    }
  }
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// Example 2.3.10 (Six-fingered man). A crime has been
// committed in a certain country. The perpetrator is
// one (and only one) of the n men who live in the
// country. Initially, these n men are all deemed
// equally likely to be the perpetrator. An eyewitness
// then reports that the crime was committed by a man
// with six fingers on his right hand. Let p0 be the
// probability that an innocent man has six fingers on
// his right hand, and p1 be the probability that the
// perpetrator has six fingers on his right hand, with
// p0 < p1. (We may have p1 < 1, since eyewitnesses
// are not 100% reliable.) Let a = p0/p1 and
// b = (1 − p1)/(1 − p0).
//
// Rugen lives in the country. He is
// found to have six fingers on his right hand.
//
// (a) Given this information, what is the probability
// that Rugen is the perpetrator?
// (b) Now suppose that all n men who live in the
// country have their hands checked, and Rugen is the
// only one with six fingers on his right hand. Given
// this information, what is the probability that
// Rugen is the perpetrator?
//
// (a) 
// p0 - probability that an innocent man has six
//      fingers on his right hand
// p1 - probability that the perpetrator has six
//      fingers on his right hand
//    
// S - a man has six fingers 
// T - a man is perpetrator
//
// P(S|¬T) = p0
// P(S|T) = p1,
// P(T|S) = P(S|T)P(T)/P(S)
// P(T) = 1/n
// P(S) = P(S|T)P(T) + P(S|¬T)P(¬T)
//      = p1/n + p0(n-1)/n
// P(T|S) = p1/n/(p1/n + p0(n-1)/n) =
//        = p1/(p1 + p0(n-1)) =
//        = 1/(1 + a(n-1))
//
// (b)
// p0 - probability that an innocent man has six
//      fingers on his right hand
// p1 - probability that the perpetrator has six
//      fingers on his right hand
//    
// S - a man has six fingers 
// T - a man is perpetrator
// N - no one else has six fingers
//
// P(S|¬T) = p0
// P(S|T) = p1
//
// P(S|N) = 1/n
//
// P(T|S,N) = P(S,N|T)P(T)/P(S,N)
//
// P(S,N|T) = P(S|T)P(N|S,T)
// P(N|S,T) if a man has six fingers and is the
// perpetrator what is the probability of him being
// the only one, in that case all other are innocent
// and the probability of having not siz fingers is
// (1 - p0)^(n-1)
// P(S,N|T) = p1(1 - p0)^(n-1)
//
// P(S,N) = P(S,N|T)P(T) + P(S,N|¬T)P(¬T)
// P(S,N|¬T) = P(S|¬T)P(N|S,¬T)
// P(N|S,¬T) is the probability that there is only one
// man with six fingers given that Rugen is with six
// fingers and it is innocent, let Rugen is namba one
// then this is equal to the sum of the probability that
// namba two is the perpetrator * (1 - p0)^(n-2)(1 - p1)
// + ... = (1 - p0)^(n-2)(1 - p1), zo
// P(S,N|¬T) = p0(1 - p0)^(n-2)(1 - p1)
// P(S,N) = p1(1 - p0)^(n-1)(1/n) +
//          p0(1 - p0)^(n-2)(1 - p1)(( n - 1 )/n), and
//
// P(T|S,N) = P(S,N|T)P(T)/P(S,N) =
//  = p1(1 - p0)^(n-1)(1/n)/P(S,N) =
//  = 1/(1 + p0/p1(1 - p1)/(1 - p0)(n - 1)) =
//  = 1/( 1 + ab( n - 1 ))
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
////// Finding Borders                          //////
//////                                          //////
////// A border of a string is a prefix that is //////
////// also a suffix of the string but not the  //////
////// whole string. For example the borders of //////
////// abcababcab are ab and abcab. Your task   //////
////// is to find all border lengths of a given //////
////// string.                                  //////
//////                                          //////
////// [Input]                                  //////
////// The only input line has a string of      //////
////// length n consisting of characters a–z.   //////
//////                                          //////
////// [Output]                                 //////
////// Print all border lengths of the string   //////
////// in increasing order.                     //////
//////                                          //////
////// [Constraints]                            //////
////// 1 <= n <= 1e6                            //////
//////                                          //////
////// [Example]                                //////
////// Input:                                   //////
////// abcababcab                               //////
//////                                          //////
////// Output:                                  //////
////// 2 5                                      //////
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
