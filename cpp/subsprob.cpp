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
# include <unordered_set>
# include <unordered_map>
////////////////////////////////////////////////////////////////
// SUB_PROB - Substring Problem
//////////////////////////////////////////////////////////////// useful
// String matching is an important problem in computer science   inform
// research and finds applications in bioinformatics, data       ation!
// mining, pattern recognition, internet security and many more
// areas.
//////////////////////////////////////////////////////////////// that alpha
// The problem we consider here is a smaller version of it. You  numeric is
// are given a string T and N other strings smaller in length    !important
// than T. You have to find whether each of these N strings is a 
// substring of T. All strings consist of only alphanumeric
// characters.
////////////////////////////////////////////////////////////////
// Input
////////////////////////////////////////////////////////////////
// Input to the program consists of a series of lines. The first
// line contains the string T (no more than 100000 characters
// long). The next line contains an integer N (<1000) the number
// of query strings. Each of the next N lines contain a string S
// (each of which is no more than 2000 characters long).
////////////////////////////////////////////////////////////////
// Output
////////////////////////////////////////////////////////////////
// Output should consist of N lines each with a character 'Y' or
// 'N' indicating whether the string S is a substring of string
// T or not.
////////////////////////////////////////////////////////////////
// Example
// Input:
// abghABCDE
// 2
// abAB
// ab
////////////////////////////////////////////////////////////////
// Output:
// N
// Y
////////////////////////////////////////////////////////////////
// Note: The test data for this problem not only consist of the
// official test cases from the contest, as well some cases of
// my own.
////////////////////////////////////////////////////////////////
// A test case was added on 25.7.2010, after rejudging 3 users  
// lose accepted.                                                haHa
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
OVERLOAD_OSTREAM_OPERATOR( unordered_map );
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
typedef unsigned long long u64;
////////////////////////////////////////////////////////////////
const u64 P = 79; // 0-9 A-Z a-z
const u64 M = 1'000'000'079;
////////////////////////////////////////////////////////////////
vector<u64> p; // powers of P
vector<u64> h; // hash prefixes
////////////////////////////////////////////////////////////////
void precompute( const string& t ){
    const int n = t.size();
    p.resize( n );
    p[0] = 1;
    for( int i = 1; i < n; ++i ){
        p[i] = p[i - 1] * P % M;
    }
    h.resize( n + 1 ); // for convenience
    h[0] = 0;
    for( int i = 0; i < n; ++i ){
        u64 y = (t[i] - '0' + 1) * p[i] % M;
        h[i + 1] = (h[i] + y) % M;
    }
}
u64 calculate_hash( const string& s ){
    const int n = s.size();
    u64 g = 0;
    for( int i = 0; i < n; ++i ){
        u64 y = (s[i] - '0' + 1) * p[i] % M;
        g = (g + y) % M;
    }
    return g;
}
unordered_set<u64> rabin_karp( const int L ){
    const int n = p.size();
    if( L > n ) return {};
    unordered_set<u64> bag;
    for( int i = 0; i + L - 1 < n; i++ ){
        u64 g = (h[i + L] + M - h[i]) % M;
        bag.insert( g * p[n - i - 1] % M );
    }
    return bag;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
# define READ( name ) cin >> name
////////////////////////////////////////////////////////////////
int main() {
    if( 0 ){
    } else {
        string t;
        int n;
        READ( t );
        READ( n );
        unordered_set<int> lens;
        vector<string> subs( n );
        precompute( t );
        for( auto &s: subs ){
            READ( s );
            lens.insert( s.size());
        }
        unordered_map<int, unordered_set<u64>> buckets;
        for( int L: lens ){
            buckets[L] = rabin_karp( L );
        }
        for( const auto& s: subs ){
            u64 g = calculate_hash( s ) * p.back() % M;
            if( buckets[ s.size() ].count( g )){
                cout << "Y" << endl;
            } else {
                cout << "N" << endl;
            }
        }
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// @ @@@ @@######## м                     ковеме стихчета 
//    @             о                     с мойте френдове
// @ @   @@######## р                     ново хоби 
// @ @@ @         # е                     рисуване c думи :)
//    @@@ @## ### #                       
// = ====     /// /                       
// == === =//     /                       
// =   == =// /// /
//    ===         /
// = ======////// / 海 
// 
// The gentle breeze  
// The boat in the blue sea  
// The sound of splashing waves  
// And your eyes, casting spells on me
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// TIME                                                     0.16
// MEM                                                      6.8M
