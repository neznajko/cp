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
# ifdef __GNUC__
# include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T, typename Comparator=less<T>>
using iset = tree<T, null_type, Comparator, rb_tree_tag,
                  tree_order_statistics_node_update>;
# define FBO find_by_order
# define OOK order_of_key
# endif
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
# define LB lower_bound
# define UB upper_bound
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
# define dmp2( a, b ) cout << a << sp << b << nl;
# define dbg2( a, b ) dbg( a ); dbg( b )
# define dbg3( a, b, c ) dbg2( a, b ); dbg( c )
# define dbg4( a, b, c, d ) dbg3( a, b, c ); dbg( d )
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
struct Ival {
    i32 left;
    i32 ryte;
    i32 posn;
};
////////////////////////////////////////////////////////////////
ostream& operator<<( ostream& os, const Ival& ival ){
    return os << "(" << ival.left << " " << ival.ryte << ")["
              << ival.posn << "]";
}
////////////////////////////////////////////////////////////////
struct Left_Comparator {
    bool operator()( const Ival& a, const Ival& b ) const {
        if( a.left == b.left ){
            return a.ryte > b.ryte;
        }
        return a.left < b.left;
    }
};
////////////////////////////////////////////////////////////////
struct Ryte_Comparator {
    bool operator()( const Ival& a, const Ival& b ) const {
        if( a.ryte == b.ryte ){
            return a.left > b.left;
        }
        return a.ryte < b.ryte;
    }
};
////////////////////////////////////////////////////////////////
class Algorithm {
public:
    Algorithm( i32 n, v<pi32>& p ):
        n( n ),
        p( p )
    {}
    void pusk() {
        vi32 top( n );
        vi32 bot( n );
        v<Ival> ivals( n );
        for( i32 i = 0; i < n; ++i ){
            auto [ left, ryte ] = p[i];
            ivals[i] = { left, ryte, i };
        }
        sort( on( ivals ), Left_Comparator() );
        i32 maxryte = mini32;
        iset<pi32> ryte_endpoints;
        for( auto iv: ivals ){
            pi32 q = { iv.ryte, -iv.left };
            ryte_endpoints.insert( q );
            if( iv.ryte > maxryte ){
                maxryte = iv.ryte;
            } else {
                auto j = ryte_endpoints.OOK( q );
                bot[iv.posn] = ryte_endpoints.size() - 1 - j;
            }
        }
        sort( on( ivals ), Ryte_Comparator() );
        i32 maxleft = mini32;
        iset<pi32> left_endpoints;
        for( auto iv: ivals ){
            pi32 q = { iv.left, -iv.ryte };
            left_endpoints.insert( q );
            if( iv.left > maxleft ){
                maxleft = iv.left;
            } else {
                auto j = left_endpoints.OOK( q );
                top[iv.posn] = left_endpoints.size() - 1 - j;
            }
        }
        CONT = {"",""," "};
        dmp( top );
        dmp( bot );
    }
private:
    const i32 n;
    v<pi32>& p;
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
        auto p = load_vector<pi32>( n );
        Algorithm( n, p ).pusk();
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
