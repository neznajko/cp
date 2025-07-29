////////////////////////////////////////////////////////////////
// codeforces.com/contest/2126/problem/E
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// YES NO YES YES NO YES NO YES NO NO NO NO YES NO NO YES NO YES
// NO YES NO NO YES YES NO NO YES NO NO YES NO NO NO NO NO NO NO
// YES NO NO YES NO NO YES NO YES NO NO YES YES NO NO YES NO YES
// NO NO YES NO NO YES NO YES NO NO YES NO NO YES NO YES YES YES
// NO YES NO YES YES YES YES NO NO NO NO YES NO YES NO NO YES NO
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
template <typename T>
ostream& operator<<( ostream& os, const vector<T>& vec ){
    string sep = "";
    for( const auto& value: vec ){
        os << sep << value;
        sep = " ";
    }
    return os;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
const string NOPE = "NO";
const string OKAY = "YES";
////////////////////////////////////////////////////////////////
int gcd( int m, int n ){
    if( n == 0 ) return m;
    return gcd( n, m % n );
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
string Lets_roll( const int n,
                  const vector<int>& p,
                  const vector<int>& s ){
    //
    //
    int g = s.front();
    if( p.back() != g ) return NOPE;
    //
    //
    for( int i = 1; i < n; ++i ){
        if( p[i - 1] % p[i] ) return NOPE;
        if( s[i] % s[i - 1] ) return NOPE;
    }
    //
    //
    for( int i = 0; i < n; ++i ){
        if( gcd( p[i], s[i] ) != g ) return NOPE;
    }
    //
    //
    // p[i] = gcd( p[i - 1], a[i] ), 1 <= i < n
    // s[i] = gcd( a[i], s[i + 1] ), 0 <= i < n - 1
    // 
    // gcd( p[i - 1]/ p[i], a[i]/ p[i] ) = 1
    // gcd( s[i + 1]/ s[i], a[i]/ s[i] ) = 1
    //
    // a[i] := lcm( p[i], s[i] ) * y
    //       = p[i] * s[i] * y / g
    //
    // gcd( p[i - 1]/ p[i], ( s[i]/ g ) * y ) = 1
    // gcd( s[i + 1]/ s[i], ( p[i]/ g ) * y ) = 1
    //
    // we must have:
    // gcd( p[i - 1]/ p[i], s[i]/ g ) = 1
    // gcd( s[i + 1]/ s[i], p[i]/ g ) = 1
    //
    for( int i = 1; i < n; ++i ){
        if( gcd( p[i - 1]/ p[i], s[i]/ g ) != 1 ){
            return NOPE;
        }
    }
    for( int i = 0; i < n - 1; ++i ){
        if( gcd( s[i + 1]/ s[i], p[i]/ g ) != 1 ){
            return NOPE;
        }
    }
    return OKAY;
}
////////////////////////////////////////////////////////////////
//       0   1   2   3   4   5   6
// p =  72  24   3   3   3   3
// s =   3   3   3   6  12 144
////////////////////////////////////////////////////////////////
int main() {
    if( 0 ){
    } else {
        int t; cin >> t;
        while( t-- ){
            int n; cin >> n;
            vector<int> p( n );
            vector<int> s( n );
            for( auto& y: p ) cin >> y;
            for( auto& y: s ) cin >> y;
            cout << Lets_roll( n, p, s ) << endl;
        }
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// <> 2.1.47*: Find the acceleration of the bodies of the system
// shown in the figure. The force F is applied i n the direction
// of the thread to one of the bodies of mass m. The sections of
// the thread on either side o f the light block attached to the
// body of mass M are parallel
//
//        +---+   T     T
//   <----| 1 |--->-----<---#####        +-------+
//   F    +---+            #     #       |       |
//                        #   #   #------|   3   |
//            +---+   T    #     #       |       |
//            | 2 |--->-<---#####        +-------+
//            +---+     T
//
// <------------------------------------------posi4ive----------
//
// m₁ = m₂ = m, m₃ = M
//               
// F - T = m a₁ (1)
// -T = m a₂    (2)
// 2T = M a₃    (3)
//
// In system moving with a₃, 1 and 2 will have oposite and 
// equal accelerations: a₁ - a₃ = -( a₂ - a₃ ) = -a₂ + a₃
// a₁ + a₂ = 2a₃ (4)
//
// (1) + (2): F - 2T = m(a₁ + a₂) = 2ma₃, so F = 2T + 2ma₃ = 
// = Ma₃ + 2ma₃ = a₃(M + 2m)
// a₃ = F/(M + 2m)                                             «
// T = M a₃ / 2 = MF/2(M + 2m)
// a₂ = - T/m = -MF/2m(M + 2m)                                 « 
// a₁ = 2a₃ - a₂ = 2F/(M + 2m) + MF/2m(M + 2m) =
// F/(M + 2m)[ 2 + M/2m) = F/(M + 2m)[4m + M]/2m,
// a₁ = F(4m + M)/2m(M + 2m)                                   «         
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
