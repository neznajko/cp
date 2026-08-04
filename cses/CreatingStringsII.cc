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
constexpr i64 MOD = 1e9 + 7;
constexpr i32 MAXN = 1e6;
vector<i64> f( MAXN + 1 ); // factorials
vector<i64> i( MAXN + 1 ); // inverse factorials
i64 modexp( i64 x, i64 y ){ // x^y % MOD
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
  f[1] = i[1] = 1;
  for( i32 j = 2; j <= MAXN; ++j ){
    f[j] = f[j-1] * j % MOD;
    i[j] = inv( f[j] );
  }
}
void pusk() {
  bld();
  auto s = loads<string>(); dbg( s );
  i32 n = siz( s ); dbg( n );
  vector<i32> fq( 'z' + 1 - 'a' );
  for( auto c: s ){
    ++fq[ c - 'a' ];
  }
  dbg( fq );
  i64 count = f[ n ];
  for( auto MHz: fq ){
    if( MHz ){
      count = count * i[ MHz ] % MOD;
    }
  }
  cout << count << nl;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//                                         [ Arcsway ]
//
//                                 No up, neither down,
//                        just the gentle, steady pull
//                                  of a turning dream.
//
//                                       ディープシーク
//
// 2.2.23. To create artificial gravity, two modules
// of an orbital station (with a mass ratio of 1 : 2)
// were separated to a distance R from each other and
// spun around their common center of mass. Determine
// the period of complete revolution of the modules
// if, in the more massive module, the artificial
// gravity is two times less than the gravity on
// Earth.
//
// A----C--------B at point A we have the 2m module,
// the ratio AC/CB is the opposite of the mass ratio,
// zo Y := AC = R/3, the acceleration of A is a = ω²Y
// = g/2, zo ω = √(3g/2R) the period T is equal to:
// T = 2π/ω = 2π√(2R/3g)
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
////// Creating Strings II                      //////
//////                                          //////
////// Given a string, your task is to          //////
////// calculate the number of different        //////
////// strings that can be created using its    //////
////// characters.                              //////
//////                                          //////
////// [ Input ]                                //////
////// The only input line has a string of      //////
////// length n. Each character is between a–z. //////
//////                                          //////
////// [ Output ]                               //////
////// Print the number of different strings    //////
////// modulo 1e9+7.                            //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 <= n <= 1e6                            //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// aabac                                    //////
//////                                          //////
////// Output:                                  //////
////// 20                                       //////
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
