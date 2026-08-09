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
// There is a dp formula for calculating Catalan
// numbers but it runs for O(n²). I'm not sure who but
// someone came with a very beautiful idea, 
// representing expression of 2n parenthesis as a walk
// on a 2d nxn grid with ( going up and ) going ryte,
// cos we have n up and n ryte no matter how we choose
// the combinations we'll always end up in the (n,n)
// point, so the total number of paths is C(2n,n) some
// of them thought are not valid like ())... so at the
// moment we detect an extra ) that means that the
// number of ups is one less then the number of rytes
// in the remaining path, so if we flip the remaining
// directions up <-> ryte the resulting paths will
// end up in the point (n+1,n-1), so we can make a
// one to one correspondence of the number of invalid
// paths and all paths in an (n+1,n-1) grid C(2n,n+1),
// zo the number of valid paths is C(2n,n) - C(2n,n+1)
// = C(2n,n)/(n+1)
constexpr i64 MOD = 1e9 + 7;
i64 modexp( i64 x, i64 y ){ // x^y % MOD
  if( y == 0 ) return 1;
  auto z = modexp( x, y/2 );
  auto r = z * z % MOD;
  if( y & 1 ){
    r = r * x % MOD;
  }
  return r;
}
i64 invs( i64 x ){
  return modexp( x, MOD - 2 );
}
vector<i64> getf( i32 n ){
  vector<i64> f( n + 1 );
  f[0] = 1;
  for( i32 i = 1; i <= n; ++i ){
    f[i] = f[i-1] * i % MOD;
  }
  return f;
}
void pusk() {
  auto n = loads<i32>();
  if( !n or n & 1 ){
    cout << 0 << nl;
    return;
  }
  auto f = getf( n );
  i64 i = invs( f[n/2] );
  i64 c = f[n] * i % MOD * i % MOD * invs(n/2 + 1) % MOD;
  cout << c << nl;
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
////// Bracket Sequences I                      //////
//////                                          //////
////// Your task is to calculate the number of  //////
////// valid bracket sequences of length n. For //////
////// example, when n=6, there are 5           //////
////// sequences:                               //////
//////                                          //////
////// ()()()                                   //////
////// ()(())                                   //////
////// (())()                                   //////
////// ((()))                                   //////
////// (()())                                   //////
//////                                          //////
////// Input                                    //////
////// The only input line has an integer n.    //////
//////                                          //////
////// Output                                   //////
////// Print the number of sequences modulo     //////
////// 1e9+7.                                   //////
//////                                          //////
////// Constraints                              //////
////// 1 ≤ n ≤ 1e6                              //////
//////                                          //////
////// Example                                  //////
////// Input:                                   //////
////// 6                                        //////
//////                                          //////
////// Output:                                  //////
////// 5                                        //////
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
