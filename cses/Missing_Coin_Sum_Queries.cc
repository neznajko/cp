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
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Algorithm {
#   define reqr first
#   define give second
    using Node = pi64;
    using Cluster = vector<Node>; 
private:
                i32 n = 0;
    vector<Cluster> t;

    void bld( i32 siz ){
        n = siz;
        if( n & (n - 1)){ n = 1 << (32 - __builtin_clz( n )); }
        dbg2( siz, n );
        t.resize( n << 1 );
        i64 x;
        for( i32 j = 0; j < siz; ++j ){
            cin >> x;            
            t[n + j].emp( x - 1, x );
        }
        for( i32 j = siz( t ) - 1; j > 1; j -= 2 ){
            t[j/2] = merge( t[j-1], t[j] );
        }
        dbg( t );
    }
    Cluster query( i32 k, i32 x, i32 y, i32 a, i32 b ){
        if( y < a or x > b ){ return {}; }
        if( a <= x and y <= b ){ return t[k]; }
        const i32 mid = (x + y) >> 1;
        return merge( query( 2*k, x, mid, a, b ),
                      query( 2*k + 1, mid + 1, y, a, b ));
    }
    i64 query( i32 a, i32 b ){
        dbg2( a, b );
        const auto clst = query( 1, 0, n - 1, a, b );
        dbg( clst );
        const auto front = clst.front();
        if( front.reqr ){ return 1; }
        return ( front.reqr + front.give + 1 );
    }
    void merge( Cluster& clst, const Node& node ){
        auto& back = clst.back();
        const auto maxsum = back.reqr + back.give;
        if( maxsum >= node.reqr ){
            back.give += node.give;
        } else {
            clst.psh( node );
        }
    }
    Cluster merge( const Cluster& left, const Cluster& ryte ){
        if( left.empty()){ return ryte; }
        if( ryte.empty()){ return left; }
        Cluster clst;
        i32 i = 0;
        i32 j = 0;
        if( left[i].reqr > ryte[j].reqr ){
            clst.psh( ryte[j++] );
        } else {
            clst.psh( left[i++] );
        }
        while( true ){
            if( i >= siz( left )){
                for(; j < siz( ryte ); ++j ){
                    merge( clst, ryte[j]);
                }
                break;
            }
            if( j >= siz( ryte )){
                for(; i < siz( left ); ++i ){
                    merge( clst, left[i] );
                }
                break;
            }
            if( left[i].reqr > ryte[j].reqr ){
                merge( clst, ryte[j++] );
            } else {
                merge( clst, left[i++] );
            }
        }
        return clst;
    }
////////////////////////////////////////////////////////////////
public:
    void pusk() {
        auto [n,q] = load_pair<i32>();
        bld( n );
        while( q-- ){
            auto [a,b] = load_pair<i32>();
            dmp( query( a - 1, b - 1 ));
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
// Missing Coin Sum Queries
// You have n coins with positive integer values. 
// The coins are numbered 1,2,...,n.
// Your task is to process q queries of the form: 
// "if you can use coins a ... b, what is the smallest sum you 
// cannot produce?"
// Input
// The first input line has two integers n and q: 
// the number of coins and queries.
// The second line has n integers x_1,x_2,...,x_n: 
// the value of each coin.
// Finally, there are q lines that describe the queries. 
// Each line has two values a and b: you can use coins a ... b.
// Output
// Print the answer for each query.
// Constraints
// 1 <= n, q <= 2e5
// 1 <= x_i <= 1e9
// 1 <= a <= b <= n
// Example
// Input:
// 5 3
// 2 9 1 2 7
// 2 4
// 4 4
// 1 5
// Output:
// 4
// 1
// 6
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// log: yea that section of range queries in cses is just brutal
// i mean the last 10 problems or so each took me bout a week or
// smth, and this was the last one:) i am just posting the times
// cos the time limit is 1 sec. This clearly is not the intended
// solution which according to DeepSeek is with persistent trees
// so here m keeping a list of pairs in each node that should be
// O(logn), yea one haiku from ChatCPT to celebrate that 0.93s W
// #1   ACCEPTED    0.00 s
// #2   ACCEPTED    0.85 s
// #3   ACCEPTED    0.93 s
// #4   ACCEPTED    0.47 s
// #5   ACCEPTED    0.00 s
// #6   ACCEPTED    0.82 s
// #7   ACCEPTED    0.00 s
// #8   ACCEPTED    0.63 s
// #9   ACCEPTED    0.82 s                night full of failures
// #10  ACCEPTED    0.00 s           code finally starts to work
// #11  ACCEPTED    0.85 s                           no idea why
