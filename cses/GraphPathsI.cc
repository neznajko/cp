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
// 2.2.29*. A monkey of mass m is balanced by a
// counterweight on pulley A. Pulley A is balanced by
// a load of mass 2m on pulley B. The system is
// initially at rest. How will the load move if the
// monkey starts pulling the rope at a constant speed
// u relative to itself? Neglect the mass of the
// pulleys and friction.
// 
// Initially the system is in balance and the monkey
// starts moving with constant speed, so the cm is
// moving without acceleration, but everything starts
// from 0 so to start rolling there must be some force
// from outside that changes the momentum of the
// system Δp/Δt and this is the puling from B that is
// responsible for thus. [ok] neva mind, with respect
// to A both monkey and m are moving up with u/2 so if
// 2m is having velocity v up then A is having v down
// and in lab system monkey and m are moving with
// u/2 - v up. The subsystems 2m and A are symmetrical
// in the sense that the forces acting on them are 
// same, so the momentum gain 2mv and 2m(u/2 - v) are
// equal from here v = u/4, zo everybody are moving
// with u/4
//////////////////////////////////////////////////////
constexpr i64 MOD = 1e9 + 7;
//////////////////////////////////////////////////////
struct Mat {
  i32 n;
  vector<i64> dat;
  Mat( i32 n = 0 ): n(n) {
    dat.resize( n * n );
  }
  i64& operator()( i32 i, i32 j ){
    return dat[i*n + j];
  }
} I;
Mat operator*( Mat& a, Mat& b ){
  const auto n = a.n;
  Mat c( n );
  for( i32 i = 0; i < n; ++i ){
    for( i32 k = 0; k < n; ++k ){
      i64 aik = a(i,k);
      if( !aik ) continue;
      for( i32 j = 0; j < n; ++j ){
        i64& cij = c(i,j);
        cij = (cij + aik * b(k,j)) % MOD;
      }
    }
  }
  return c;
}
ostream& operator<<( ostream& s, Mat& mat ){
  const auto n = mat.n;
  for( i32 i = 0; i < n; ++i ){
    s << nl;
    for( i32 j = 0; j < n; ++j ){
      s << mat( i, j ) << sp;
    }
  }
  return s;
}
Mat modexp( Mat& x, i32 n ){
  if( !n ) return I;
  auto z = modexp( x, n/2 );
  z = z * z;
  if( n & 1 ) z = z * x;
  return z;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// 7. A hat contains 100 coins, where at least 99 are
// fair, but there may be one that is double headed
// (always landing Heads); if there is no such coin,
// then all 100 are fair. Let D be the event that
// there is such a coin, and suppose that P(D) = 1/2.
// A coin is chosen uniformly at random. The chosen
// coin is flipped 7 times, and it lands Heads all 7
// times.
//
// (a) Given this information, what is the probability
// that one of the coins is double headed?
//
// H - seven heads are flipped
// D - there is a double coin in the hat
//
// P(D|H) = P(H|D)P(D)/P(H)
// P(H|D) is the probability from the prev exercises
// let M is the event the coin is double headed, and
// F fair then,
// P(H|D) = P(H|DM)P(M) + P(H|DF)P(F) =
//        = 1*(1/100) + 1/2⁷*99/100 =
//        = (1 + 99/128)/100 = 227/128*100 = 0.0177
// P(D) = 1/2
// P(H) = P(H|D)P(D) + P(H|¬D)P(¬D),
// P(¬D) = 1/2
// P(H|¬D) = 1/2⁷ = 1/128 = 0.0078, zo
// P(D|H) = 0.0177/(0.0177 + 0.0078) = 0.6938
//
// (b) Given this information, what is the probability
// that the chosen coin is double headed?
// P(M|H) = P(H|M)P(M)/P(H);
// P(H) = (0.0177 + 0.0078)/2 = 0.0128
// P(H|M) = 1
// P(M) = P(M|D)P(D) + P(M|¬D)P(¬D) =
//      = 1/100*1/2 + 0 = 1/200,
// zo P(M|H) = 0.0050/0.0128 = 0.3906
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
void pusk() {
  auto n = loads<i32>(); dbg( n );
  auto m = loads<i32>(); dbg( m );
  auto k = loads<i32>(); dbg( k );

  I = Mat( n );
  for( i32 i = 0; i < n; ++i ){
    I(i,i) = 1;
  }
  dbg( I );

  Mat mat( n );
  while( m-- ){
    auto [a,b] = loadp<i32>();
    ++mat( a - 1, b - 1 );
  }
  dbg( mat );
  mat = modexp( mat, k );
  dbg( mat );
  cout << mat(0,n-1) << nl;
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
////// Graph Paths I                            //////
//////                                          //////
////// Consider a directed graph that has n     //////
////// nodes and m edges. Your task is to count //////
////// the number of paths from node 1 to node  //////
////// n with exactly k edges.                  //////
//////                                          //////
////// [Input]                                  //////
////// The first input line contains three      //////
////// integers n, m and k: the number of nodes //////
////// and edges, and the length of the         //////
////// path. The nodes are numbered 1,2,...,n.  //////
////// Then, there are m lines describing the   //////
////// edges. Each line contains two integers a //////
////// and b: there is an edge from node a to   //////
////// node b.                                  //////
//////                                          //////
////// [Output]                                 //////
////// Print the number of paths modulo 1e9+7.  //////
//////                                          //////
////// [Constraints]                            //////
////// 1 ≤ n ≤ 100                              //////
////// 1 ≤ m ≤ n(n-1)                           //////
////// 1 ≤ k ≤ 1e9                              //////
////// 1 ≤ a,b ≤ n                              //////
//////                                          //////
////// [Example]                                //////
////// Input:                                   //////
////// 3 4 8                                    //////
////// 1 2                                      //////
////// 2 3                                      //////
////// 3 1                                      //////
////// 3 2                                      //////
//////                                          //////
////// Output:                                  //////
////// 2                                        //////
//////                                          //////
////// Explanation: The paths are:              //////
////// 1 → 2 → 3 → 1 → 2 → 3 → 1 → 2 → 3 and    //////
////// 1 → 2 → 3 → 2 → 3 → 2 → 3 → 2 → 3.       //////
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
