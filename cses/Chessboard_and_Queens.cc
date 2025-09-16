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
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using vi32 = vector<i32>;
using vu32 = vector<u32>;
using vi64 = vector<i64>;
using vu64 = vector<u64>;
using vb8l = vector<bool>;
using vstr = vector<string>;
using pu32 = pair<u32,u32>;
using vpu32 = vector<pu32>;
using vvchr = vector<vector<char>>;
////////////////////////////////////////////////////////////////
constexpr char nl = '\n';
constexpr char sp = ' ';
constexpr char tab = '\t';
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
istream& operator>>( istream& is, vector<T>& v ){
    for( auto& y: v ){ is >> y; }
    return is;
}
////////////////////////////////////////////////////////////////
template <typename T>
inline vector<T> load_vector( u32 n ) {
    vector<T> y( n ); cin >> y;
    return y;
}
////////////////////////////////////////////////////////////////
template <typename T>
inline vector<vector<T>> load_tensor( u32 n, u32 m ) {
    vector<vector<T>> y( n, vector<T>( m )); cin >> y;
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
    string open_bracket;
    string close_bracket;
    string separator;
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
    string sep = "";                                           \
    for( const auto& y: con ){                                 \
        os << sep << y;                                        \
        sep = CONT.separator;                                  \
    }                                                          \
    return os << CONT.close_bracket;                           \
}
////////////////////////////////////////////////////////////////
template <typename K, typename V>
ostream& operator<<( ostream& os, const pair<K,V>& p ){
    return os << PAIR.open_bracket
              << key( p )
              << PAIR.separator
              << val( p )
              << PAIR.close_bracket;
}
////////////////////////////////////////////////////////////////
OVERLOAD_OSTREAM_OPERATOR( vector );
OVERLOAD_OSTREAM_OPERATOR( set );
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
constexpr u32 BSIZ = 8;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Algorithm {
public:
    Algorithm( const vvchr& b ):
        b( b ),
        col( vb8l( BSIZ )),
        dig1( vb8l( 2 * BSIZ - 1 )),
        dig2( vb8l( 2 * BSIZ - 1 ))
    {}
    void pusk() {
        srch( 0 );
        cout << count << nl;
    }
private:
    const vvchr& b;
    u32 count = 0;
    vb8l col;
    vb8l dig1;
    vb8l dig2;
    void mark( u32 i, u32 j ){
        col [j] = dig1 [i + j] = dig2 [BSIZ - 1 + i - j] = true;
    }
    void unmark( u32 i, u32 j ){
        col [j] = dig1 [i + j] = dig2 [BSIZ - 1 + i - j] = false;
    }
    bool ck( u32 i, u32 j ){
        return (col [j] == false and
                dig1 [i + j] == false and
                dig2 [BSIZ - 1 + i - j] == false and
                b [i][j] == '.');
    }
    void srch( u32 i ){
        if( i == BSIZ ){
            ++count;
        } else {
            for( u32 j = 0; j < BSIZ; ++j ){
                if( ck( i, j )){
                    mark( i, j );
                    srch( i + 1 );
                    unmark( i, j );
                }
            }
        }
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
        auto b = load_tensor<char>( BSIZ, BSIZ );
        CONT = { "[", "]\n", " " };
        Algorithm( b ).pusk();
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
