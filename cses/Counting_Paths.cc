// -*- c-file-style: "gnu" -*-
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
# define DeBug
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
# include <bits/stdc++.h>
//////////////////////////////////////////////////////
using namespace std;
//////////////////////////////////////////////////////
template <typename T>
using v = vector<T>;
template <typename T>
using w = v<v<T>>;
template <typename K, typename V>
using p = pair<K,V>;
template <typename T>
using e = tuple<T,T,T>;
template <typename K, typename V>
using umap = unordered_map<K,V>;
template <typename T>
using uset = unordered_set<T>;
template <typename T>
using mset = multiset<T>;
template <typename T, typename Compare=less<T>>
using maxpq = priority_queue<T, v<T>, Compare>;
template <typename T, typename Compare=greater<T>>
using minpq = priority_queue<T, v<T>, Compare>;
# ifdef __GNUC__
# include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T, typename Compare=less<T>>
using iset = tree<T, null_type, Compare, rb_tree_tag,
                  tree_order_statistics_node_update>;
# define FBO find_by_order
# define OOK order_of_key
# endif
//////////////////////////////////////////////////////
using  u8 = unsigned char;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using str = string;
using chr = char;
using dbl = double;
//////////////////////////////////////////////////////
using vi32 = v<i32>;
using vu32 = v<u32>;
using vi64 = v<i64>;
using vu64 = v<u64>;
using pi32 = p<i32,i32>;
using pu32 = p<u32,u32>;
using pi64 = p<i64,i64>;
using pu64 = p<u64,u64>;
using ei64 = e<i64>;
//////////////////////////////////////////////////////
constexpr chr nl = '\n';
constexpr chr sp = ' ';
constexpr chr tab = '\t';
constexpr u64 mod1 = 1'000'000'007;
constexpr i64 inf = 1'000'000'000'000'000;
constexpr i32 mini32 = numeric_limits<i32>::min();
constexpr i32 maxi32 = numeric_limits<i32>::max();
constexpr i64 mini64 = numeric_limits<i64>::min();
constexpr i64 maxi64 = numeric_limits<i64>::max();
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
inline void vrooom() {
    cin.tie( nullptr )->sync_with_stdio( false );
}
//////////////////////////////////////////////////////
template <typename K, typename V>
istream& operator>>( istream& is, p<K,V>& p ){
    return is >> p.first >> p.second;
}
//////////////////////////////////////////////////////
template <typename T>
istream& operator>>( istream& is, e<T>& t) {
    return is >> get<0>( t ) >> get<1>( t ) >> get<2>( t );
}
//////////////////////////////////////////////////////
template <typename T>
istream& operator>>( istream& is, v<T>& v ){
    for( auto& y: v ){ is >> y; }
    return is;
}
//////////////////////////////////////////////////////
template <typename T>
inline T loads() {
    T y; cin >> y;
    return y;
}
//////////////////////////////////////////////////////
template <typename T>
inline v<T> loadv( u32 n ){
    v<T> y( n ); cin >> y;
    return y;
}
//////////////////////////////////////////////////////
template <typename T>
inline w<T> loadt( u32 n, u32 m ){
    w<T> y( n, v<T>( m )); cin >> y;
    return y;
}
//////////////////////////////////////////////////////
template <typename T>
inline p<T,T> loadp() {
    p<T,T> y;
    cin >> get<0>( y ) >> get<1>( y );
    return y;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
template <typename C>
auto acc( const C& c ){
    using T = typename C::value_type;
    return accumulate( c.begin(), c.end(), T( 0 ));
}
//////////////////////////////////////////////////////
struct {
    str open_bracket;
    str close_bracket;
    str separator;
} CONT{ "[", "]", " " },
  PAIR{ "(", ")", ":" };
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
# define loop while( true )
# define psh push_back
# define posh push_back
# define kpop pop_back
# define emp emplace_back
# define in push_back
# define out pop_front
# define mkp make_pair
# define fst first
# define snd second
# define L lower_bound
# define U upper_bound
# define odd( x ) ((x) & 1)
# define evn( y ) (!odd( y ))
# define sqr( x ) ((x) * (x))
# define all( x ) x.begin(), x.end()
# define siz( y ) (i64) y.size()
# define dmp( y ) cout << y << nl
# define key( p ) p.first
# define val( p ) p.second
# define on( y ) all( y )
////////////////////////////////////////////////////////////////
# define OVERLOAD_OSTREAM_OPERATOR( Container )                \
template <typename... T>                                       \
ostream& operator<<( ostream& os, const Container<T...>& con ){\
    os << CONT.open_bracket;                                   \
    str sep = "";                                              \
    for( const auto& y: con ){                                 \
        os << sep << y;                                        \
        sep = CONT.separator;                                  \
    }                                                          \
    return os << CONT.close_bracket;                           \
}
////////////////////////////////////////////////////////////////
template <typename K, typename V>
ostream& operator<<( ostream& os, const p<K,V>& p );          
//////////////////////////////////////////////////////
template <typename T>
ostream& operator<<( ostream& os, const e<T>& t );
//////////////////////////////////////////////////////
OVERLOAD_OSTREAM_OPERATOR( vector );
OVERLOAD_OSTREAM_OPERATOR( set );
OVERLOAD_OSTREAM_OPERATOR( multiset );
OVERLOAD_OSTREAM_OPERATOR( unordered_map );
OVERLOAD_OSTREAM_OPERATOR( deque );
OVERLOAD_OSTREAM_OPERATOR( unordered_set );
OVERLOAD_OSTREAM_OPERATOR( map );
//////////////////////////////////////////////////////
template <typename K, typename V>
ostream& operator<<( ostream& os, const p<K,V>& p ){
    return os << PAIR.open_bracket
              << key( p )
              << PAIR.separator
              << val( p )
              << PAIR.close_bracket;
}
//////////////////////////////////////////////////////
template <typename T>
ostream& operator<<( ostream& os, const e<T>& t) {
    return os << "{" << get<0>( t )
              << "," << get<1>( t )
              << "," << get<2>( t )
              << "}";
}
//////////////////////////////////////////////////////
#define dmp2(a,b)     cout << a << sp << b << nl;
#define dbg2(a,b)     dbg(a,", ");dbg(b)
#define dbg3(a,b,c)   dbg(a,", ");dbg(b,", ");dbg(c)
#define dbg4(a,b,c,d) dbg(a,", ");dbg(b,", ");dbg(c,", ");dbg(d)
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
enum { BLACK, WHITE, GRAY, RED, BLUE, ORANGE, MAGENTA, BROWN };
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////................
//////////////////////////////////////................
//////////////////////////////////////................
//////////////////////////////////////................
//####################################################
template <typename T>
ostream& operator<<( ostream& s, const w<T>& mat ){
    for( auto& row: mat ){ s << nl << row; }
    return s;
}
//////////////////////////////////////////////////////
# ifdef DeBug
template<typename T>
inline void debug( string name, T x, string sep="\n" ){
  cerr << name << " = " << x << sep;
}
#   define dbg( x, ... ) debug( #x, x, ##__VA_ARGS__ )
# else
#   define dbg( x, ... )
# endif
//####################################################
//////////////////////////////////////////////////////
using paint_t = pair<int,int>; // It comes in paints!
//////////////////////////////////////////////////////
struct RMQ {
  const i32 n;
  const v<i32>& arry;
  RMQ( const v<i32>& arry ): 
    n( siz( arry )), 
    arry( arry )
  {
    bld();
  }
  w<i32> t; // the sparce table!
  // it comes in logs that is t[i][j] is the minimum
  // element's index of subarray of arry starting at
  // j and having length 2^i
  void bld() {
    t.psh({});
    for( i32 j = 0; j < n; ++j ){ t[0].psh( j ); }
    for( i32 i = 1; (1 << i) <= n; ++i ){
      t.psh({});
      for( i32 j = 0; j + (1 << i) <= n; ++j ){
        auto u = t[i-1][j];
        auto v = t[i-1][j + (1 << (i-1))];
        if( arry[u] <= arry[v] ){
          t[i].psh( u );
        } else {
          t[i].psh( v );
        }
      }
    }
  }
  // a and b are 0-based, return k: arry[k] is 
  // minimum in the range [a,b]
  i32 minq( i32 a, i32 b ){
    // 2^i is the maximum length that fits in [a,b]
    i32 i = 31 - __builtin_clz( b - a + 1 );
    //
    b -= (1 << i) - 1;
    i32 u = t[i][a];
    i32 v = t[i][b];
    if( arry[u] <= arry[v] ){
      return u;
    } else {
      return v;
    }
  }
};
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
struct Algorithm {
  //
  i32 n,
      q;
  v<i32> cnt;
  void pusk() {                                     
    tie( n, q ) = loadp<i32>();
    bld();
    RMQ rmq( tour_dep );
    cnt.resize( n + 1 );
    while( q-- ){
      auto [a,b] = loadp<i32>();
      auto c = lca( a, b, rmq );
      auto d = par[c];
      ++cnt[a]; 
      ++cnt[b];
      --cnt[c];
      --cnt[d];
    }
    postfactum( 1, 0 );
    for( i32 i = 1; i <= n; ++i ){
      cout << cnt[i] << sp;
    }
  }
  i32 lca( i32 a, i32 b, RMQ& rmq ){
    a = off[a];
    b = off[b];
    if( a > b ){ swap( a, b );}
    return tour_vtx[ rmq.minq( a, b )];
  }
  w<i32> adj;
  v<i32> dep; 
  v<i32> off; // vertex to offset mapping
  v<i32> par; // parent
  v<i32> tour_vtx;
  v<i32> tour_dep;
  void bld() {
    adj.resize( n + 1 );
    dep.resize( n + 1 );
    off.resize( n + 1 );
    par.resize( n + 1 );
    for( i32 j = 1; j < n; ++j ){
      auto [a,b] = loadp<i32>();
      adj[a].psh( b );
      adj[b].psh( a );
    }
    tour( 1, 0 );
  }
  // let's try normal recursion( NOSTK )
  void tour( i32 u, i32 t ){ // t -> u -> v
    off[ u ] = siz( tour_vtx );
    tour_vtx.psh( u );
    tour_dep.psh( dep[u] );
    for( auto v: adj[ u ]){
      if( v != t ){
        par[v] = u;
        dep[v] = dep[u] + 1;
        tour( v, u );
      }
    }
    off[ t ] = siz( tour_vtx );
    tour_vtx.psh( t );
    tour_dep.psh( dep[t] );
  }
  void postfactum( i32 u, i32 t ){
    for( i32 v: adj[u] ){
      if( v == t ){ continue; }
      postfactum( v, u );
    }
    for( i32 v: adj[u] ){
      if( v == t ){ continue; }
      cnt[u] += cnt[v]; 
    }
  }
};
///////////////////////////////////////// /  /////////
//////////////////////////////////////// /  //////////
/////////////////////////////////////// /  ///////////
////////////////////////////////////// /  ////////////
//
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
int main() {
  vrooom();
  if( 0 ){
    //           0  1  2  3  4  5  6  7
    v<i32> arry{ 6, 1, 5, 3, 2, 8, 4, 3 };
    RMQ rmq( arry );
    dbg( rmq.minq( 3, 6 ));
    dbg( rmq.minq( 0, 1 ));
  } else { Algorithm().pusk(); }}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// Counting Paths
//         
// You are given a tree consisting of n nodes, and m
// paths in the tree.
// Your task is to calculate for each node the number
// of paths containing that node.
//
// Input
//
// The first input line contains integers n and m: the
// number of nodes and paths. The nodes are numbered
// 1,2,...,n.
// 
// Then there are n-1 lines describing the edges. Each
// line contains two integers a and b: there is an
// edge between nodes a and b.
//
// Finally, there are m lines describing the paths.
// Each line contains two integers a and b: there is a
// path between nodes a and b.
//
// Output
//
// Print n integers: for each node 1,2,...,n, the
// number of paths containing that node.
//
// Constraints
// 1 <= n, m <= 2e5
// 1 <= a,b <= n
// 
// Example
// Input:
// 5 3
// 1 2
// 1 3
// 3 4
// 3 5
// 1 3
// 2 5
// 1 4
// 
// Output:
// 3 1 3 1 1 
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// log:
