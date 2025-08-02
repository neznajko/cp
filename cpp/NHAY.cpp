////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
# include <deque>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
template <template <typename...> class Barracks, typename T>
ostream& operator<<( ostream& os, const Barracks<T>& marines ){
    os << "[ ";
    for( const auto& marine: marines ){
        os << marine << " ";
    }
    return os << "]";
}
////////////////////////////////////////////////////////////////
// NHAY - A Needle in the Haystack
// #############################################################
// Write a program that finds all occurences of a given pattern
// in a given input string. This is often referred to as finding
// a needle in a haystack.
// #############################################################
// The program has to detect all occurences of the needle in the
// haystack. It should take the needle and the haystack as
// input, and output the positions of each occurence, as shown
// below. The suggested implementation is the KMP algorithm, but
// this is not a requirement. However, a naive approach will
// probably exceed the time limit, whereas other algorithms are
// more complicated... The choice is yours.
// #############################################################
// Input
// #############################################################
// The input consists of a number of test cases. Each test case
// is composed of three lines, containing:
// #############################################################
// the length of the needle,
// the needle itself,
// the haystack.
// #############################################################
// The length of the needle is only limited by the memory
// available to your program, so do not make any assumptions -
// instead, read the length and allocate memory as needed. The
// haystack is not limited in size, which implies that your
// program should not read the whole haystack at once. The KMP
// algorithm is stream-based, i.e. it processes the haystack
// character by character, so this is not a problem.
// #############################################################
// The test cases come one after another, each occupying three
// lines, with no additional space or line breaks in between.
// #############################################################
// Output
// #############################################################
// For each test case your program should output all positions
// of the needle's occurences within the haystack. If a match is
// found, the output should contain the position of the first
// character of the match. Characters in the haystack are
// numbered starting with zero.
// #############################################################
// For a given test case, the positions output should be sorted
// in ascending order, and each of these should be printed in a
// separate line. For two different test cases, the positions
// should be separated by an empty line.
// #############################################################
// Example
// #############################################################
// Sample input:
// 2
// na
// banananobano
// #############################################################
// 6
// foobar
// foo
// #############################################################
// 9
// foobarfoo
// barfoobarfoobarfoobarfoobarfoo
// #############################################################
// Sample output:
// 2
// 4
//
//
// 3
// 9
// 15
// 21
// #############################################################
// Note the double empty line in the output, which means that no
// match was found for the second test case.
// #############################################################
// Warning: large Input/Output data, be careful with certain
// languages
// #############################################################
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
typedef unsigned long long u64;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// The text suggest using KMP, which is a really beautiful
// solution without the need of hashing, but this is in the
// section Hashing in cp, so the idea is that we receive the
// string as stream, and we have to update the current hash by
// removing the first character and add new, if we use the
// normal hashing function, then we need to deal with inverse
// modulo arithmetic, the trick here is to reverse the order of
// the powers in the hash function
////////////////////////////////////////////////////////////////
// t[0..n-1]:
// g = t[0]p^(n-1) + t[1]p^(n-2) + ... + t[n-1] mod m
// t[1..n]:
// pg - t[0]p^n = t[1]p^(n-1) + ... + t[n-1]p mod m
// g <- pg - t[0]p^n + t[n] mod m =
//      p(g - t[0]p^(n-1)) + t[n] mod m
////////////////////////////////////////////////////////////////
template <int P, int MOD> 
////////////////////////////////////////////////////////////////
class ReverseHasher {
public:
    ReverseHasher( int n, const string& s )
        : n( n ),
          p( vector <u64> ( n )),
          deq( deque <int> ( n ))
    {
        initialize( s );
    }
    int roll( char ch )
    {
        int value = ascii( ch );
        u64 front = deq.front() * p[n - 1] % MOD;
        g = ( g + MOD - front ) % MOD;
        g = ( P * g + value ) % MOD;
        deq.pop_front();
        deq.push_back( value );
        ++j;
        return ( g == h ) ? j - n : -1;
    }
private:
    const int n;
    int j = 0; // current offset of the streamed character
    u64 h; // static needle hash
    u64 g = 0; // the rolling hash
    vector <u64> p;
    deque <int> deq;
    //
    int ascii( char ch ){
        return ch - 'a' + 1;
    }
    void initialize( const string& s )
    {
        p[0] = 1;
        for( int i = 1; i < n; ++i ){
            p[i] = P * p[i - 1];
            p[i] %= MOD;
        }
        h = 0;
        for( int i = n - 1; i >= 0; --i ){
            h += ascii( s[i] ) * p[n - i - 1];
            h %= MOD;
        }
    }
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class NHAY {
public:
    NHAY( int n, const string& s )
        : rh1( RH1( n, s )),
          rh2( RH2( n, s ))
    {
    }
    void push( char ch )
    {
        int i = rh1.roll( ch );
        int j = rh2.roll( ch );
        if( i == j && j != -1 ){
            ofsets.push_back( j );
        }
    }
    void dump() {
        if( ofsets.empty() ){
            cout << endl << endl;
        } else {
            for( int ofset: ofsets ){
                cout << ofset << endl;
            }
        }
    }
private:
    using RH1 = ReverseHasher <31, 1'000'000'009>;
    using RH2 = ReverseHasher <29, 1'000'000'7>;
    RH1 rh1;
    RH2 rh2;
    vector <int> ofsets;
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main()
{
    int n;
    string s;
    while( cin >> n >> s ){
        NHAY nhay( n, s );
        cin.ignore(); // newline
        while( int ch = cin.get() ){
            if( ch == '\n' or ch == EOF ){ break; }
            nhay.push( ch );
        }
        nhay.dump();
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// C. 33. If a > 0 and b > 0, prove that [a,b] = ab/(a,b)
//
// [a,b] is the least common multiple of a and b,
// (a,b) is the greatest common divisor of a and b
//
// let t := ab/(a,b), we have to prove that
//
// 1) a|t and b|t:
//
//    a = u(a,b), for some u in N, zo t = ub => b|t
//    b = v(a,b), for some v in N, zo t = va => a|t
//
// 2) if s: a|s, b|s then s >= t
//    a|s => s = aw = (a,b)uw, for some w in N
//    b = v(a,b) divides s = (a,b)uw as well, that is v|uw, but 
//    (v,u) = 1, otherwise (v,u)(a,b) will divide both a and b,
//    and (a,b) wouldn't be gcd, zo v|w, that is w = kv for some
//    k in N, zo s = k(a,b)uv = kab/(a,b) = kt >= t            «
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// TIME                                                     0.90
// MEM                                                      5.2M
