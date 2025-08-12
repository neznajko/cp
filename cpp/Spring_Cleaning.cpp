////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// ADACLEAN - Ada and Spring Cleaning
////////////////////////////////////////////////////////////////
// Ada the Ladybug has decided to do some "Spring Cleaning". As
// you might know, she keeps a TODO list. She is very sparing so
// she keeps all her activities as one string. You might get
// very confused while reading the string but she has a system -
// every activity has length exactly K characters. Sadly, as new
// activities were added to the list many duplicities
// appeared. Now it is time to find out how many unique
// activities are in her TODO list.
////////////////////////////////////////////////////////////////
// Input
// First line contains T, number of test-cases.
////////////////////////////////////////////////////////////////
// Each test-case begins with N, K, 1 ≤ K ≤ N ≤ 10^5, length of
// string and length of activities respectively.
////////////////////////////////////////////////////////////////
// Next line consists of string of length N, consisting of
// lowercase letters.
////////////////////////////////////////////////////////////////
// The sum of lengths of strings among all test-cases won't
// exceed 3*10^5
////////////////////////////////////////////////////////////////
// Output
// For each test-case, print the number of unique substrings of
// length K
////////////////////////////////////////////////////////////////
// Example Input  # hash(s[0:K])=sum{ y[j]p[j]: 0<=j<K } mod M #
// 5              # y[j]=s[j]-'a'+1 ############################
// 3 2            # p[j]=P**j ##################################
// aaa            ##############################################
// 5 1            # h[0]=y[0]+p(y[1]+y[2]p[1]+..+y[K-1]p[K-2]) # mod M
// abcba          # h[0]:=hash(s[0:K]) #########################
// 4 2            ##############################################
// abac           # h[0]-y[0]=p(y[1]+y[2]p[1]+..+y[K-1]p[K-2]) # mod M
// 10 2           ##############################################
// abbaaaabba     # q: pq mod M = 1 ############################
// 7 3            # q(h[0]-y[0])=y[1]+y[2]p[1]+..+y[K-1]p[K-2] # mod M
// dogodog        # q(h[0]-y[0]) + y[K]p[K-1] = h[1] ###########
// Example Output ##############################################
// 1              # h[i+1] = q(h[i]-y[i]) + y[i+K]p[K-1] mod M #
// 3              ##############################################
// 3              ##############################################
// 4              ##############################################
// 4              ##############################################
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
# include <algorithm>
# include <utility>
# include <unordered_set>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
# define OVERLOAD_OSTREAM_OPERATOR( Container )                \
template <typename... T>                                       \
ostream& operator<<( ostream& os, const Container<T...>& con ){\
    os << "[ ";                                                \
    for( const auto& y: con ) os << y << " ";                  \
    return os <<"]";                                           \
}
OVERLOAD_OSTREAM_OPERATOR( vector );
OVERLOAD_OSTREAM_OPERATOR( unordered_set );
////////////////////////////////////////////////////////////////
template <typename A, typename B>
ostream& operator<<( ostream& os, const pair<A, B>& p ){
    return os << "(" << p.first << ", " << p.second << ")";
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int u32;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
pair<i64, i64> eEuclid( u64 a, u64 b ){
    if( b == 0 ){ return { 1, 0 }; }
    auto p = eEuclid( b, a % b );
    auto x = p.first;
    auto y = p.second;
    return { y, x - (a / b * y) };
}
////////////////////////////////////////////////////////////////
u64 modulo_inverse( u64 n, u64 mod ){
    auto p = eEuclid( mod, n );
    auto y = p.second;
    return (y < 0) ? y + mod : y;
}
////////////////////////////////////////////////////////////////
inline u64 W( char ch ){
    return ch - 'a' + 1;
}
////////////////////////////////////////////////////////////////
class Hasher {
public:
    Hasher( u64 P, u64 MOD ):
        P( P ),
        MOD( MOD ),
        Q( modulo_inverse( P, MOD ))
    {}
    u64 initialize( u32 k, const string& s ){
        p = 1;
        h = W( s[0] );
        for( int i = 1; i < k; ++i ){
            p = p * P % MOD;
            u64 y = W( s[i] ) * p % MOD;
            h = (h + y) % MOD;
        }
        return h;
    }
    u64 roll( u64 head, u64 tail ){
        h = (h - head + MOD) % MOD;
        h = h * Q % MOD;
        u64 y = tail * p % MOD;
        h = (h + y) % MOD;
        return h;
    }
private:
    const u64 P;
    const u64 MOD;
    const u64 Q;
    u64 p;
    u64 h;
};
////////////////////////////////////////////////////////////////
u64 pack( u64 h, u64 g ){
    return (h << 32) | g;
}
////////////////////////////////////////////////////////////////
// #############################################################
// #############################################################
// #############################################################
// #############################################################
////////////////////////////////////////////////////////////////
int main() {
    if( 0 ){
    } else {        
        u32 t; cin >> t;
        while( t-- ){
            u32 n, k; cin >> n >> k;
            string s; cin >> s;
            Hasher a( 31, 1'000'000'009 );
            Hasher b( 29, 1'000'000'007 );
            u64 h = a.initialize( k, s );
            u64 g = b.initialize( k, s );
            unordered_set<u64> uset{ pack( h, g )};
            for( int i = 1; i + k - 1 < n; ++i ){
                u64 head = W(s[i - 1]);
                u64 tail = W(s[i + k - 1]);
                h = a.roll( head, tail );
                g = b.roll( head, tail );
                uset.insert( pack( h, g ));
            }
            cout << uset.size() << endl;
        }
    }
}           
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Exercise 1.4.2. Let A ⊆ R be nonempty and bounded above, and
// let s ∈ R have the property that for all n ∈ N, s + 1/n is an
// upper bound for A and s − 1/n is not an upper bound for
// A. Show s = sup A.
//
// Ok we have to prove that:
// (a) s is an upper bound for A
// (b) if b is another upper bound then s ≤ b
//
// (a) let suppose that there is some a ∈ A: s < a, from the
// Archimedean Property if follows that we can always found
// n ∈ N: 1/n < y for any real y > 0, zo if we substitute,
// y := a - s we get a - s > 1/n, a > s + 1/n, vhich is not true
// cos s + 1/n is an upper bound for any n ∈ N                 «
//
// (b) here again let b is an upper bound less then s, then we
// can always find n ∈ N: 1/n < s - b, that is b < s - 1/n, but
// for any n ∈ N s - 1/n is not an upper bound                 «
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// TIME                                                     0.62
// MEM                                                      7.4M
