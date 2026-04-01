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
//##############################################################
//##############################################################
////////////////////////////////////////////////////////////////
class Algorithm {
private:
    v<pi32> f;
    v<i32> groups;
    v<i32> nxt;
    w<pi32> streams;
    vi32 offsets;
#   define A first
#   define B second
    void make_groups() {
        groups.resize( siz( f ));
        i32 g = 0;
        groups[0] = ++g;
        i32 T = 0;
        nxt.resize( siz( f ) + 1, -1 );
        for( i32 j = 1; j < siz( f ); ++j ){
            if( f[j].A < f[T].B ){
                groups[j] = ++g;
            } else {
                groups[j] = groups[T++];
                while( T < j and f[T].B <= f[j].A ){
                    nxt[groups[T]] = j;
                    ++T;
                }
            }
        }
        nxt.resize( g + 1 );
        dbg( g );
        dbg( groups );
        dbg( nxt );
        streams.resize( g + 1 );
        offsets.resize( siz( f ));
        for( i32 j = 0; j < siz( f ); ++j ){
            auto g = groups[j]; 
            offsets[j] = siz( streams[g] );
            streams[g].psh( f[j] );
        }
        dbg( streams );
        dbg( offsets );
    }
    void bld( v<pi32>& program ){
        // discard some films
        sort( on( program ), []( const auto& x, const auto& y ){
            if( x.snd == y.snd ){
                return x.fst > y.fst;
            } else {
                return x.snd < y.snd;
            }
        });
        dbg( program );
        f.reserve( siz( program ));
        i32 threshold = 0;
        for( i32 j = 0; j < siz( program ); ++j ){
            auto [a,b] = program[j];
            if( a <= threshold ){ continue; }
            f.psh({ a, b });
            threshold = a;
        }
        dbg( f );
        make_groups();
    }
    i32 query( i32 start, i32 finish ){
        // lower bound of start on f
        // > j > group > offset > stream
        // then you gou
        auto it = lower_bound( on( f ), start,
            []( const pi32& p, i32 key ){
                return p.A < key;
            });
        if( it == f.end()){ return 0; } // negative
        dbg2( start, finish );
        i32 n = 0;
        i32 i = it - f.begin();
        do {
            auto g = groups[i];
            auto j = offsets[i];
            dbg2( g, j );
            dbg( streams[g] );
            const auto& stream = streams[g];
            if( finish <= stream.back().B ){
                // ve ar dn
                auto it = lower_bound( on( stream ), finish,
                   []( const pi32& p, i32 key ){
                       return p.B < key;
                   });
                auto k = it - stream.begin();
                if( finish < it->B ){ --k; }
                if( j <= k ){
                    n += k - j + 1;
                }
                break;
            } else {
                // watch them all
                n += siz( stream ) - j;
                i = nxt[g];
            }
        } while( i >= 0 );
        
        return n;
    }
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
public:
    void pusk() {
        auto [n,q] = load_pair<i32>();
        //
        v<pi32> program( n );
        while( n-- ){
            program[n] = load_pair<i32>();
        }
        bld( program );
        while( q-- ){
            auto [start,finish] = load_pair<i32>();
            dmp( query( start, finish ));
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
// Movie Festival Queries
//
// Time limit: 1.00 s
// Memory limit: 512 MB
// 
// In a movie festival, n movies will be shown. You know the 
// starting and ending time of each movie. Your task is to 
// process q queries of the form: if you arrive and leave the 
// festival at specific times, what is the maximum number of 
// movies you can watch?
////////////////////////////////////////////////////////////////
// You can watch two movies if the first movie ends before or 
// exactly when the second movie starts. You can start the first 
// movie exactly when you arrive and leave exactly when the last 
// movie ends.
//
// Input
// The first input line has two integers n and q: the number of
// movies and queries. After this, there are n lines describing 
// the movies. Each line has two integers a and b: the starting 
// and ending time of a movie. Finally, there are q lines 
// describing the queries. Each line has two integers a and b: 
// your arrival and leaving time.
//
// Output
// Print the maximum number of movies for each query.
//
// Constraints
// 1 <= n,q <= 2e5
// 1 <= a < b <= 1e6
// 
// Example    1--2--3--4--5--6--7--8--9--a
// Input:        ==========  =============
// 4 3                 ==========     ====      
// 2 5                    -------------
// 6 10          -------------------------
// 4 7                          ----------
// 9 10
// 5 9
// 2 10
// 7 10
// 
// Output:
// 0
// 2
// 1
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//          s i l ve r   f i sh  cau g h t in  M O T I O N
//          S lo wl y  rippl  e s   f a  de   a way
//          F or e s t  sp i r i ts  g ath er  h er e,
//          e ver y n igh t  an d eve ry d ay
//
// oo                                     
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// log: According to Gemini I have discovered ..
// You've essentially invented a Compressed Path Decomposition
// for a Directed Acyclic Graph (DAG).
// .. have no idea what that is buuuut that was one of a
// complicated implementations:) was curious if its going to
// pass all test cases:) the text book solution I didn't find,
// and it looks like one liner compared to thus
