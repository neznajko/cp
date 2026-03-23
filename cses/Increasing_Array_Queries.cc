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
// nput: h[0,N), 0 < h[j]
// outp: f[0,N), f[j] is the number of ops required in the range
// [j,N) to make suffix h[j,N) increasing
// Getf( h ):
//     j <- N
//     stk <- [(inf,j)]
//     f <- [0] * (N + 1)
// #   define T stk.top()
// #   define fst fyorst
// #   define snd second
// 1H  if --j < 0: jmp 2F
//     f[j] <- f[j + 1]
//     if h[j] < T.fst:
//         stk.psh(( h[j], j ))
//     else if h[j] = T.fst:
//         T.snd <- j
//     else // T.fst < h[j]
//         y <- T.fst
//         stk.pop()
//         while T.fst < h[j]
//             f[j] += (T.fst - y) * (T.snd - j - 1)
//             y <- T.fst
//             stk.pop()
//         f[j] += (h[j] - y) * (T.snd - j - 1)
//         if h[j] = T.fst:
//             T.snd <- j
//         else
//             stk.psh(( h[j], j ))
//     jmp 1B
// 2H  ret f
vu64 Getf( const vu32& h ){
    i32 j = siz( h );
    v<pu32> stk( 1, { 1'000'000'001, j });
    vu64 f( j + 1 );
#   define T stk.back()
    while( --j >= 0 ){
        f[j] = f[j + 1];
        if( h[j] < T.fst ){
            stk.psh({ h[j], j });
        } else 
        if( h[j] == T.fst ){
            T.snd = j;
        } else {
            auto y = T.fst; stk.kpop();
            while( T.fst < h[j] ){
                f[j] += (u64) (T.fst - y) * (T.snd - j - 1);
                y = T.fst; stk.kpop();
            }
            f[j] += (u64) (h[j] - y) * (T.snd - j - 1);
            if( h[j] == T.fst ){
                T.snd = j;
            } else {
                stk.psh({ h[j], j });
            }
        }
    }
    return f;
}
////////////////////////////////////////////////////////////////
// nput: n, n > 0
// outp: True/False if n is a power of 2
// xmpl: Isp2( 8 ) = True
// Isp2( n ): ret !(n & (n - 1))
inline bool Isp2( u32 n ){ 
    return !(n & (n - 1));
}
////////////////////////////////////////////////////////////////
// nput: n, n > 0
// outp: the upper bound of n as a power of 2
// xmpl: Getn( 7 ) = 8
// Getn( n ):
//     if Isp2( n ): ret n
//     k <- 0
//     do {
//         n /= 2
//         ++k
//     } while( n );
//     ret 1 << k;
u32 Getn( u32 n ){
    if( Isp2( n )){ return n; }
    u32 k = 0;
    do { n >>= 1; ++k; } while( n );
    return 1 << k;
}
////////////////////////////////////////////////////////////////
// nput: h[0,N], 0 < h[j], h[N] = 0 is guard
//       a, mos left maximum offset in the left child segment
//       b, mos left maximum offset in the ryte child segment
// outp: mos left maximum offset in the parent segment
// note: all offsets are 0-based, in case of empty segments the
// value of the offset is set to N
// Merge( h, a, b ):
//    ret h[b] > h[a] ? b : a
inline u32 Merge( const vu32& h, u32 a, u32 b ){
    return (h[b] > h[a]) ? b : a;
}
////////////////////////////////////////////////////////////////
// nput: h[0,N], 0 < h[j], h[N] = 0 is guard
// outp: t[0,2*n), mos left maximum offset segment tree, n is 
//       the upper bound of N as a power of 2
// Bldt( h ):
//     N <- siz( h ) - 1
//     n <- Getn( N )
//     t <- [N] * 2 * n
//     for( j <- 0; j < N; ++j ){
//         t[n + j] <- j
//     }
//     for( j <- siz( t ) - 1; j > 1; j -= 2 ){
//         t[j/2] <- Merge( h, t[j - 1], t[j] )
//     }
//     ret t
vu32 Bldt( const vu32& h ){
    u32 N = siz( h ) - 1;
    auto n = Getn( N );
    auto t = vu32( n + n, N );
    for( u32 j = 0; j < N; ++j ){
        t[n + j] = j;
    }
    for( u32 j = siz( t ) - 1; j > 1; j -= 2 ){
        t[j/2] = Merge( h, t[j - 1], t[j] );
    }
    return t;
}
////////////////////////////////////////////////////////////////
// nput: h[0,N], h[j] > 0, h[N] = 0 is guard
//       t[0,2n), n is defined as above
//       [a,b], 0 <= a <= b < N
// outp: the mos left offset maximum in the ragne [a,b] that is
//       a <= m <= b: h[m] is maximum in [a,b] and m is mos left
// Getm( h, t, a, b ):
//     n <- siz( t )/2
//     a += n
//     b += n
//     M <- { 0,0 }
//     while a <= b:
//         if a & 1 = 1:
//             M <- max( M, { h[t[a]], -t[a] })
//             ++a;
//         if b & 1 = 0:
//             M <- max( M, { h[t[b]], -t[b] })
//             --b;
//         a /= 2
//         b /= 2
//     ret -M.second
# define isRyte( x ) odd( x )
# define isLeft( y ) evn( y )
u32 Getm( const vu32& h, const vu32& t, u32 a, u32 b ){
    u32 n = siz( t )/2;
    a += n;
    b += n;
    pi32 M = { 0, 0 };
    while( a <= b ){
        if( isRyte( a )){
            M = max( M, { h[t[a]], -t[a] });
            ++a;
        }
        if( isLeft( b )){
            M = max( M, { h[t[b]], -t[b] });
            --b;
        }
        a /= 2;
        b /= 2;
    }
    return -M.snd;
}
////////////////////////////////////////////////////////////////
// nput: h[0,N), h[j] > 0
// outp: p[0,N], prefix sum of h: p[j] = h[0] + ... + h[j - 1]
// Getp( h ):
//     p <- [0] * (N + 1)
//     for( j <- 0; j < N; ++j ){
//         p[j + 1] = p[j] + h[j];
//     }
//     ret p
vu64 Getp( const vu32& h ){
    u32 N = siz( h );
    vu64 p( N + 1 );
    for( u32 j = 0; j < N; ++j ){
        p[j + 1] = p[j] + h[j];
    }
    return p;
}
////////////////////////////////////////////////////////////////
// nput: f[0,N), suffix number of ops as defined above
//       p[0,N], prefix sum
//       h[0,N), the array of interest
//       t[0,2*n), mos left offset max segment tree
//       [a,b], the query range
// outp: number of ops to make h[a,b] increasing
// Query( f, p, h, t, a, b ):
//     m <- Getm( h, t, a, b ) 
//     z <- f[a] - f[m]
//     z += h[m] * (b - m) - (pref[b + 1] - pref[m + 1])
//     ret z
u64 Query( const vu64& f, 
           const vu64& p, 
           const vu32& h, 
           const vu32& t, u32 a, u32 b ){
    auto m = Getm( h, t, a, b );
    u64 z = f[a] - f[m];
    z += (u64) h[m] * (b - m) - (p[b + 1] - p[m + 1]);
    return z;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Algorithm { 
public:
  void pusk(                                                  ){
    auto n = load_scalar<u32>(                                );
    auto q = load_scalar<u32>(                                );
    auto h = load_vector<u32>(                         n      );
    auto f = Getf(               h                            );
    dbg(                 f                                    );
    auto p = Getp(                                          h );
    dbg( p                                                    );
    h.psh(                                0                   );
    auto t = Bldt(   h                                        );
    dbg(                                                 h    );
    dbg(                                 t                    );
    while(                         q                       -- ){
      auto a = load_scalar<u32>(        )    -                1;
      auto b = load_scalar<u32>(               )   -          1;
      dbg2(              a,                   b               );
      dmp( Query(  f,          p,  h,  t,       a,     b     ));
    }
  }
};
/////////////////////////////////////////////////// /  /////////
////////////////////////////////////////////////// /  //////////
///////////////////////////////////////////////// /  ///////////
//////////////////////////////////////////////// /  ////////////
// We keep walking,
// through fading lights and blurry roads,
// still our steps refuse to stop,
// until the dawn, we move ahead.
 int main() {
  vrooom();
  if( 0 ){
  } else { Algorithm().pusk(); }}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// CSES Problem Set                           Time limit: 1.00 s
//                                          Memory limit: 512 MB
/////////////////////////////////////// Increasing Array Queries
// You are given an array that consists of n integers. The array
// elements are indexed 1,2,...,n.
//
// You can modify the array using the following operation:
// choose an array element and increase its value by one.
//
// Your task is to process q queries of the form: when we
// consider a subarray from position a to position b, what is
// the minimum number of operations after which the subarray is
// increasing?
//
// An array is increasing if each element is greater than or
// equal with the previous element.
////////////////////////////////////////////////////////// Input
// The first input line has two integers n and q: the size of
// the array and the number of queries.
//
// The next line has n integers x_1,x_2,...,x_n: the contents of
// the array.
//
// Finally, there are q lines that describe the queries. Each
// line has two integers a and b: the starting and ending
// position of a subarray.
///////////////////////////////////////////////////////// Output
// For each query, print the minimum number of operations.
//////////////////////////////////////////////////// Constraints
// 1 <= n,q <= 2e5
// 1 <= x_i <= 1e9
// 1 <= a <= b <= n
//////////////////////////////////////////////////////// Example
// Input:
// 5 3
// 2 10 4 2 5
// 3 5
// 2 2
// 1 4
//
// Output:
// 2
// 0
// 14
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
