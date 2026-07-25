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
# define siz( a ) ((i32) a.size())
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
constexpr i32 N = 2e5; // max nodes
//////////////////////////////////////////////////////
i32 n, k1, k2; // number of vertices, path len range
vector<i32> adj[N + 1]; // adjacency list
//////////////////////////////////////////////////////
void load() {
  n = loads<i32>(); dbg( n );
  tie( k1, k2 ) = loadp<i32>(); dbg2( k1, k2 );
  for( i32 j = n - 1; j > 0; --j ){
    auto [a,b] = loadp<i32>();
    adj[a].push_back( b );
    adj[b].push_back( a );
  }
  dmp( adj, n + 1 );  
}
//////////////////////////////////////////////////////
i32 subs[N + 1]; // sub tree size
bool removed[N + 1]; // centroid decomposition
//////////////////////////////////////////////////////
void dfs_subsize( i32 u, i32 t ){
  subs[u] = 1;
  for( auto v: adj[u] ){
    if( removed[v] or v == t ){ continue; }
    dfs_subsize( v, u );
    subs[u] += subs[v];
  }
}
//////////////////////////////////////////////////////
i32 centroid;                   ////
i32 treesize;                  //// 
i32 halflife;                 ////
//////////////////////////////////////////////////////
bool iscentroid( i32 u, i32 t ){
  if( treesize - subs[u] > halflife ){ return false; }
  for( auto v: adj[u]){
    if( removed[v] or v == t ){ continue; }
    if( subs[v] > halflife ){ return false; }
  }
  return true;
}
//////////////////////////////////////////////////////
void dfs_centroid( i32 u, i32 t ){
  if( iscentroid( u, t )){
    centroid = u;
  } else {
    for( auto v: adj[u]){
      if( removed[v] or v == t ){ continue; }
      dfs_centroid( v, u );
    }
  }
}
//////////////////////////////////////////////////////
i32 find_centroid( i32 u ){
  centroid = 0; // reset( for debugging )
  dfs_subsize( u, 0 );
  treesize = subs[u];
  halflife = treesize / 2;
  dfs_centroid( u, 0 );
  return centroid;
}
//////////////////////////////////////////////////////
//                                  [ The Quiet Side ]
//
//                          The lightsaber -- sleeping.
//                         Vader's helmet falls silent.
//                            Where The Force has gone?
//
//                                             ChatGPT
//
// <> 2.2.14. A body of mass m₁ having velocity υ, has
// hit a resting body of mass m₂ and bounced at right
// angle with respect to the initiali direction. What
// is the velocity of the m₂ body?
//          
//         | m₁u        if we add m₁u and m₂υ₂ as 
//  m₁υ    |            vectors they should be equal 
//  -------+,- - - - -  to m₁υ so we must have:
//           `,
//             `,       (m₂υ₂)² = (m₁υ)² + (m₁u)² = 
//               `,             = m₁²(υ² + u²),
//                 `, m₂υ₂   υ₂ = (m₁/m₂)√(υ² + u²)
//
//////////////////////////////////////////////////////
struct Fenwick { // 1-based
  i32 n;
  vector<i64> tree;

  Fenwick() {}
  Fenwick( i32 n ): n( n ){
    tree.resize( n + 1 );
  }
  void add( i32 k, i64 x ){
    while( k <= n ){
      tree[k] += x;
      k += (k & -k);
    }
  }
  i64 sum( i32 k ){
    i64 s = 0;
    while( k > 0 ){
      s += tree[k];
      k -= (k & -k);
    }
    return s;
  }
  i64 query( i32 a, i32 b ){
    return sum( b ) - sum( a - 1 );
  }
} fenwick;
//////////////////////////////////////////////////////
vector<i32> buckets;
//////////////////////////////////////////////////////
void fill_buckets( i32 u, i32 t, i32 depth ){ // u <- t
  if( depth > k2 ) return;
  if( depth < siz( buckets )){
    ++buckets[ depth ];
  } else {
    buckets.push_back( 1 );
  }
  for( auto v: adj[ u ]){
    if( removed[v] or v == t ) continue;
    fill_buckets( v, u, depth + 1 );
  }
}
//////////////////////////////////////////////////////
i64 count_paths( i32 c ){
  i64 paths = 0;
  vector<i32> total_buckets;
  for( i32 u: adj[c] ){
    if( removed[u] ) continue;
    buckets = { 0 };
    fill_buckets( u, c, 1 );
    dbg2( u, c );
    dbg( buckets );
    // buckets contain frequency count per depth in
    // the range [1,k2]
    i32 B = siz( buckets );

    for( i32 d = 1; d < B; ++d ){
      // count inner-branch paths
      if( d >= k1 and d <= k2 ){
        paths += buckets[d];
      }      
      // count cross-branch paths
      auto f = fenwick.query( k1 - d, k2 - d );
      paths += f * buckets[d];
    }
    // update fenwick
    for( i32 d = 1; d < B; ++d ){
      fenwick.add( d, buckets[d] );
    }
    // copy to total
    if( siz( total_buckets ) < B ){
      total_buckets.resize( B );
    }
    for( i32 d = 1; d < B; ++d ){
      total_buckets[d] += buckets[d];
    }
  }
  // reset fenwick
  for( i32 d = siz( total_buckets ) - 1; d > 0; --d ){
    fenwick.add( d, -total_buckets[d] );
  }
  dbg( fenwick.tree );
  return paths;
}
//////////////////////////////////////////////////////
i64 total = 0; // total paths of len between [k1,k2]
//////////////////////////////////////////////////////
void decompose( i32 u ){
  auto c = find_centroid( u );
  dbg2( u, c );
  total += count_paths( c );
  //
  //
  dbg( total );
  removed[c] = true;
  for( auto v: adj[c] ){
    if( removed[v] ){ continue; }
    decompose( v );
  }
}
//////////////////////////////////////////////////////
void pusk() {
  load();
  fenwick = Fenwick( k2 );
  decompose( 1 );
  cout << total << nl;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//                           [ Arthur Schopensalaten ]
//
//                            Bowl rotates, oil spills,
//                           Onion west, tomatoes east,
//                           Blast! that physics sucks.
//
//                                            DeepSeek
//
// <> 2.2.15. In β-decay a nucleus initialy at rest,
// decays into proton neutron and neutrino. The
// momentum of proton and neutron are p₁ and p₂ and
// the angle between them is α. What is the momentum
// of the neutrino?
//                                 _    _    _
// Again as vectors we chould have p₁ + p₂ + p = 0, zo
// _      _    _
// p = -( p₁ + p₂ ), if we square this we get:
//             _  _
// p² = p₁² + 2p₁.p₂ + p₂², the dot product is equal
// to p₁p₂cosα, zo p = √(p₁² + 2p₁p₂cosα + p₂²)
//
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
////// Fixed-Length Paths II                    //////
//////                                          //////
////// Given a tree of n nodes, your task is to //////
////// count the number of distinct paths that  //////
////// have at least k_1 and at most k_2 edges. //////
//////                                          //////
////// [ Input ]                                //////
////// The first input line contains three      //////
////// integers n, k_1 and k_2: the number of   //////
////// nodes and the path lengths. The nodes    //////
////// are numbered 1,2,...,n.  Then there are  //////
////// n-1 lines describing the edges. Each     //////
////// line contains two integers a and b:      //////
////// there is an edge between nodes a and b.  //////
//////                                          //////
////// [ Output ]                               //////
////// Print one integer: the number of paths.  //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 <= k_1 <= k_2 <= n <= 2e5              //////
////// 1 <= a,b <= n                            //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 5 2 3                                    //////
////// 1 2                                      //////
////// 2 3                                      //////
////// 3 4                                      //////
////// 3 5                                      //////
//////                                          //////
////// Output:                                  //////
////// 6                                        //////
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
