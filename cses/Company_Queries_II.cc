// -*- c-file-style: "gnu" -*-
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// # define DeBug
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
////////////////////////////////////////////////////////////////
enum { BLACK, WHITE, GRAY, RED, BLUE, ORANGE, MAGENTA, BROWN };
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
using pint_t = pair<int,int>; // It comes in pints!
//////////////////////////////////////////////////////
struct Algorithm { //
  i32 n, // number of nodes
      q; // number of queries
  void pusk() {                                     
    tie( n, q ) = loadp<i32>();
    bld();
    while( q-- ){
      auto [a,b] = loadp<i32>();
      dmp( query( a, b ));
    }
  }
  // up[u][i] is the 2^i-th ancestor of u
  w<i32> up,
         ch;
  void bld() {
    up.resize( n + 1 );
    ch.resize( n + 1 );
    // fill up[x][0] vith the input
    for( i32 u = 2; u <= n; ++u ){
      auto t = loads<i32>();
      up[u].push_back( t );
      ch[t].push_back( u );
    }
    dbg( ch );
    // levelup the nodes in dfs order this guarantee
    // that children are processed after parents
    dfs();
    dbg( up );
  }
  // Assuming we have the answers to all ancestors of u, 
  // fill the up[u] list, keep in mind that up[1] is 
  // empty so make sure u ain't 1
  void levelup( i32 u ){
    while( u > 1 ){
      // next level
      i32 i = siz( up[ u ]) - 1;
      i32 p = up[u][i];
      // above we can see the familiar binary 
      // lifting pattern cos up[p][i] is 
      // up[up[u][i]][i]
      if( i < siz( up[ p ])){
        up[u].push_back( up[p][ i ]);
      } else { break; }
    }
  }
  // Depth Fyorst Search
  v<i32> depth; // reversed level
  void dfs() {
    depth.resize( n + 1 );
    v<i32> stk( 1, 1 );
    while( !stk.empty( )){
      auto u = stk.back(); stk.kpop();
      levelup( u );
      for( auto v: ch[u] ){
        stk.push_back( v );
        depth[v] = depth[u] + 1;
      }
    }
    dbg( depth );
  }
  //
  i32 query( i32 a, i32 b ){
    dbg2( a, depth[ a ]);
    dbg2( b, depth[ b ]);
    if( depth[a] < depth[ b ]){
      // raise b to a
      b = kth( b, depth[b] - depth[ a ]);
    } else if( depth[a] > depth[ b ]){
      // raise a to b
      a = kth( a, depth[a] - depth[ b ]);
    }
    return lca( a, b );
  }
  static i32 msb( i32 k ){
    return ( 31 - __builtin_clz( k ));
  }
  i32 kth( i32 u, i32 k ){
    while( k ){
      auto i = msb( k );
      if( i < siz( up[ u ])){
        u = up[u][i];
        k -= ( 1 << i );
      } else { return 0; }
    }
    return u;
  }
  i32 lca( i32 a, i32 b ){
    dbg2( a, b );
    if( a == b ){ return a; }
    while( true ){
      i32 i = 0;
      for(; i < siz( up[ a ]); ++i ){
        if( up[a][i] == up[b][i] ){ break; }
      }
      if( i ){
        a = up[a][i - 1];
        b = up[b][i - 1];
      } else { break; }
    }
    return up[a][0];
  }
};
///////////////////////////////////////// /  /////////
//////////////////////////////////////// /  /////////
/////////////////////////////////////// /  /////////
////////////////////////////////////// /  /////////  /
int main() {
  vrooom();
  if( 0 ){
    i32 k = 16;
    dbg2( k, Algorithm::msb( k ));
  } else { Algorithm().pusk(); }}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// Company Queries II
//
// A company has n employees, who form a tree
// hierarchy where each employee has a boss, except
// for the general director.
//
// Your task is to process q queries of the form: who
// is the lowest common boss of employees a and b in
// the hierarchy?
//
// [ Input ]
// The first input line has two integers n and q: the
// number of employees and queries. The employees are
// numbered 1,2,...,n, and employee 1 is the general
// director.
// The next line has n-1 integers e_2,e_3,...,e_n: for
// each employee 2,3,...,n their boss.
// Finally, there are q lines describing the
// queries. Each line has two integers a and b: who is
// the lowest common boss of employees a and b?
//
// [ Output ]
// Print the answer for each query.
//
// [ Constraints ]
// 1 <= n,q <= 2e5
// 1 <= e_i <= i-1
// 1 <= a,b <= n
//
// [ Example ]
// Input:
// 5 3
// 1 1 3 3
// 4 5
// 2 5
// 1 4
//
// Output:
// 3
// 1
// 1
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//
