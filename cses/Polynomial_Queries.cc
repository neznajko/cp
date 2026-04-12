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
using d = deque<T>;
template <typename K, typename V>
using umap = unordered_map<K,V>;
////////////////////////////////////////////////////////////////
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using b8l = bool;
using str = string;
using chr = char;
using dbl = double;
////////////////////////////////////////////////////////////////
using vi32 = v<i32>;
using vu32 = v<u32>;
using vi64 = v<i64>;
using vu64 = v<u64>;
using vb8l = v<b8l>;
using pi32 = p<i32,i32>;
using pu32 = p<u32,u32>;
////////////////////////////////////////////////////////////////
constexpr chr nl = '\n';
constexpr chr sp = ' ';
constexpr chr tab = '\t';
constexpr u64 mod1 = 1'000'000'007;
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
template <typename T>
inline T load_scalar() {
    T y; cin >> y;
    return y;
}
////////////////////////////////////////////////////////////////
template <typename K, typename V>
istream& operator>>( istream& is, p<K,V>& p ){
    return is >> p.first >> p.second;
}
////////////////////////////////////////////////////////////////
template <typename T>
istream& operator>>( istream& is, v<T>& v ){
    for( auto& y: v ){ is >> y; }
    return is;
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
# define PSH push_back
# define POP pop_back
# define EMP emplace_back
# define ENQ push_back
# define DEQ pop_front
# define odd( x ) ((x) & 1)
# define evn( y ) (!odd( y ))
# define sqr( x ) ((x) * (x))
# define all( x ) x.begin(), x.end()
# define siz( y ) y.size()
# define dbg( x ) cerr << #x << " = " << x << nl
# define dmp( y ) cout << y << nl;
# define key( p ) p.first
# define val( p ) p.second
# define fst( p ) key( p )
# define snd( p ) val( p )
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
ostream& operator<<( ostream& os, const p<K,V>& p ){
    return os << PAIR.open_bracket
              << key( p )
              << PAIR.separator
              << val( p )
              << PAIR.close_bracket;
}
////////////////////////////////////////////////////////////////
OVERLOAD_OSTREAM_OPERATOR( set );
OVERLOAD_OSTREAM_OPERATOR( vector );
OVERLOAD_OSTREAM_OPERATOR( deque );
OVERLOAD_OSTREAM_OPERATOR( unordered_map );
////////////////////////////////////////////////////////////////
# define dbg2( a, b ) dbg( a ); dbg( b )
# define dbg3( a, b, c ) dbg2( a, b ); dbg( c )
# define dbg4( a, b, c, d ) dbg3( a, b, c ); dbg( d )
# define dmp2( a, b ) cout << a << sp << b << nl;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Algorithm {
public:
    void pusk() {
             n = load_scalar<u32>();
        auto q = load_scalar<u32>();
        bld( n ); 
        while( q-- ){
            auto type = load_scalar<u32>();
               auto a = load_scalar<u32>() - 1;
               auto b = load_scalar<u32>() - 1;
            if( type == 1 ){
                updateq( a, b );
            } else {
                dmp( sumq( a, b ));
            }}}
private:
            u32 n; // en
    vector<u64> t; // Segumento Sum Tree
    vector<u64> p; // Arithmetic Progression Base
    vector<u64> d; // Arithmetic Progression Increment

    void bld( u32 siz ){
        n = siz;
        if( n & (n - 1)){ n = 1 << ( 32 - __builtin_clz( n )); }
        t.resize( 2*n );
        p.resize( 2*n );
        d.resize( 2*n );
        for( u32 j = 0; j < siz; ++j ){
            t[n + j] = load_scalar<u64>();
        }
        for( u32 k = siz( t ) - 1; k > 1; k -= 2 ){
            t[k/2] = t[k-1] + t[k];
        }
    }
    static u64 S( u64 p, u64 d, u64 n ){
        return n*( 2*p + d*(n - 1))/ 2;
    }
//  @@@@     @ @ @   @ @ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 
//  @@@@ @@@ @ @ @ @@@ @ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//  @@@@   @ @ @ @   @   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//  @@@@ @@@ @ @ @@@ @ @ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//  @@@@ @@@ @   @   @ @ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    void flush( u32 k, u32 x, u32 y ){
        if( !p[k] ){ return; }
        // number of elements in [x,y]
        u64 N = y - x + 1;
        t[k] += S( p[k], d[k], N );
        if( x != y ){
            u32 mid = (x + y)/2;
            u32 left = 2*k;
            u32 ryte = left + 1;

            N = mid - x + 1; // # in [x,mid]
            p[ left ] += p[k];
            // that's from the arithmetic progression
            p[ ryte ] += p[k] + N*d[k];
            d[ left ] += d[k];
            d[ ryte ] += d[k];
        }
        p[k] = d[k] = 0;
    }
//  @@@ @ @   @@@@ @@@@@@@@@ @@@@@@ @@@@@@@@   @@@@@@@@@@@@@@@@@
//  @@@ @ @ @ @@@@ @@@   @@   @@@@ @ @@@@@@ @@ @@@@@@@@@@@@@@@@@
//  @@@   @ @ @@   @@@ @ @@@ @@@@@   @@@@@@@   @@@@@@@@@@@@@@@@@
//  @@@@@@@   @@ @ @@@    @@ @@@@@ @@@@@@@@@@@ @@@@@@@@@@@@@@@@@
//  @@@@@@@ @@@@   @@@@@@@@@  @@@@@  @@@@@@@@@ @@@@@@@@@@@@@@@@@
    u64 updateq( u32 k, u32 x, u32 y, u32 a, u32 b, u64 val ){
        flush( k, x, y );
        if( y < a or b < x ){ return val; }
        if( a <= x and y <= b ){
            p[k] = val;
            d[k] = 1;
            flush( k, x, y );
            return val + y - x + 1;
        }
        u32 mid = (x + y)/2;
            val = updateq( 2*k, x, mid, a, b, val );
            val = updateq( 2*k+1, mid+1, y, a, b, val );
           t[k] = t[2*k] + t[2*k+1];
        return val;
    }
    void updateq( u32 a, u32 b ){
        updateq( 1, 0, n - 1, a, b, 1 );
    }
    u64 sumq( u32 k, u32 x, u32 y, u32 a, u32 b ){
        flush( k, x, y );
        if( y < a or b < x ){ return 0; }
        if( a <= x and y <= b ){
            return t[k];
        }
        u32 mid = (x + y)/ 2;
        return sumq( 2*k, x, mid, a, b ) +
               sumq( 2*k+1, mid+1, y, a, b );
    }
    u64 sumq( u32 a, u32 b ){
        return sumq( 1, 0, n - 1, a, b );
    }
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main() {
    vrooom();
    if( 0 ){
    } else { Algorithm().pusk(); }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Polynomial Queries
////////////////////////////////////////////////////////////////
// Your task is to maintain an array of n values and efficiently
// process the following types of queries:
////////////////////////////////////////////////////////////////
// 1 Increase the first value in range [a,b] by 1, the second
// value by 2, the third value by 3, and so on. 
// 2 Calculate the sum of values in range [a,b].
////////////////////////////////////////////////////////////////
// Input The first input line has two integers n and q: the size
// of the array and the number of queries. The next line has n
// values t_1,t_2,...,t_n: the initial contents of the array.
// Finally, there are q lines describing the queries. The format
// of each line is either "1 a b" or "2 a b". Output Print the
// answer to each sum query.
////////////////////////////////////////////////////////////////
// Constraints
// 1 <= n, q <= 2e5
// 1 <= t_i <= 1e6
// 1 <= a <= b <= n
////////////////////////////////////////////////////////////////
// Example
// Input:
// 5 3
// 4 2 3 1 7
// 2 1 5
// 1 1 5
// 2 1 5
////////////////////////////////////////////////////////////////
// Output:
// 17
// 32
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
