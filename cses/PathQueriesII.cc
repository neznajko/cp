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
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
constexpr i32 CAP = 200001;
i32 n, q;
i32 value[CAP];
vector<i32> adj[CAP];
// ---------------------------------------------------
i32 depth[CAP];  //
i32 trailoff[CAP]; // vtx to offset mapping
vector<i32> vtrail; // vertex trail
vector<i32> dtrail; // depth trail
// ---------------------------------------------------
vector<i32> st[CAP + CAP]; // sparse table
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
i32 subs[CAP]; // subsize
vector<i32> hld; // heavy light decomposition
i32 pathid = 0;
i32 path[CAP]; // vertex to path mapping
i32 parent[CAP];
vector<i32> orig;
// ###################################################
// 2.1.59. A body of mass m, attached to an axis by a
// spring of stiffness k, moves around the axis along
// a circle of radius R with angular velocity ω. Find
// the length of the spring when it is not deformed.
//
// R0 - undeformed length
// k( R - R0 ) = m(w^2)R
// R( 1 - (m/k)w^2 ) = R0
//
namespace rmq {
  i32 N; // 2n
  i32 minoff( i32 l, i32 r ){
    return (dtrail[r] < dtrail[l]) ? r : l;
  }  
  void bld() {
    N = dtrail.size();
    for( i32 j = 0; j < N; ++j ){
      st[j].push_back( j );
    }
    for( i32 w = 1; 2*w <= N; w *= 2 ){
      for( i32 j = 0; j + 2*w <= N; ++j ){
        auto l = st[j].back();
        auto r = st[j + w].back();
        st[j].push_back( minoff( l, r ));
      }
    }
  }  
  // 0-based, what is the min value in [a,b]
  i32 make_query( i32 a, i32 b ){
    // get the maximum power of 2 that fits the lenght
    // of the [a,b] interval
    i32 w = 31 - __builtin_clz( b - a + 1 );
    // 2^w is the lenght, but we need the offset w
    auto l = st[a][w];
    auto r = st[b - (1 << w) + 1][w];
    return minoff( l, r ); 
  }
}
// ###################################################
// 2.1.60*. A thin elastic cord (rubber band) of mass
// m and stiffness k is formed into a ring of radius
// R0. The ring is then spun about its axis. Find the
// new radius of the ring if its angular velocity is ω.
//
//          dm            (dm)(w^2)R = 2fsin(da/2) =
//       . #####,         = fda;
// f , `   `   `  ` .  f  
// `       `   `          dm = m(ds)/2(pi)R = mRda/2(pi)R
//          ` `           dm = mda/2pi
//          ` `
//          ` `           f = k2pi(R - R0)
//           ` da         mda/2pi * w^2 * R = k2pi(R-R0)da
//           `            mw^2R/2pi = k2pi(R-R0)
//                        mw^2R/k4pi^2 = R - R0
//                        R = R0/( 1 - mw^2/k4pi^2 )
namespace lca {
  void push( i32 u ){
    trailoff[u] = vtrail.size();
    vtrail.push_back( u );
    dtrail.push_back( depth[u] );    
  }
  void dfs( i32 u, i32 t ){
    depth[u] = depth[t] + 1;
    push( u );
    for( auto v: adj[u] ){
      if( v == t ){ continue; }
      dfs( v, u );
    }
    push( t );
  }
  void bld(){
    depth[0] = -1;
    dfs( 1, 0 );
  }
  i32 make_query( i32 a, i32 b ){
    a = trailoff[a];
    b = trailoff[b];
    if( b < a ){ swap( a, b ); }
    auto k = rmq::make_query( a, b );
    dbg( k );
    return vtrail[k];
  }
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void dfs( i32 u, i32 t ){
  for( auto v: adj[u]) {
    if( v == t ){ continue; }
    parent[v] = u;
    dfs( v, u );
    subs[u] += subs[v];
  }
}
bool isleaf( i32 u ){
  return u > 1 and (adj[u].size() == 1);
}
bool isorig = true;
void hld_dfs( i32 u, i32 t ){
  if( isorig ){
    orig.push_back( u );
    isorig = false;
  }
  path[u] = pathid;
  hld.push_back( u );
  if( isleaf( u )){
    ++pathid;
    isorig = true;
  } else {
    for( auto v: adj[u]) {
      if( v != t ){
        hld_dfs( v, u );
      }
    }
  }
}
void sort_adj() {
  i32 u = n;
  do {
    sort( on( adj[ u ]), []( i32 a, i32 b ){
      return (subs[a] > subs[b]);
    });
  } while( --u );
}
void bld() {
  for( auto k = 1; k <= n; ++k ){
    subs[k] = 1;
  }
  dfs( 1, 0 );
  dmp( subs, n + 1 );
  dmp( parent, n + 1 );
  sort_adj();
  dmp( adj, n + 1 );
  hld_dfs( 1, 0 );
  dbg( hld );
  dmp( path, n + 1 );
  dbg( orig );
}
// ===================================================
struct Segment { // maximum
  static bool ryte( i32 b ){ return b & 1; }
  static bool left( i32 a ){ return !ryte( a ); }
  i32 n; 
  vector<i32> tree; // SE GU ME N TO
  i32 f[CAP]; // vertex to offset mapping
  Segment() {}
  void cons() {
    n = ::n; // shadow copy
    // make n power of 2
    if( n & (n - 1)){
      n = 1 << (32 - __builtin_clz( n ));
    }
    // initialize mapping
    // initialize base segments
    tree.resize( n + n );
    for( i32 j = 0; j < ::n; ++j ){
      f[hld[j]] = n + j;
      tree[n + j] = value[hld[j]];
    }
    for( i32 j = 2*n - 1; j > 1; j -= 2 ){
      tree[j/2] = max( tree[j], tree[j - 1]);
    }
    dbg( tree );
    dmp( f, n + 1 );
  }
  // update query
  void updateq( i32 s, i32 x ){
    i32 j = f[s];
    tree[j] = x;
    for( j /= 2; j > 0; j /= 2 ){
      tree[j] = max( tree[2*j], tree[2*j + 1]);
    }
    dbg( tree );
  }
  // range query
  i32 maxq( i32 a, i32 b ){
    i32 m = 0;
    a = f[a];
    b = f[b];
    if( b < a ){ swap( a, b); }
    while( a <= b ){
      if( ryte( a )){ m = max( m, tree[ a++ ]); }
      if( left( b )){ m = max( m, tree[ b-- ]); }
      a /= 2;
      b /= 2;
    }
    return m;
  }
} seg;
// +++++++++++++++++++++++++++++++++++++++++++++++++++
void updateq( i32 s, i32 x ){
  seg.updateq( s, x );
}
i32 getmax( i32 a, i32 c ){ // c is lca
  i32 m = 0;
  auto q = path[ c ];
  while( true ){
    auto p = path[ a ];
    if( p == q ){
      return max( m, seg.maxq( a, c ));
    } else {
      auto b = orig[ p ];
      m = max( m, seg.maxq( a, b ));
      a = parent[b];
    }
  }
  return m;
}
i32 maxq( i32 a, i32 b ){
  auto c = lca::make_query( a, b );
  return max( getmax( a, c ), getmax( b, c ));
}
// ///////////////////////////////////////////////////
void pusk() {
  tie( n, q ) = loadp<i32>(); dbg2( n, q );
  for( i32 k = 1; k <= n; ++k ){
    cin >> value[k];
  }
  for( i32 j = 1; j < n; ++j ){ // n - 1
    auto [a,b] = loadp<i32>();
    adj[a].push_back( b );
    adj[b].push_back( a );
  }
  dmp( value, n + 1 );
  dmp( adj, n + 1 );
  //
  lca::bld();
  dmp( depth, n + 1 );
  dbg( vtrail );
  dbg( dtrail );
  dmp( trailoff, n + 1 );
  rmq::bld();
  bld();
  //
  seg.cons();
  //
  for( i32 j = 0; j < q; ++j ){
    auto t = loads<i32>();
    if( t == 1 ){
      auto [s,x] = loadp<i32>(); dbg2( s, x );
      updateq( s, x );
    } else {
      auto [a,b] = loadp<i32>(); dbg2( a, b );
      cout << maxq( a, b ) << sp;
    }
  }
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
//////             Path Queries II              //////
////// You are given a tree consisting of n     //////
////// nodes. The nodes are numbered 1,2,..,n.  //////
////// Each node has a value. Your task is to   //////
////// process following types of queries:      //////
//////                                          //////
////// 1 change the value of node s to x        //////
////// 2 find the maximum value on the path     //////
//////   between nodes a and b.                 //////
//////                                          //////
////// [ Input ]                                //////
////// The first input line contains two        //////
////// integers n and q: the number of nodes    //////
////// and queries. The nodes are numbered      //////
////// 1,2,..,n. The next line has n integers   //////
////// v_1,v_2,..,v_n: the value of each node.  //////
////// Then there are n-1 lines describing the  //////
////// edges. Each line contains two integers a //////
////// and b: there is an edge between nodes a  //////
////// and b. Finally, there are q lines        //////
////// describing the queries. Each query is    //////
////// either of the form "1 s x" or "2 a b".   //////
//////                                          //////
////// [ Output ]                               //////
////// Print the answer to each query of type 2 //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 <= n, q <= 2e5                         //////
////// 1 <= a,b, s <= n                         //////
////// 1 <= v_i, x <= 1e9                       //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 5 3                                      //////
////// 2 4 1 3 3                                //////
////// 1 2                                      //////
////// 1 3                                      //////
////// 2 4                                      //////
////// 2 5                                      //////
////// 2 3 5                                    //////
////// 1 2 2                                    //////
////// 2 3 5                                    //////
//////                                          //////
////// Output:                                  //////
////// 4 3                                      //////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// log: Yeah I won't be surprised if there is some
// solution smth like 35 characters in python:) but
// what I did looks like a diploma thesis:) man I feel
// stupid never mind, by the way one problem that I've
// solved before <Missing Coin Sum Queries> in a kinda
// unorthodox way, and was very happy that it has
// passed all 11 cases now suddenly from nowhere a 12
// test case has popped out that my solution is not
// passing; I mean wtf thats not fair, never mind I
// guess the lesson is: Don't brag!
