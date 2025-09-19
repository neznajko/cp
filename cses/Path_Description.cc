////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Grid Path Description
////////////////////////////////////////////////////////////////
// Time limit: 1.00 s
// Memory limit: 512 MB
////////////////////////////////////////////////////////////////
// There are 88418 paths in a 7 x 7 grid from the upper-left
// square to the lower-left square. Each path corresponds to a
// 48-character description consisting of characters D (down), U
// (up), L (left) and R (right). For example, the path
// corresponds to the description
// DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD. You are
// given a description of a path which may also contain
// characters ? (any direction). Your task is to calculate the
// number of paths that match the description.
////////////////////////////////////////////////////////////////
// Input
// The only input line has a 48-character string of characters
// ?, D, U, L and R.
////////////////////////////////////////////////////////////////
// Output
// Print one integer: the total number of paths.
////////////////////////////////////////////////////////////////
// Example
// Input:
// ??????R??????U??????????????????????????LD????D?
// Output:
// 201
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
////////////////////////////////////////////////////////////////
# define dbg2( a, b ) dbg( a ); dbg( b )
# define dbg3( a, b, c ) dbg2( a, b ); dbg( c )
# define dbg4( a, b, c, d ) dbg3( a, b, c ); dbg( d )
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// 0 1 2 3 
// 4 5 6 7
// 8 9 a b
// c d e f
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Algorithm {
public:
    Algorithm( const str& s ):
        n( siz( s )),
        s( s ),
        h( sqrt( n + 1 )),
        g( w<u32>( h + 2, v<u32>( h + 2, 1 )))
    {
        for( u32 i = 1; i <= h; ++i ){
            for( u32 j = 1; j <= h; ++j ){
                g [i][j] = 0;
            }
        }
    }
    void pusk() {
        dbg( g );
        dfs( 1, 1, 0 );
        cout << c << nl;
    }
private:
    const u32 n;
    const str& s;
    u32 c = 0;//ounter
    u32 h = 0;//eight
    w<u32> g;//rid
    u32 Manhattan_Distance( u32 i, u32 j ){
        return j - 1 + h - i;
    }
    b8l voila( u32 i, u32 j ){
        return i == h and j == 1;
    }
    void dfs( u32 i, u32 j, u32 off ){
        if( voila( i, j )){
            if( off == n ){ ++c; }
            return;
        }
        if( Manhattan_Distance( i, j ) > n - off ){ return; }

        b8l up_free   = !g [i - 1][j];
        b8l left_free = !g [i][j - 1];
        b8l down_free = !g [i + 1][j];
        b8l ryte_free = !g [i][j + 1];

        if( !up_free and !down_free and left_free and ryte_free ){
            return;
        }
        if( !left_free and !ryte_free and up_free and down_free ){
            return;
        }

        b8l wildcard = s[ off ] == '?';
        b8l go_up    = s[ off ] == 'U' or wildcard;
        b8l go_left  = s[ off ] == 'L' or wildcard;
        b8l go_down  = s[ off ] == 'D' or wildcard;
        b8l go_ryte  = s[ off ] == 'R' or wildcard;

        ++off;
        g [i][j] = 1;
        
        if( up_free   and   go_up ){ dfs( i - 1, j, off ); }
        if( left_free and go_left ){ dfs( i, j - 1, off ); }
        if( down_free and go_down ){ dfs( i + 1, j, off ); }
        if( ryte_free and go_ryte ){ dfs( i, j + 1, off ); }
        
        g [i][j] = 0;
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
        auto s = load_scalar<str>();
        CONT.open_bracket = "\n[";
        Algorithm( s ).pusk();
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
