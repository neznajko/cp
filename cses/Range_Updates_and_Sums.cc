////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
# define DeBug
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
template <typename T>
inline p<T,T> load_pair() {
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
//##############################################################
template <typename T>
ostream& operator<<( ostream& s, const w<T>& mat ){
    for( auto& row: mat ){ s << nl << row; }
    return s;
}
//##############################################################
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Algorithm {
private:
    u32 n;
    vector <u64> t;
    vector <u64> idle; // set value
    vector <u64> lazy; // increment

    void bld( u32 siz ){
        n = siz;
        if( n & (n - 1)){ n = 1 << (32 - __builtin_clz( n )); }
        t.resize( 2*n );
        idle.resize( 2*n );
        lazy.resize( 2*n );
        for( u32 j = 0; j < siz; ++j ){
            t[n + j] = load_scalar<u64>();
        }
        for( u32 j = 2*n - 1; j > 1; j -= 2 ){
            t[j/2] = t[j-1] + t[j];
        }
    }
    enum { IN, OUT, PAWN_RECAPTURE };
    u32 cross( u32 x, u32 y, u32 a, u32 b ){
        if( y < a or x > b ){ return OUT; }
        if( a <= x and y <= b ){ return IN; }
        return PAWN_RECAPTURE;
    }
    static inline u32 L( u32 k ){ return 2*k; }
    static inline u32 R( u32 k ){ return 2*k + 1; }

    void flush( u32 k, u32 x, u32 y ){
        if( idle[k] ){
            t[k] = (y - x + 1) * idle[k];
            if( x != y ){
                idle[L( k )] = idle[R( k )] = idle[k];
                lazy[L( k )] = lazy[R( k )] = 0;
            }
            idle[k] = 0;
        }
        if( lazy[k] ){
            t[k] += (y - x + 1) * lazy[k];
            if( x != y ){
                lazy[L( k )] += lazy[k];
                lazy[R( k )] += lazy[k];
            }
            lazy[k] = 0;
        }
    }
    u64 sum( u32 k, u32 x, u32 y, u32 a, u32 b ){
        flush( k, x, y );
        switch( cross( x, y, a, b )){
            case IN: return t[k];
            case OUT: break;
            case PAWN_RECAPTURE:
                u32 mid = (x + y)/ 2;
                return ( sum( L( k ), x, mid, a, b ) +
                         sum( R( k ), mid + 1, y, a, b ));
        }
        return 0;
    }
    void up( u32 k, u32 x, u32 y, u32 a, u32 b, u64 val, 
             vector<u64>& pending ){
        flush( k, x, y );
        switch( cross( x, y, a, b )){
            case IN:
                pending[k] = val;
                flush( k, x, y );
            case OUT: break;
            case PAWN_RECAPTURE:
                u32 mid = (x + y)/ 2;
                up( L( k ),       x, mid, a, b, val, pending );
                up( R( k ), mid + 1,   y, a, b, val, pending );
                t[k] = t[L( k )] + t[R( k )];
        }
    }
    u64 sumq( u32 a, u32 b ){
        return sum( 1, 0, n - 1, a, b );
    }
    void incq( u32 a, u32 b, u64 val ){
        up( 1, 0, n - 1, a, b, val, lazy );
    }
    void setq( u32 a, u32 b, u64 val ){
        up( 1, 0, n - 1, a, b, val, idle );
    }
////////////////////////////////////////////////////////////////
public:
    void pusk() {
        auto [n,q] = load_pair<u32>();
        bld( n );
        while( q-- ){
            auto type = load_scalar<u32>();
            auto [a,b] = load_pair<u32>();
            --a; --b;
            if( type == 3 ){
                dmp( sumq( a, b ));
            } else {
                auto val = load_scalar<u64>();
                if( type == 1 ){
                    incq( a, b, val );
                } else {
                    setq( a, b, val );
                }}}}};
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
// Range Updates and Sums
// Your task is to maintain an array of n values and efficiently 
// process the following types of queries:
// 
// 1 Increase each value in range [a,b] by x.
// 2 Set each value in range [a,b] to x.
// 3 Calculate the sum of values in range [a,b].
// 
// Input
// The first input line has two integers n and q: the array size 
// and the number of queries.
// The next line has n values t_1,t_2,...,t_n: the initial 
// contents of the array.
// Finally, there are q lines describing the queries. The format 
// of each line is one of the following: "1 a b x",  "2 a b x", 
// or "3 a b".
// Output
// Print the answer to each sum query.
// 
// Constraints
// 1 <= n, q <= 2e5
// 1 <= t_i, x <= 1e6
// 1 <= a <= b <= n
// 
// Example
// Input:
// 6 5
// 2 3 1 1 5 3
// 3 3 5
// 1 2 4 2
// 3 3 5
// 2 2 4 5
// 3 3 5
// 
// Output:
// 7
// 11
// 15
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
