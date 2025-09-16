////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Raab Game I
////////////////////////////////////////////////////////////////
// Time limit: 1.00 s
// Memory limit: 512 MB
////////////////////////////////////////////////////////////////
// Consider a two player game where each player has n cards
// numbered 1,2,...,n. On each turn both players place one of
// their cards on the table. The player who placed the higher
// card gets one point. If the cards are equal, neither player
// gets a point. The game continues until all cards have been
// played.  You are given the number of cards n and the players'
// scores at the end of the game, a and b. Your task is to give
// an example of how the game could have played out.
////////////////////////////////////////////////////////////////
// Input
// The first line contains one integer t: the number of tests.
// Then there are t lines, each with three integers n, a and b.
////////////////////////////////////////////////////////////////
// Output
// For each test case print YES if there is a game with the
// given outcome and NO otherwise.  If the answer is YES, print
// an example of one possible game. Print two lines representing
// the order in which the players place their cards. You can
// give any valid example.
////////////////////////////////////////////////////////////////
// Constraints
// 1 <= t <= 1000
// 1 <= n <= 100
// 0 <= a,b <= n
////////////////////////////////////////////////////////////////
// Example
// Input:
// 5
// 4 1 2
// 2 0 1
// 3 0 0
// 2 1 1
// 4 4 1
// Output:
// YES
// 1 4 3 2
// 2 1 3 4
// NO
// YES
// 1 2 3
// 1 2 3
// YES
// 1 2
// 2 1
// NO
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
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Algorithm {
public:
    Algorithm( u32 n, u32 a, u32 b ):
        n( n ),
        a( a ),
        b( b )
    {}
    void pusk() {
        if( (a + b > n) or
            (a == 0 and b != 0) or
            (a != 0 and b == 0) ){
            cout << "NO" << nl;
            return;
        }
        vu32 player1;
        vu32 player2;
        for( u32 i = b + 1; i <= b + a; ++i ){
            player1.PSH( i );
            player2.PSH( i - b );
        }
        for( u32 i = 1; i <= b; ++i ){
            player1.PSH( i );
            player2.PSH( i + a );
        }
        for( u32 i = a + b + 1; i <= n; ++i ){
            player1.PSH( i );
            player2.PSH( i );
        }
        cout << "YES" << nl
             << player1 << nl
             << player2 << nl;
    }
private:
    const u32 n;
    const u32 a;
    const u32 b;
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main() {
    vrooom();
    if( 0 ){
    } else {
        CONT = { "", "", " " };
        FOR_THE_HORDE {
            auto n = load_scalar<u32>();
            auto a = load_scalar<u32>();
            auto b = load_scalar<u32>();
            Algorithm( n, a, b ).pusk();
        }
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
