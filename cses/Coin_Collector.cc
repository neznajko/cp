////////////////////////////////////////////////////////////////
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
# ifdef DeBug
#   define dbg( x ) cerr << #x << " = " << x << nl
# else
#   define dbg( x )
# endif
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
# define dmp2( a, b ) cout << a << sp << b << nl;
# define dbg2( a, b ) dbg( a ); dbg( b )
# define dbg3( a, b, c ) dbg2( a, b ); dbg( c )
# define dbg4( a, b, c, d ) dbg3( a, b, c ); dbg( d )
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
enum { WHITE, GRAY, BLACK, RED, BLUE, ORANGE, MAGENTA, BROWN };
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
vi64 dfs_topsort( w<i64>& adj ){
    vi64 topsort;
    vi64 status( siz( adj ), WHITE );
    For( u, 1, siz( adj )){
        if( status[u] == BLACK ){ continue; } 
        v<pi64> stk;
        status[u] = GRAY;
        stk.emp( u, siz( adj[u] ));
        while( !stk.empty()){
            auto& [u,j] = stk.back();
            if( j == 0 ){
                status[u] = BLACK;
                topsort.psh( u );
                stk.kpop();
                continue;
            }
            auto v = adj[u][--j];
            if( status[v] == WHITE ){
                status[v] = GRAY;
                stk.emp( v, siz( adj[v]));
            }
        }
    }
    return topsort;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Algorithm {
private:
    i64 n; vi64& k; v<pi64>& e;
    w<i64> adj;
    w<i64> rev;
public:
    Algorithm( i64 n, vi64& k, v<pi64>& e ):
        n( n ), k( k ), e( e )
    {
        dbg( k );
        cons_graphs();
    }
    void cons_graphs() {
        adj = w<i64>( n + 1 );
        rev = w<i64>( n + 1 );
        for( auto [u,v]: e ){
            if( u == v ){ continue; }
            adj[u].psh( v );
            rev[v].psh( u );
        }
    }
    void pusk() {
        dbg( adj );
        auto topsort = dfs_topsort( adj );
        reverse( on( topsort ));
        dbg( topsort );
        auto [scc,m] = dfs_scc( topsort );
        dbg2( scc, m );
        vi64 h( m + 1 );
        w<i64> dag( m + 1 );
        For( u, 1, n + 1 ){
            h[scc[u]] += k[u - 1];
            for( auto v: adj[u] ){
                if( scc[u] == scc[v] ){ continue; }
                dag[scc[u]].psh( scc[v] );
            }
        }
        dbg2( h, dag );
        topsort = dfs_topsort( dag );
        dbg( topsort );
        i64 max_total = 0;
        vi64 total( m + 1 );
        for( auto u: topsort ){
            i64 max_nbor = 0;
            for( auto v: dag[u] ){
                max_nbor = max( max_nbor, total[v] );
            }
            total[u] = h[u] + max_nbor;
            max_total = max( max_total, total[u] );
        }
        dbg( total );
        dmp( max_total );
    }
    p<vi64,i64> dfs_scc( vi64& topsort ){
        vi64 scc( n + 1 );
        vi64 status( n + 1, WHITE );
        i64 cnt = 0;
        for( auto u: topsort ){
            if( status[u] == BLACK ){ continue; } 
            v<pi64> stk;
            status[u] = GRAY;
            scc[u] = ++cnt;
            stk.emp( u, siz( rev[u] ));
            while( !stk.empty()){
                auto& [u,j] = stk.back();
                if( j == 0 ){
                    status[u] = BLACK;
                    stk.kpop();
                    continue;
                }
                auto v = rev[u][--j];
                if( status[v] == WHITE ){
                    status[v] = GRAY;
                    scc[v] = cnt;
                    stk.emp( v, siz( rev[v]));
                }
            }
        }
        return {scc,cnt};
    }
};
/////////////////////////////////////////////////// /  /////////
////////////////////////////////////////////////// /  //////////
///////////////////////////////////////////////// /  ///////////
//////////////////////////////////////////////// /  ////////////
int main() {
    vrooom();
    if( 0 ){
    } else {
        auto n = load_scalar<i64>();
        auto m = load_scalar<i64>();
        auto k = load_vector<i64>( n );
        auto e = load_vector<pi64>( m );
        Algorithm( n, k, e ).pusk();
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
