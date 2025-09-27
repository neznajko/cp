////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

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
template <typename T>
using uset = unordered_set<T>;
template <typename T>
using maxpq = priority_queue<T>;
template <typename T>
using minpq = priority_queue<T,v<T>,greater<T>>;
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
using pi64 = p<i64,i64>;
using pu64 = p<u64,u64>;
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
# define MKP make_pair
# define LWB lower_bound
# define UPB upper_bound
# define odd( x ) ((x) & 1)
# define evn( y ) (!odd( y ))
# define sqr( x ) ((x) * (x))
# define all( x ) x.begin(), x.end()
# define siz( y ) (u32) y.size()
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
OVERLOAD_OSTREAM_OPERATOR( unordered_set );
OVERLOAD_OSTREAM_OPERATOR( map );
////////////////////////////////////////////////////////////////
# define dbg2( a, b ) dbg( a ); dbg( b )
# define dbg3( a, b, c ) dbg2( a, b ); dbg( c )
# define dbg4( a, b, c, d ) dbg3( a, b, c ); dbg( d )
# define dmp2( a, b ) cout << a << sp << b << nl;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// s = "abobebob"
// N - all distinct subseq of s: a, b, o, e, ab, abo, aboe, ..
// B - all subseq of s that don't have b: a, o, e, ao, ..
// b - nof of b's in s: 4, then
// N = B + bB = B(1 + b), zo B = N/(1 + b), zo if we wanna
// calculate the N for "babobebob" it will be N + B =
// N + N/(1 + b) = N( 2 + b )/( 1 + b )
////////////////////////////////////////////////////////////////
pi64 ee( i64 a, i64 b ){ // ignore gcd
    if( b == 0 ){ return { 1, 0 }; }
    auto [x, y] = ee( b, a % b );
    return { y, x - y * (a / b) };    
}
////////////////////////////////////////////////////////////////
i64 modinv( i64 a ){
    auto [x, _] = ee( a, mod1 );
    if( x < 0 ) x += mod1;
    return x % mod1; // make it happen
}
////////////////////////////////////////////////////////////////
class Algorithm {
public:
    Algorithm( const vi32& x ):
        n( siz( x )),
        x( x )
    {}
    void pusk() {
        v<pi32> posn( n );
        for( i32 j = 0; j < n; ++j ){
            posn[j] = { x[j], j };
        }
        stable_sort( all( posn ));
        // staat
        i64 N = 1;
        for( i32 j = n - 1; j >= 0; --j ){
            auto it1 = LWB( all( posn ), MKP( x[j], j ));
            auto it2 = UPB( all( posn ), MKP( x[j], j ),
                            []( auto a, auto b ){
                                return fst( a ) < fst( b );
                            });
            i64 b = prev( it2 ) - it1;
            N = N * (2 + b) % mod1;
            i64 inv = modinv( 1 + b );
            N = N * inv % mod1;
        }
        // fnish
        dmp( N % mod1 - 1 );
    }
private:
    const i32 n;
    const vi32& x;
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main() {
    vrooom();
    if( 0 ){
        i64 a = 8;
        i64 b = modinv( 2 );
        i64 c = a * b % mod1;
        dmp( c );
    } else {
        auto n = load_scalar<i32>();
        auto x = load_vector<i32>( n );
        Algorithm( x ).pusk();
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
