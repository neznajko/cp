////////////////////////////////////////////////////////////////
// leetcode.com/problems/longest-duplicate-substring/
////////////////////////////////////////////////////////////////
// Given a string s, consider all duplicated substrings:
// (contiguous) substrings of s that occur 2 or more times. The
// occurrences may overlap.
////////////////////////////////////////////////////////////////
// Return any duplicated substring that has the longest possible
// length. If s does not have a duplicated substring, the answer
// is "".
////////////////////////////////////////////////////////////////
// Input: s = "banana"
// Output: "ana"
// Example 2:
////////////////////////////////////////////////////////////////
// Input: s = "abcd"
// Output: ""
////////////////////////////////////////////////////////////////
// 2 <= s.length <= 3 * 10^4
// s consists of lowercase English letters.
////////////////////////////////////////////////////////////////
# include <string>
# include <vector>
# include <memory>
# include <iostream>
# include <unordered_set>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
typedef unsigned long long u64;
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
template <class T>
ostream& operator <<( ostream& _, const vector <T> &vec ){
    for( const auto& coord: vec ){
        _ << coord << " ";
    }
    return _;
}
////////////////////////////////////////////////////////////////
struct Hash {
    static const int P = 31;
    const int n;
    const string& s;
    vector <u64> powr;
    vector <u64> hash;
    Hash( const string& s ):
        n( s.size() ),
        s( s ),
        powr( vector <u64> ( n )),
        hash( vector <u64> ( n + 1 ))
    {}
    void Identify_yourself() {
        powr[0] = 1;
        for( int j = 1; j < n; ++j ){
            powr[j] = powr[j - 1] * P;
        }
        for( int j = 0; j < n; ++j ){
            hash[j + 1] = hash[j] + ascii::digit( s[j] ) * powr[j];
        }
    }
    u64 All_crews_reporting( int i, int j ){
        u64 h = hash[j + 1] - hash[i];
        return h * powr[n - i - 1];
    }
};
////////////////////////////////////////////////////////////////
struct Solution {
    unique_ptr <Hash> hash;
    string longestDupSubstring( const string& s ){
        hash = make_unique <Hash> ( s );
        hash->Identify_yourself();
        return I_gotcha();
    }
    int This_is_Jimmy( int len ){
        unordered_set <u64> set;
        const int n = hash->n;
        for( int i = 0; i <= n - len; ++i ){
            int j = i + len - 1;
            u64 h = hash->All_crews_reporting( i, j );
            if( set.count( h ) > 0 ){
                return i;
            }
            set.insert( h );                
        }
        return -1;
    }    
    string I_gotcha() {
        int l = 1;
        int u = hash->n;
        int ofst = -1;
        while( l <= u ){
            int m = ( l + u )/ 2;
            int i = This_is_Jimmy( m );
            if( i != -1 ){
                ofst = i;
                l = m + 1;
            } else {
                u = m - 1;
            }
        }        
        return ofst == -1 ? "" : hash->s.substr( ofst, u );
    }
};
////////////////////////////////////////////////////////////////
int main() {
    string s;
    cin >> s;
    cout << Solution().longestDupSubstring( s ) << endl;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Runtime:                                658 ms | Beats 87.04%
// Memory:                              214.23 MB | Beats 83.40%
