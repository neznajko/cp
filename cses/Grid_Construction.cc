////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Grid Construction
// Time limit: 1.00 s
// Memory limit: 512 MB

// Your task is to construct an n x n grid where each square has
// the smallest nonnegative integer that does not appear to the
// left on the same row or above on the same column.

// Input
// The only line has an integer n.

// Output
// Print the grid according to the example.

// Constraints
// 1 <= n <= 100

// Example
// Input:
// 5

// Output:
// 0 1 2 3 4
// 1 0 3 2 5
// 2 3 0 1 6
// 3 2 1 0 7
// 4 5 6 7 0
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
////////////////////////////////////////////////////////////////
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using b8l = bool;
using str = string;
using chr = char;
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
# define odd( x ) ((x) & 1)
# define evn( y ) (!odd( y ))
# define sqr( x ) ((x) * (x))
# define all( x ) x.begin(), x.end()
# define siz( y ) y.size()
# define dbg( x ) cerr << #x << " = " << x << nl
# define key( p ) p.first
# define val( p ) p.second
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
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// 0 1 2 3 4 store[1] = 1 3 2 5
// 1 0 3 2 5 store[2] = 2 3 1 6
// 2 3 0 1 6 store[3] = 3 2 1
// 3 - - 0 7 store[4] = 4 5 6
// 4 - - - 0 
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Algorithm {
public:
    Algorithm( u32 n ):
        n( n ),
        grid( w<u32>( n, v<u32>( n ))),
        store( v<set<u32>>( n ))
    {}
    void pusk() {
        for( u32 j = 1; j < n; ++j ){
            put( 0, j, j );
        }
        for( u32 i = 1; i < n; ++i ){
            for( u32 j = i + 1; j < n; ++j ){
                put( i, j, avail( i, j ));
            }
        }
        CONT = { "", "\n", " " };
        cout << sp << grid << nl;
    }
private:
    const u32 n;
    w<u32> grid;
    v<set<u32>> store;
    void put( u32 i, u32 j, u32 value ){
        store [i].insert( value );
        store [j].insert( value );
        grid [i][j] = grid [j][i] = value;
    }
    u32 avail( u32 i, u32 j ){
        v<u32> u{ 0 };
        set_union( all( store [i] ),
                   all( store [j] ),
                   back_inserter( u ));
        
        const u32 usiz = siz( u );
        u32 c = 1;
        for(; c < usiz; ++c ){
            if( c < u [c] ){ break; }
        }
        return c;
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
        auto n = load_scalar<u32>();
        Algorithm( n ).pusk();
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
