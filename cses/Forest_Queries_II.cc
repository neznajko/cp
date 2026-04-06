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
//##############################################################
template <typename T>
ostream& operator<<( ostream& s, const w<T>& mat ){
    for( auto& row: mat ){ s << nl << row; }
    return s;
}
////////////////////////////////////////////////////////////////
class Algorithm {
private:
    u32 n;
    w<char> forest;
    w<i32> t; // 2d bit( Fenwick )
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
    void bld() {
        dbg( forest );
        n = siz( forest );
        t.resize( n + 1, vi32( n + 1 ));
        for( u32 i = 0; i < n; ++i ){
            for( u32 j = 0; j < n; ++j ){
                if( forest[i][j] == '*' ){
                    add( i + 1, j + 1, 1 );
                }
            }
        }
        dbg( t );
    }
////////////////////////////////////////////////////////////////
    void add( u32 i, u32 j, i32 x ){
        for(; i <= n; i += i & -i ){
            for( u32 k = j; k <= n; k += k & -k ){
                t[i][k] += x;
            }
        }
    }
////////////////////////////////////////////////////////////////
    i32 sum( u32 i, u32 j ){
        i32 s = 0;
        for(; i > 0; i -= i & -i ){
            for( u32 k = j; k > 0; k -= k & -k ){
                s += t[i][k];
            }
        }
        return s;
    }
////////////////////////////////////////////////////////////////
    void upq( const pu32& r ){
        const auto [i,j] = r;
        if( forest[i - 1][j - 1] == '.' ){
            forest[i - 1][j - 1] = '*';
            add( i, j, 1 );
        } else {
            forest[i - 1][j - 1] = '.';
            add( i, j, -1 );
        }
    }
    void sumq( const pu32& r1, const pu32& r2 ){
        const auto [i1,j1] = r1;
        const auto [i2,j2] = r2;
        dmp( sum( i2, j2 ) -
             sum( i1 - 1, j2 ) -
             sum( i2, j1 - 1 ) +
             sum( i1 - 1, j1 - 1 ));
    }
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
public:
    void pusk() {
        auto [n,q] = load_pair<u32>();
        forest = load_tensor<char>( n, n );
        bld();
        while( q-- ){
            auto type = load_scalar<u32>();
            auto r1 = load_pair<u32>();
            if( type == 1 ){
                upq( r1 );
            } else {
                auto r2 = load_pair<u32>();
                sumq( r1, r2 );
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
// Forest Queries II
// 
// You are given an n x n grid representing the map of a forest. 
// Each square is either empty or has a tree. Your task is to 
// process q queries of the following types:
// 
// Change the state (empty/tree) of a square.
// How many trees are inside a rectangle in the forest?
// 
// Input
// The first input line has two integers n and q: the size of 
// the forest and the number of queries. Then, there are n lines 
// describing the forest. Each line has n characters: . is an 
// empty square and * is a tree.
// Finally, there are q lines describing the queries. The format 
// of each line is either "1 y x" or "2 y_1 x_1 y_2 x_2".
// Output
// Print the answer to each query of the second type.
// Constraints
// 
// 1 <= n <= 1000
// 1 <= q <= 2e5
// 1 <= y,x <= n
// 1 <= y_1 <= y_2 <= n
// 1 <= x_1 <= x_2 <= n
// 
// Example
// Input:
// 4 3
// .*..
// *.**
// **..
// ****
// 2 2 2 3 4
// 1 3 3
// 2 2 2 3 4
// 
// Output:
// 3
// 4 
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
