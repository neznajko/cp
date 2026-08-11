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
// n = 3, s = (()    
//
// 3 +   +   +   +   x = 1
//                   y = 2
// 2 +---+   +   +
//   |               x = n - x = 2
// 1 +   +   +   +   y = n - y = 1
//   |            
// 0 +   +   +   +   C(x+y,x) - C(x+y,x+1) =
//   0   1   2   3   C(3,2) - C(3,3) = 3 - 1 = 2
//
//   C(x+y,x) = (x+y)!/x!y!
// C(x+y,x+1) = (x+y)!/(x+1)!(y-1)! = 
//            = y(x+y)!/(x+1)x!y(y-1)! =
//            = [y/(x+1)][(x+y)!/x!y!]
//            = [y/(x+1)]C(x+y,x)
// C(x+y,x) - C(x+y,x+1) = C(x+y,x)[1 - y/(x+1)] =
// = C(x+y,x)[x + 1 - y]/(x+1)
//////////////////////////////////////////////////////
constexpr i64 MOD = 1e9 + 7;
vector<i64> f;
//////////////////////////////////////////////////////
i64 modexp( i64 x, i64 y ){ // x ^ y % MOD
  if( !y ) return 1;
  i64 z = modexp( x, y/2 );
  z = z * z % MOD;
  if( y & 1 ) z = z * x % MOD;
  return z;
}
//////////////////////////////////////////////////////
i64 invs( i64 x ){
  return modexp( x, MOD - 2 );
}
//////////////////////////////////////////////////////
void bldf( i32 n ){
  f.resize( n + 1 );
  f[0] = 1;
  for( i32 i = 1; i <= n; ++i ){
    f[i] = f[i-1] * i % MOD;
  }
}
//////////////////////////////////////////////////////
i64 C( i32 n, i32 k ){
  return f[n] * invs(f[k]) % MOD * invs(f[n-k]) % MOD;
}
//////////////////////////////////////////////////////
pair<i32,i32> getxy( const string& s ){
  i32 x = 0;
  i32 y = 0;
  for( char c: s ){
    if( c == '(' ){
      ++y;
    } else {
      ++x;
    }
    if( x > y ) return { -1, -1 }; 
  }
  return { x, y };
}
//////////////////////////////////////////////////////
// 2.2.26*. Three point masses m₁, m₂, m₃ are
// connected by strings of length l and rotate with
// angular velocity ω about their center of mass,
// maintaining the configuration of an equilateral
// triangle. Find the tension in each of the strings.
//
// Let's put ORIG at m₁, then as vectors we have for
//          the cm: y₁ = (m₂l₂ + m₃l₃)/m, where m is
//    m₂    the sum of the masses, again as vectors we
//          can write T₂ + T₃ = m₁ω²y₁, T₂ and T₃ are
// m₁    m₃ directed alongside l₂ and l₃ respectively,
//          we can write the above vector equation as
// a projections parallel and perpendicular to y₁, for
// this we need expressions for sin and cos of the
// angles between y₁ and l₂ and l₃; we can use the dot
// product:
// y₁.l₂ = |y₁|lcosβ = (m₂l₂.l₂ + m₃l₃.l₂)/m
// y₁.l₃ = |y₁|lcosγ = (m₂l₂.l₃ + m₃l₃.l₃)/m
// l₂.l₂ = l₃.l₃ = l²
// l₃.l₂ = l₂.l₃ = l²/2( cos60° = 1/2 )
// |y₁| = √(y₁.y₁) = (l/m)√(m₂² + m₂m₃ + m₃²) =: lQ/m
// Q = √(m₂² + m₂m₃ + m₃²)
// l²Qcosβ/m = l²(m₂ + m₃/2)/m,
// Qcosβ = m₂ + m₃/2
// Q²cos²β = Q²(1 - sin²β) = m₂² + m₂m₃ + m₃²/4,
// m₂² + m₂m₃ + m₃² - m₂² - m₂m₃ - m₃²/4 = Q²sin²β
// Q²sin²β = 3m₃²/4
// Qsinβ = √3m₃/2
//
// Qcosβ = m₂ + m₃/2
// Qsinβ = √3m₃/2, for γ we have to swap 2 and 3
//
// Qcosγ = m₂/2 + m₃
// Qsinγ = √3m₂/2
//
// now T₂ + T₃ = m₁ω²y₁ splits into:
//
// |T₂|cosβ + |T₃|cosγ = m₁ω²lQ/m
// |T₂|sinβ = |T₃|sinγ, last equation gives
//
// |T₂|m₃ = |T₃|m₂, fyorst equation should look like:
// |T₂|(m₂ + m₃/2) + |T₃|(m₂/2 + m₃) = m₁ω²lQ²/m =
// |T₂|(m₂ + m₃/2 + (m₃/m₂)(m₂/2 + m₃)) =
// |T₂|(m₂ + m₃/2 + m₃/2 + m₃²/m₂)) =
// |T₂|(m₂² + m₂m₃ + m₃²)/m₂ = = m₁ω²lQ²/m,
// |T₂| = m₁m₂ω²l/(m₁ + m₂ + m₃), so in general the
// tension force between masses i and j is
// Tᵢⱼ = mᵢmⱼω²l/(m₁ + m₂ + m₃)
//////////////////////////////////////////////////////
void pusk() {
  auto n = loads<i32>(); dbg( n );
  if( !n or n & 1 ){
    cout << 0 << nl;
    return;
  }
  auto s = loads<string>(); dbg( s );
  auto [x,y] = getxy( s );
  if( x < 0 ){
    cout << 0 << nl;
    return;
  }
  n /= 2;
  x = n - x;
  y = n - y;
  if( x < y ){
    cout << 0 << nl;
    return;
  }
  dbg2( x, y );
  bldf( x + y );
  dbg( f );
  // C(x+y,x)[x + 1 - y]/(x+1)
  i64 A = C( x + y, x );
  i64 B = x + 1 - y;
  i64 D = x + 1;
  i64 r = A * B % MOD * invs( D ) % MOD;
  cout << r << nl;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// 2. A woman is pregnant with twin boys. Twins may be
// either identical or fraternal. Suppose that 1/3 of
// twins born are identical, that identical twins have
// a 50% chance of being both boys and a 50% chance of
// being both girls, and that for fraternal twins each
// twin independently has a 50% chance of being a boy
// and a 50% chance of being a girl. Given the above
// information, what is the probability that the
// woman’s twins are identical?
//
// I - twins are identical
// F - fraternal
// B - boy
// G - girl
//
// P(I) = 1/3, P(F) = 2/3
// P(I|BB) = ?
// P(I|BB) = P(BB|I)P(I)/P(BB)
// P(BB|I) = 1/2
// P(BB) = P(BB|I)P(I) + P(BB|F)P(F)
// P(BB|F) = 1/4
// P(BB) = (1/2)(1/3) + (1/4)(2/3) = 1/3
// P(I|BB) = (1/2)(1/3)/(1/3) = 1/2
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
////// Bracket Sequences II                     //////
//////                                          //////
////// Your task is to calculate the number of  //////
////// valid bracket sequences of length n when //////
////// a prefix of the sequence is given.       //////
//////                                          //////
////// [ Input ]                                //////
////// The first input line has an integer n.   //////
////// The second line has a string of k        //////
////// characters: the prefix of the sequence.  //////
//////                                          //////
////// [ Output ]                               //////
////// Print the number of sequences modulo     //////
////// 1e9+7.                                   //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 ≤ k ≤ n ≤ 1e6                          //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 6                                        //////
////// (()                                      //////
//////                                          //////
////// Output:                                  //////
////// 2                                        //////
//////                                          //////
////// Explanation: There are two possible      //////
////// sequences: (())() and (()()).            //////
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
