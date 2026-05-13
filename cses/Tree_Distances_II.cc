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
struct Algorithm {
  ////////////////////////////////////////////////////
  ////////////////////////////////////////////////////
  // 1) Bld tree graph adj list
  i32 n; // number of vertices
  w<i32> adj;
  void pusk() {                                     
    n = loads<i32>(); 
    adj.resize( n + 1 ); // 1-based indexing
    // read the n - 1 edges
    for( auto j = n - 1; j > 0; --j ){
      auto [a,b] = loadp<i32>(); // voila
      // put in adj
      adj[a].posh( b );
      adj[b].posh( a );
      // Betveen psh and posh push_back vins
      //                              -- back_inserter
    }
    dbg( adj ); // make sure
    bld(); 
    ltr(); // leaf to a rooot
    rtl(); // roooot to a leeaaf
    tcpdump();
  }
  // 2) Bld a tree rooted at 1
  w<i32> chld;
  v<i32> prnt;
  using paint_t = pair<int,int>; // comes in paints
  void bld() {
    chld.resize( n + 1 );
    prnt.resize( n + 1 );
    i32 t = 0; // t -> u -> v -> w
    i32 u = 1; 
    v<paint_t> stk( 1, { t, u });
    while( !stk.empty()){
      tie( t, u ) = stk.back(); stk.kpop();
      // k pop is the best         -- unkonwn pop star
      for( auto v: adj[u] ){
        if( v == t ){ continue; }
        chld[u].psh( v );
        prnt[v] = u;
        stk.psh({ u, v });
      }
    }
    dbg2( chld, prnt );
  }
  // From leaves to root direction get the path sums
  // passing thru the children nodes, thats point 3)
  v<i64> tot; // total path length
  v<i32> desc; // descendent
  void ltr() {
    // Plan of Campaign( very simple )
    // 1) neva use queue if you can use a stack
    // 2) fill the stack with leaves 
    // 3) use degrees for topsorting
    // 4) make it happen
    tot.resize( n + 1 );
    desc.resize( n + 1, 1 ); // including the root
    v<i32> deg( n + 1 );
    v<i32> stk;
    for( i32 u = 1; u <= n; ++u ){
      if( !siz( chld[ u ])){
        stk.push_back( u );
      } else {
        deg[ u ] = siz( chld[ u ]);
      }
    }
    dbg( deg );
    dbg( stk );
    while( true ){
      auto u = stk.back(); stk.kpop();
      for( auto v: chld[ u ]){
        tot[ u ] += ( desc[ v ] + tot[ v ]);
        desc[ u ] += desc[ v ];
      }
      if( u == 1 ){ break; }
      auto t = prnt[ u ];
      if( --deg[ t ] == 0 ){ stk.psh( t ); }
    }
    dbg( tot );
    dbg( desc );
  }
  ////////////////////////////////////////////////////
  // 6 9 5 8 8
  v<i64> anc; // ancestor [ensista]
  void rtl() {
    v<i32> stk;
    for( auto v: chld[ 1 ]){
      stk.psh( v );
    }
    dbg( stk );
    anc.resize( n + 1 ); // excluding the root
    while( !stk.empty()){
      auto u = stk.back(); stk.kpop();
      auto t = prnt[ u ];
      // Welcome to the brand new dirty chess tricks
      // series against Sicilian ...
      anc[u] = desc[t] - desc[u] + anc[t];
      // parent: t
      // chil u contribution: desc[u] + tot[u]
      // smth like:
      // tot[u] += tot[t] - desc[u] - tot[u] + anc[u]
      tot[u] = tot[t] - desc[u] + anc[u];
      for( auto v: chld[ u ]){
        stk.posh( v );
      }
    }
    dbg( anc );
    dbg( tot );
  }
  void tcpdump() {
      for( i32 u = 1; u <= n; ++u ){
          cout << tot[u] << sp;
      }
  }
  ////////////////////////////////////////////////////
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
// Tree Distances II
////////////////////////////////////////////////////////////////
// Time limit: 1.00 s
// Memory limit: 512 MB
////////////////////////////////////////////////////////////////
// You are given a tree consisting of n nodes. Your task is to 
// determine for each node the sum of the distances from the 
// node to all other nodes.
////////////////////////////////////////////////////////////////
// [ Input ]
// The first input line contains an integer n: the number of 
// nodes. The nodes are numbered 1,2,...,n.
// Then there are n-1 lines describing the edges. Each line 
// contains two integers a and b: there is an edge between nodes 
// a and b.
////////////////////////////////////////////////////////////////
// [ Output ]
// Print n integers: for each node 1,2,...,n, the sum of the 
// distances.
////////////////////////////////////////////////////////////////
// [ Constraints ]
// 1 <= n <= 2e5
// 1 <= a,b <= n
////////////////////////////////////////////////////////////////
// [ Example ]
// Input:
// 5
// 1 2
// 1 3
// 3 4
// 3 5
// Output:
// 6 9 5 8 8
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
