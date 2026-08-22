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
u64 inf = 1e19;
//////////////////////////////////////////////////////
struct Mat {
  i32 n;
  vector<u64> dat;
  
  Mat( i32 n, u64 init = 0 ): n( n ){
    dat.resize( n * n, init );
  }
  i32 getoff( i32 i, i32 j ) const {
    return i * n + j;
  }
  u64 operator()( i32 i, i32 j ) const {
    return dat[ getoff( i, j )];
  }
  u64& operator()( i32 i, i32 j ){
    return dat[ getoff( i, j )];
  }
};
//////////////////////////////////////////////////////
ostream& operator<<( ostream& s, const Mat& mat ){
  for( i32 i = 0; i < mat.n; ++i ){
    s << nl;
    for( i32 j = 0; j < mat.n; ++j ){
      s << mat( i, j ) << sp;
    }
  }
  return s;
}
//////////////////////////////////////////////////////
Mat operator*( Mat& a, Mat& b ){
  const auto n = a.n;
  Mat c( n, inf );
  
  for( i32 i = 0; i < n; ++i ){
    for( i32 k = 0; k < n; ++k ){
      const auto aik = a(i,k);
      if( aik == inf ) continue;
      for( i32 j = 0; j < n; ++j ){
        c(i,j) = min( c(i,j), aik + b(k,j));
      }}}
  return c;
}
//////////////////////////////////////////////////////
Mat modexp( Mat& x, i32 n ){
  if( n == 1 ) return x;
  auto z = modexp( x, n/2 );
  z = z * z;
  if( n & 1 ) z = z * x;
  return z;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// 2.2.30. A small box filled with sand hangs from a
// cord. Bullets flying horizontally with velocity υ
// become embedded in the sand. The mass of a bullet
// m₁ is much smaller than the mass of the box m₂. The
// cord is deflected from the vertical by an angle
// α. How many bullets hit the sand per unit time?
//
// Let T is the pulling from the rope when sand box is
// at angle α. Then:
//
// Tcosα = m₂g
// Tsinα = F = Δp/Δt = (ΔN/Δt)m₁υ, so
// (ΔN/Δt)m₁υ
// ---------- = tgα, (ΔN/Δt) = m₂gtgα/m₁υ
//     m₂g
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
void pusk() {
  auto n = loads<i32>(); dbg( n ); // [1,100]
  auto m = loads<i32>(); dbg( m ); // [1,9900]
  auto k = loads<i32>(); dbg( k ); // [1,1e9]

  Mat mat( n, inf );

  while( m-- ){
    auto [a,b] = loadp<i32>();
    auto c = loads<u64>(); // [1,1e9]
    if( mat(--a,--b) > c ) mat(a,b) = c;
  }
  dbg( mat );
  
  auto x = modexp( mat, k );
  dbg( x );
  if( x(0,n-1) < inf ){
    cout << x(0,n-1) << nl;
  } else {
    cout << -1 << nl;
  }
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// 8. The screens used for a certain type of cell
// phone are manufactured by 3 companies, A, B, and C.
// The proportions of screens supplied by A, B, and C
// are 0.5, 0.3, and 0.2, respectively, and their
// screens are defective with probabilities 0.01, 0.02,
// and 0.03, respectively. Given that the screen on
// such a phone is defective, what is the probability
// that Company A manufactured it?
//
// P(A|D) = P(D|A)P(A)/P(D),
// P(A) = 0.5
// P(D|A) = 0.01
// P(D) = P(D|A)P(A) + P(D|B)P(B) + P(D|C)P(C) =
//      = 0.01*0.5 + 0.02*0.3 + 0.03*0.2 = 0.017
// P(A|D) = 0.005/0.017 = .2941
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
////// Graph Paths II                           //////
//////                                          //////
////// Consider a directed weighted graph       //////
////// having n nodes and m edges. Your task is //////
////// to calculate the minimum path length     //////
////// from node 1 to node n with exactly k     //////
////// edges.                                   //////
//////                                          //////
////// [Input]                                  //////
////// The first input line contains three      //////
////// integers n, m and k: the number of nodes //////
////// and edges, and the length of the path.   //////
////// The nodes are numbered 1,2,...,n. Then,  //////
////// there are m lines describing the edges.  //////
////// Each line contains three integers a, b   //////
////// and c: there is an edge from node a to   //////
////// node b with weight c.                    //////
//////                                          //////
////// [Output]                                 //////
////// Print the minimum path length. If there  //////
////// are no such paths, print -1.             //////
//////                                          //////
////// [Constraints]                            //////
////// 1 ≤ n ≤ 100                              //////
////// 1 ≤ m ≤ n(n-1)                           //////
////// 1 ≤ k ≤ 1e9                              //////
////// 1 ≤ a,b ≤ n                              //////
////// 1 ≤ c ≤ 1e9                              //////
//////                                          //////
////// [Example]                                //////
////// Input:                                   //////
////// 3 4 8                                    //////
////// 1 2 5                                    //////
////// 2 3 4                                    //////
////// 3 1 1                                    //////
////// 3 2 2                                    //////
//////                                          //////
////// Output:                                  //////
////// 27                                       //////
//////////////////////////////////////////////////////
///////////////////////////////////////////########///
///////////////////////////////////////////########///
///////////////////////////////////////////########///
// log:                                    ########
//                                         ### ####
//                                        ###  ### 
//                                       ##   ##   
//                                       #     #
