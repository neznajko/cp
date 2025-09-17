////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Knight Moves Grid
////////////////////////////////////////////////////////////////
// Time limit: 1.00 s
// Memory limit: 512 MB
////////////////////////////////////////////////////////////////
// There is a knight on an n x n chessboard. For each square,
// print the minimum number of moves the knight needs to do to
// reach the top-left corner.
////////////////////////////////////////////////////////////////
// Input
// The only line has an integer n.
// Output
// Print the number of moves for each square.
////////////////////////////////////////////////////////////////
// Constraints
// 4 <= n <= 1000
////////////////////////////////////////////////////////////////
// Example
// Input:
// 8
// Output:
// 0 3 2 3 2 3 4 5 
// 3 4 1 2 3 4 3 4 
// 2 1 4 3 2 3 4 5 
// 3 2 3 2 3 4 3 4 
// 2 3 2 3 4 3 4 5 
// 3 4 3 4 3 4 5 4 
// 4 3 4 3 4 5 4 5 
// 5 4 5 4 5 4 5 6 
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
////////////////////////////////////////////////////////////////
class Queue {
public:
    Queue( u32 n ):
        n( n ),
        a( v<u32>( n ))
    {}
    void push( u32 y ){
        a[ tail++ ] = y;
    }
    u32 pop() {
        return a[ head++ ];
    }
    b8l empty() {
        return head >= tail;
    }
private:
    const u32 n;
    v<u32> a;
    u32 head = 0;
    u32 tail = 0;
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Algorithm {
public:
    Algorithm( i32 n ):
        n( n ),
        h( n + 4 ),
        w( n + 2 ),
        b( v<i32>( h * w, -1 ))
    {
        i32 src = off( 0, 0 );
        i32 dst = off( 1, w - 1 );
        for( i32 i = src; i <= dst; ++i ){
            b [i] = 0;
        }
        src = off( h - 2, 0 );
        dst = off( h - 1, w - 1 );
        for( i32 i = src; i <= dst; ++i ){
            b [i] = 0;
        }
        for( i32 i = 2; i < h - 2; ++i ){
            b [off( i, 0 )] = b [off( i, w - 1 )] = 0;
        }
        moves = { - (2 * w) + 1,
                  - w + 2,
                  + w + 2,
                  + (2 * w) + 1,
                  + (2 * w) - 1,
                  + w - 2,
                  - w - 2,
                  - (2 * w) - 1 };
    }
    void pusk() {
        u32 start = off( 2, 1 );
        Queue q( n * n );
        q.push( start );
        b [start] = 0;
        while( !q.empty() ){
            auto k = q.pop();
            for( auto m: moves ){
                if( b [k + m] == -1 ){
                    q.push( k + m );
                    b [k + m] = b[k] + 1;
                }
            }
        }
        output();
    }
private:
    const i32 n;
    const i32 h;
    const i32 w;
    v<i32> b;
    v<i32> moves;
    i32 off( i32 rank, i32 file ) const {
        return rank * w + file;
    }
    void output() const {
        for( i32 i = 2; i < h - 2; ++i ){
            for( i32 j = 1; j < w - 1; ++j ){
                cout << b [off( i, j )] << sp;
            }
            cout << nl;
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
        auto n = load_scalar<i32>();
        Algorithm( n ).pusk();
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
