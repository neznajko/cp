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

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Algorithm {
public:
    Algorithm( u32 x, const vu32& p ):
        n( siz( p )),
        x( x ),
        p( p )
    {}
    void pusk() {
        set<u32> lytes{ 0, x };
        map<u32,u32> pass{{ x, 1 }};
        for( auto y: p ){
            auto [ it, _ ] = lytes.insert( y );
            auto ryte = *next( it );
            auto left = *prev( it );
            --pass[ ryte - left ];
            ++pass[ ryte - y ];
            ++pass[ y - left ];
            while( true ){
                auto it = prev( pass.end());
                if( it->second ){ break; }
                pass.erase( it );
            }
            cout << prev( pass.end())->first << sp;
        }
    }
private:
    const u32 n;
    const u32 x;
    const vu32& p;
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main() {
    vrooom();
    if( 0 ){
        map<u32,u32> m;
        m[ 5 ]++;
        m[ 4 ]++;
        m[ 6 ]++;
        dbg( m );
        m[ 6 ]--;
        dbg( m );
        while( true ){
            auto it = prev( m.end());
            if( it->second ){ break; }
            m.erase( it );
        }
        dbg( m );
        dbg( prev( m.end())->first );
    } else {
        auto x = load_scalar<u32>();
        auto n = load_scalar<u32>();
        auto p = load_vector<u32>( n );
        Algorithm( x, p ).pusk();
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
