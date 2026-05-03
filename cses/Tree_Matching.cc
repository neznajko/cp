// -*- c-file-style: "gnu" -*-
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// # define DeBug
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
# include <bits/stdc++.h>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////
using  u8 = unsigned char;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using str = string;
using chr = char;
using dbl = double;
////////////////////////////////////////////////////////////////
using vi32 = v<i32>;
using vu32 = v<u32>;
using vi64 = v<i64>;
using vu64 = v<u64>;
using pi32 = p<i32,i32>;
using pu32 = p<u32,u32>;
using pi64 = p<i64,i64>;
using pu64 = p<u64,u64>;
using ei64 = e<i64>;
////////////////////////////////////////////////////////////////
constexpr chr nl = '\n';
constexpr chr sp = ' ';
constexpr chr tab = '\t';
constexpr u64 mod1 = 1'000'000'007;
constexpr i64 inf = 1'000'000'000'000'000;
constexpr i32 mini32 = numeric_limits<i32>::min();
constexpr i32 maxi32 = numeric_limits<i32>::max();
constexpr i64 mini64 = numeric_limits<i64>::min();
constexpr i64 maxi64 = numeric_limits<i64>::max();
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
inline void vrooom() {
    cin.tie( nullptr )->sync_with_stdio( false );
}
////////////////////////////////////////////////////////////////
template <typename K, typename V>
istream& operator>>( istream& is, p<K,V>& p ){
    return is >> p.first >> p.second;
}
////////////////////////////////////////////////////////////////
template <typename T>
istream& operator>>( istream& is, e<T>& t) {
    return is >> get<0>( t ) >> get<1>( t ) >> get<2>( t );
}
////////////////////////////////////////////////////////////////
template <typename T>
istream& operator>>( istream& is, v<T>& v ){
    for( auto& y: v ){ is >> y; }
    return is;
}
////////////////////////////////////////////////////////////////
template <typename T>
inline T loads() {
    T y; cin >> y;
    return y;
}
////////////////////////////////////////////////////////////////
template <typename T>
inline v<T> loadv( u32 n ){
    v<T> y( n ); cin >> y;
    return y;
}
////////////////////////////////////////////////////////////////
template <typename T>
inline w<T> loadt( u32 n, u32 m ){
    w<T> y( n, v<T>( m )); cin >> y;
    return y;
}
////////////////////////////////////////////////////////////////
template <typename T>
inline p<T,T> loadp() {
    p<T,T> y;
    cin >> get<0>( y ) >> get<1>( y );
    return y;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
template <typename C>
auto acc( const C& c ){
    using T = typename C::value_type;
    return accumulate( c.begin(), c.end(), T( 0 ));
}
////////////////////////////////////////////////////////////////
struct {
    str open_bracket;
    str close_bracket;
    str separator;
} CONT{ "[", "]", " " },
  PAIR{ "(", ")", ":" };
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
# define FOR_THE_HORDE auto t = load_scalar<u32>(); while( t-- )
# define loop while( true )
# define psh push_back
# define kpop pop_back
# define emp emplace_back
# define in push_back
# define out pop_front
# define mkp make_pair
# define fst first
# define snd second
# define L lower_bound
# define U upper_bound
# define For( i, begin, end ) for( i64 i = begin; i < end; ++i )
# define Rev( i, end, begin ) for( i64 i = end; i > begin; --i )
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
////////////////////////////////////////////////////////////////
template <typename T>
ostream& operator<<( ostream& os, const e<T>& t );
////////////////////////////////////////////////////////////////
OVERLOAD_OSTREAM_OPERATOR( vector );
OVERLOAD_OSTREAM_OPERATOR( set );
OVERLOAD_OSTREAM_OPERATOR( multiset );
OVERLOAD_OSTREAM_OPERATOR( unordered_map );
OVERLOAD_OSTREAM_OPERATOR( deque );
OVERLOAD_OSTREAM_OPERATOR( unordered_set );
OVERLOAD_OSTREAM_OPERATOR( map );
////////////////////////////////////////////////////////////////
template <typename K, typename V>
ostream& operator<<( ostream& os, const p<K,V>& p ){
    return os << PAIR.open_bracket
              << key( p )
              << PAIR.separator
              << val( p )
              << PAIR.close_bracket;
}
////////////////////////////////////////////////////////////////
template <typename T>
ostream& operator<<( ostream& os, const e<T>& t) {
    return os << "{" << get<0>( t )
              << "," << get<1>( t )
              << "," << get<2>( t )
              << "}";
}
////////////////////////////////////////////////////////////////
#define dmp2(a,b)     cout << a << sp << b << nl;
#define dbg2(a,b)     dbg(a,", ");dbg(b)
#define dbg3(a,b,c)   dbg(a,", ");dbg(b,", ");dbg(c)
#define dbg4(a,b,c,d) dbg(a,", ");dbg(b,", ");dbg(c,", ");dbg(d)
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
enum { BLACK, WHITE, GRAY, RED, BLUE, ORANGE, MAGENTA, BROWN };
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////................
////////////////////////////////////////////////................
////////////////////////////////////////////////................
////////////////////////////////////////////////................
//##############################################################
template <typename T>
ostream& operator<<( ostream& s, const w<T>& mat ){
    for( auto& row: mat ){ s << nl << row; }
    return s;
}
////////////////////////////////////////////////////////////////
#ifdef DeBug
    template<typename T>
    inline void debug( string name, T x, string sep="\n" ){
        cerr << name << " = " << x << sep;
    }
    #define dbg( x, ... ) debug( #x, x, ##__VA_ARGS__ )
#else
    #define dbg( x, ... )
#endif
//##############################################################
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
class Algorithm {
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// u in 1..n
// match[u] # matches
// match[u]  > 0 includes u
// match[u] <= 0 excludes u
//////////////////////////////////////////////////////
private:
  vector<i32> match;
  vector<i32> degree;
  vector<i32> parn;
  
  vector<vector<i32>> adj;
  vector<vector<i32>> chil;

  vector<i32> que;
  i32 front = 0;
  i32  rear = 0;
  ////////////////////////////////////////////////////
  void bld() {
    auto n = loads<i32>();
    //////////////////////////////////////////////////
     match.resize( n + 1 );    
    degree.resize( n + 1 );
      parn.resize( n + 1 );
       adj.resize( n + 1 );
      chil.resize( n + 1 );
       que.resize( n     );
    //////////////////////////////////////////////////
    while( --n ){
      auto [a,b] = loadp<i32>();
      adj[a].psh( b );
      adj[b].psh( a );
    }
    dfs();
  }
  ////////////////////////////////////////////////////
  void dfs() {
    vector<pair<i32,i32>> stk;
    stk.push_back({ 1, 0 }); // root parent
    while( !stk.empty()){
      auto [u,t] = stk.back(); // t -> u -> v
      stk.kpop();
      for( auto v: adj[u] ){
        if( v == t ){ continue; }
        chil[u].push_back( v );
        parn[v] = u;
        stk.push_back({ v, u });
      }
    }
  }
  ////////////////////////////////////////////////////
  void push( i32 u ){
    que[ rear++ ] = u;
  }
  i32 pop() {
    return que[ front++ ];
  }
  void initialize_que() {
    for( i32 u = 1; u < siz( degree ); ++u ){
      degree[u] = siz( chil[u] );
      if( degree[u] == 0 ){
        push( u );
      }
    }
  }
  ////////////////////////////////////////////////////
  void construct_matching( i32 u ){
    bool avail = false;
    i32 tot = 0;
    for( auto v: chil[ u ]){
      if( match[v] > 0 ){
        tot += match[v];
      } else {
        tot -= match[v];
        avail = true;
      }
    }
    if( avail ){
      match[u] = 1 + tot;
    } else {
      match[u] = -tot;
    }
  }
  ////////////////////////////////////////////////////
public:
  void pusk() {
    bld();
    dbg( adj );
    dbg( chil );
    dbg( parn );
    initialize_que();
    dbg( degree );
    dbg3( front, rear, que );
    while( true ){
      auto u = pop();
      construct_matching( u );
      auto p = parn[ u ];
      if( !p ){
        dmp( abs( match[u] ));
        break;
      }
      if( --degree[ p ] == 0 ){
        push( p );
      }
    }
  }
};
///////////////////////////////////////// /  /////////
//////////////////////////////////////// /  //////////
/////////////////////////////////////// /  ///////////
////////////////////////////////////// /  ////////////
int main() {
  vrooom();
  if( 0 ){
  } else { Algorithm().pusk(); }}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Tree Matching
// You are given a tree consisting of n nodes.
// A matching is a set of edges where each node is an endpoint 
// of at most one edge. What is the maximum number of edges in a
// matching?
// [Input] The first input line contains an integer n: the 
// number of nodes. The nodes are numbered 1,2,...,n. Then there 
// are n-1 lines describing the edges. Each line contains two 
// integers a and b: there is an edge between nodes a and b.
// [Output] Print one integer: the maximum number of pairs.
// [Constraints]
// 1 <= n <= 2e5
// 1 <= a,b <= n
// [Example]
// Input:
// 5
// 1 2
// 1 3
// 3 4
// 3 5
// Output:
// 2
// Explanation: One possible matching is (1,2) and (3,4).
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
