////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Concert Tickets
////////////////////////////////////////////////////////////////
// Time limit: 1.00 s
// Memory limit: 512 MB
////////////////////////////////////////////////////////////////
// There are n concert tickets available, each with a certain
// price. Then, m customers arrive, one after another.  Each
// customer announces the maximum price they are willing to pay
// for a ticket, and after this, they will get a ticket with the
// nearest possible price such that it does not exceed the
// maximum price.
////////////////////////////////////////////////////////////////
// Input
// The first input line contains integers n and m: the number of
// tickets and the number of customers.  The next line contains
// n integers h_1,h_2,...,h_n: the price of each ticket.  The
// last line contains m integers t_1,t_2,...,t_m: the maximum
// price for each customer in the order they arrive.
////////////////////////////////////////////////////////////////
// Output
// Print, for each customer, the price that they will pay for
// their ticket. After this, the ticket cannot be purchased
// again.  If a customer cannot get any ticket, print -1.
////////////////////////////////////////////////////////////////
// Constraints
// 1 <= n, m <= 2e5
// 1 <= h_i, t_i <= 1e9
////////////////////////////////////////////////////////////////
// Example
// Input:
// 5 3
// 5 3 7 8 5
// 4 8 3
////////////////////////////////////////////////////////////////
// Output:
// 3
// 8
// -1
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
using vb8l = v<b8l>;
using pu32 = p<u32,u32>;
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
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Algorithm {
public:
    Algorithm( const vi32& h, const vi32& t ):
        n( siz( h )),
        m( siz( t )),
        h( h ),
        t( t )
    {}
    void pusk() {
        for( auto p: h ){
            ++fq [p];
            s.insert( p );
        }
        for( auto key: t ){
            cout << floor( key ) << nl;
        }
    }
private:
    const i32 n;
    const i32 m;
    const vi32& h;
    const vi32& t;
    umap<i32,i32> fq;
    set<i32> s;
    i32 floor( i32 key ){
        auto it = s.upper_bound( key );
        if( it == s.begin() ){
            return -1;
        }
        auto value = *prev( it );
        if( --fq [value] == 0 ){
            s.erase( value );
        }
        return value;
    }
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main() {
    vrooom();
    if( 0 ){
    } else {
        auto n = load_scalar<i32>();
        auto m = load_scalar<i32>();
        auto h = load_vector<i32>( n );
        auto t = load_vector<i32>( m );
        Algorithm( h, t ).pusk();
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
