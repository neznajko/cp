////////////////////////////////////////////////////////////////
// codeforces.com/contest/271/problem/D
////////////////////////////////////////////////////////////////
// D. Good Substrings
////////////////////////////////////////////////////////////////
// time limit per test 2 seconds
// memory limit per test 512 megabytes
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// You've got string s, consisting of small English letters.
// Some of the English letters are good, the rest are bad.
////////////////////////////////////////////////////////////////
// A substring s[l...r] (1 ≤ l ≤ r ≤ |s|) of string
// s = s1s2...s|s| (where |s| is the length of string s) is
// string  slsl + 1...sr.
////////////////////////////////////////////////////////////////
// The substring s[l...r] is good, if among the letters
// sl, sl + 1, ..., sr there are at most k bad ones (look at the
// sample's explanation to understand it more clear).
////////////////////////////////////////////////////////////////
// Your task is to find the number of distinct good substrings
// of the given string s. Two substrings s[x...y] and s[p...q]
// are considered distinct if their content is different, i.e.
// s[x...y] ≠ s[p...q].
////////////////////////////////////////////////////////////////
// Input
// The first line of the input is the non-empty string s,
// consisting of small English letters, the string's length is
// at most 1500 characters.
////////////////////////////////////////////////////////////////
// The second line of the input is the string of characters "0"
// and "1", the length is exactly 26 characters. If the i-th
// character of this string equals "1", then the i-th English
// letter is good, otherwise it's bad. That is, the first
// character of this string corresponds to letter "a", the
// second one corresponds to letter "b" and so on.
////////////////////////////////////////////////////////////////
// The third line of the input consists a single integer k
// (0 ≤ k ≤ |s|) — the maximum acceptable number of bad
// characters in a good substring.
////////////////////////////////////////////////////////////////
// Output
// Print a single integer — the number of distinct good
// substrings of string s.
////////////////////////////////////////////////////////////////
// Examples
// Input
// ababab
// 01000000000000000000000000
// 1
// Output
// 5
// Input
// acbacbacaa
// 00000000000000000000000000
// 2
// Output
// 8
////////////////////////////////////////////////////////////////
// Note
// In the first example there are following good substrings:
// "a", "ab", "b", "ba", "bab".
//
// In the second example there are following good substrings:
// "a", "aa", "ac", "b", "ba", "c", "ca", "cb".
////////////////////////////////////////////////////////////////
# include <string>
# include <vector>
# include <utility>
# include <iostream>
# include <unordered_set>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
typedef long long i64;
////////////////////////////////////////////////////////////////
template <typename T>
ostream& operator <<( ostream& _, const vector <T> &vec ){
    for( const auto& el: vec ){
        _ << el << " ";
    }
    return _;
}
////////////////////////////////////////////////////////////////
namespace ascii {
    constexpr int ofst( char c ){
        return c - 'a';
    }
    constexpr int digit( char c ){
        return ofst( c ) + 1;
    }
}
////////////////////////////////////////////////////////////////
struct GoodSubstrings {
    static const int P = 31;
    static const int MOD = ( int )( 1e9 + 9 );
    const int n;
    const string& s;
    const string& ok;
    const int k;
    vector <int> pref;
    vector <i64> hash;
    vector <i64> powr;
    GoodSubstrings( const string& s,
                    const string& ok,
                    const int k ):
        n( s.size() ),
        s( s ),
        ok( ok ),
        k( k ),
        pref( vector <int> ( n + 1 )),
        hash( vector <i64> ( n + 1 )),
        powr( vector <i64> ( n + 1 )){
    }
    bool Checked_up_and_good_to_go( char c ){
        return ok[ ascii::ofst( c )] == '1';
    }
    GoodSubstrings& I_can_t_build_there() {
        powr[0] = 1;
        for( int j = 0; j < n; ++j ){
            char c = s[j];
            powr[j + 1] = ( powr[j] * P ) % MOD;
            pref[j + 1] = pref[j] + !Checked_up_and_good_to_go( c );
            hash[j + 1] = ( hash[j] + ascii::digit( c ) * powr[j] ) % MOD;
        }
        return *this;
    }
    int In_the_pipe_five_by_five() {
        int n = s.size();
        int cnt = 0;
        for( int len = n; len > 0; --len ){
            unordered_set <i64> set;
            for( int j = 0; j <= n - len; ++j ){
                int nfbad = pref[j + len] - pref[j];
                if( nfbad > k ) continue;
                i64 h = ( hash[j + len] + MOD - hash[j] ) % MOD;
                h = ( h * powr[n - j - 1] ) % MOD;
                set.insert( h );
            }
            cnt += set.size();
        }
        return cnt;
    }
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main() {
    string s;
    string ok;
    int k;
    cin >> s >> ok >> k;
    cout << GoodSubstrings( s, ok, k )
        .I_can_t_build_there()
        .In_the_pipe_five_by_five() << endl;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Time:                                                  498 ms
// Memory:                                                100 KB
