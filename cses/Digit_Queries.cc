////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Digit Queries
////////////////////////////////////////////////////////////////
// Time limit: 1.00 s
// Memory limit: 512 MB
////////////////////////////////////////////////////////////////
// Consider an infinite string that consists of all positive
// integers in increasing order:
// 12345678910111213141516171819202122232425...  Your task is to
// process q queries of the form: what is the digit at position
// k in the string?
////////////////////////////////////////////////////////////////
// Input
// The first input line has an integer q: the number of queries.
// After this, there are q lines that describe the queries. Each
// line has an integer k: a 1-indexed position in the string.
////////////////////////////////////////////////////////////////
// Output
// For each query, print the corresponding digit.
////////////////////////////////////////////////////////////////
// Constraints
// 1 <= q <= 1000
// 1 <= k <= 10^{18}
////////////////////////////////////////////////////////////////
// Example
// Input:
// 3
// 7
// 19
// 12
// Output:
// 7
// 4
// 1
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
constexpr chr nl = '\n';
constexpr chr sp = ' ';
constexpr chr tab = '\t';
constexpr u64 mod1 = 1'000'000'007;
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
template <typename T>
istream& operator>>( istream& is, v<T>& v ){
    for( auto& y: v ){ is >> y; }
    return is;
}
////////////////////////////////////////////////////////////////
template <typename T>
inline v<T> load_vector( u32 n ) {
    v<T> y( n ); cin >> y;
    return y;
}
////////////////////////////////////////////////////////////////
template <typename T>
inline w<T> load_tensor( u32 n, u32 m ) {
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
////////////////////////////////////////////////////////////////
# define dbg2( a, b ) dbg( a ); dbg( b );
# define dbg3( a, b, c ) dbg2( a, b ); dbg( c );
# define dbg4( a, b, c, d ) dbg3( a, b, c ); dbg( 4 );
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Algorithm {
public:
    Algorithm( u64 k ):
        k( k )
    {}
    void pusk() {
        u64 p = 9;
        u64 n = 1;
        u64 s = 0;
        u64 b/*ackup */= 0;
        while( s < k ){
            b = s;
            s += n * p;
            ++n;
            p *= 10;
        }
        u64 start = p / 10 / 9;
        k -= b + 1;
        n -= 1;
        u64 number = start + k / n;
        u64 offset = n - k % n;
        // 100
        // 101
        // 102
        //
        u64 digit;
        while( offset-- ){
            digit = number % 10;
            number /= 10;
        }
        cout << digit << nl;
    }
private:
    u64 k;
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main() {
    vrooom();
// 1..9 = 9
// 10..99 = 2*90
// 100..999 = 3*900
//
// 9 * sum{ k * 10^{ k - 1 }}
    if( 0 ){
    } else {
        FOR_THE_HORDE {
            auto k = load_scalar<u64>();
            Algorithm( k ).pusk();
        }
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
