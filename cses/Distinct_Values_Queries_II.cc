// -*- c-file-style: "gnu" -*-
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//# define DeBug
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
inline T load_scalar() {
    T y; cin >> y;
    return y;
}
////////////////////////////////////////////////////////////////
template <typename T>
inline v<T> load_vector( u32 n ){
    v<T> y( n ); cin >> y;
    return y;
}
////////////////////////////////////////////////////////////////
template <typename T>
inline w<T> load_tensor( u32 n, u32 m ){
    w<T> y( n, v<T>( m )); cin >> y;
    return y;
}
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
} CONT{ "[", "]", "," },
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
#ifdef DeBug
    template<typename T>
    inline void debug( string name, T x, string sep="\n" ){
        cerr << name << " = " << x << sep;
    }
    #define dbg( x, ... ) debug( #x, x, ##__VA_ARGS__ )
#else
    #define dbg( x, ... )
#endif
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
////////////////////////////////////////////////////////////////
struct Node {
  bool reps = false;
  i32  prev = -1;
  i32  left = -1;
  i32  ryte = -1;
  bool isnil() const { return left < 0; }
  static Node nil() { return {}; }
};
////////////////////////////////////////////////////////////////
ostream& operator<<( ostream& s, const Node& p ){
  return s << "{"
           << p.reps << "'"
           << p.prev << "'"
           << p.left << "'"
           << p.ryte << "}";
}
////////////////////////////////////////////////////////////////
class Algorithm { 
private:
  i32 n, m;
  vi32 h;
  v<tuple<i32,i32,i32>> q;

  v<pi32> g;

  v<set<i32>> p;
  v<Node> t;

  i32 rename() {
    sort( on( g )); dbg( g );
    i32 nick = 0;
    i32 last = 0;
    for( const auto[ name, j ]: g ){
      if( name != last ){ ++nick; }
      if( j < 0 ){
        get<2>( q[-j - 1] ) = nick;
      } else {
        h[j] = nick;
      }
      last = name;
    }
    dbg( h );
    dbg( q );
    return nick;
  }
  Node merge( const Node& left, const Node& ryte ){
    if( left.isnil()){ return ryte; }
    if( ryte.isnil()){ return left; }
    return {
      left.reps or ryte.reps or ryte.prev >= left.left,
      max( left.prev, ryte.prev ),
      left.left,
      ryte.ryte
    };
  }
  void build() {
    const auto nick = rename();
    p.resize( nick + 1 );
    if( n & (n - 1)){ n = 1 << (32 - __builtin_clz( n )); }
    t.resize( n + n );
    For( j, 0, siz( h )){
      auto&  off = p[h[j]];
      auto& node = t[n + j];
      if( !off.empty() ){
        node.prev = *prev( off.end() );
      }
      node.left = node.ryte = j;
      off.insert( j );
    }
    For( j, siz( h ), n ){
      auto& node = t[n + j];
      node.left = node.ryte = j;
    }
    dbg( p );
    for( i32 j = siz( t ) - 1; j > 1; j -= 2 ){
      t[j/2] = merge( t[j - 1], t[j] );
    }
    dbg( t );
  }
  void popping( i32 j ){ // vs breakdance
    for( j /= 2; j > 0; j /= 2 ){
      t[j] = merge(t[2*j], t[2*j + 1]);
    }
  }
  void update( i32 k, i32 u ){
    if( h[k] == u ){ return; }

    auto [jt,_] = p[u].insert( k );
    i32 j = n + k;
    if( jt != p[u].begin()){
      t[j].prev = *prev( jt );
    } else {
      t[j].prev = -1;
    }
    popping( j );
    if( next( jt ) != p[u].end()){
      j = n + *next( jt );
      t[j].prev = k;
      popping( j );
    }
    auto& off = p[h[k]];
    auto it = off.erase( off.find( k ));
    if( it != off.end () ){
      i32 i = n + *it;
      if( it != off.begin()){
        t[i].prev = *prev( it );
      } else {
        t[i].prev = -1;
      }
      popping( i );
    }
    h[k] = u;
  }
  Node _distinctq( i32 k, i32 a, i32 b, i32 x, i32 y ){
    if( y < a or b < x ){ return Node::nil(); }
    if( a <= x and y <= b ){
      if( t[k].reps ){ throw( "voley" ); }
      return t[k];
    }
    i32 d = (x + y)/2;
    auto node = merge( _distinctq( 2*k    , a, b, x    , d ),
                       _distinctq( 2*k + 1, a, b, d + 1, y ));
    if( node.reps ){ throw( "yosh!" ); }
    return node;
  }
  bool distinctq( i32 a, i32 b ){
    try {
      _distinctq( 1, a, b, 0, n - 1 );
    } catch ( ... ) {
      return false;
    }
    return true;
  }
public:
  void pusk() {
    n = load_scalar<i32>();
    m = load_scalar<i32>();
    h.resize( n );
    g.resize( n );
    For( j, 0, n ){
      h[j] = load_scalar<i32>();
      g[j] = make_pair( h[j], j );
    }
    dbg( h );
    q.resize( m );
    For( j, 0, m ){
      const auto type = load_scalar<i32>();
      if( type == 1 ){
        const auto k = load_scalar<i32>() - 1;
        const auto x = load_scalar<i32>();
        g.emp( x, -j - 1 ); // かわす -0
        q[j] = make_tuple( type, k, x );
      } else {
        const auto a = load_scalar<i32>() - 1;
        const auto b = load_scalar<i32>() - 1;
        q[j] = make_tuple( type, a, b );
      }
    }
    dbg( g );
    dbg( q );
    build();
    for( const auto& [type, a, b]: q ){
      if( type == 1 ){
        update( a, b );
      } else {
        if( distinctq( a, b )){
          dmp( "YES" );
        } else {
          dmp( "NO" );
        }
      }
    }
  }
};
/////////////////////////////////////////////////// /  /////////
////////////////////////////////////////////////// /  //////////
///////////////////////////////////////////////// /  ///////////
//////////////////////////////////////////////// /  ////////////
int main() {
  vrooom();
  if( 0 ){
  } else { Algorithm().pusk(); }}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Debugging night.
// Red cursor blinks again,
// Segfault hides in shadows deep,
// Coffee fuels the hunt.
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
