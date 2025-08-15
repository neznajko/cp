////////////////////////////////////////////////////////////////
// E. Text Editor
////////////////////////////////////////////////////////////////
// One of the most useful tools nowadays are text editors, their
// use is so important that the Unique Natural Advanced Language
// (UNAL) organization has studied many of the benefits working
// with them.
////////////////////////////////////////////////////////////////
// They are interested specifically in the feature "find", that
// option looks when a pattern occurs in a text, furthermore, it
// counts the number of times the pattern occurs in a text. The
// tool is so well designed that while writing each character of
// the pattern it updates the number of times that the
// corresponding prefix of the total pattern appears on the
// text.
////////////////////////////////////////////////////////////////
// Now the UNAL is working with the editor, finding patterns in
// some texts, however, they realize that many of the patterns
// appear just very few times in the corresponding texts, as
// they really want to see more number of appearances of the
// patterns in the texts, they put a lower bound on the minimum
// number of times the pattern should be found in the text and
// use only prefixes of the original pattern. On the other hand,
// the UNAL is very picky about language, so they will just use
// the largest non-empty prefix of the original pattern that fit
// into the bound.
////////////////////////////////////////////////////////////////
// Input
////////////////////////////////////////////////////////////////
// The first line contains the text A (1 ≤ |A| ≤ 10^5) The
// second line contains the original pattern B (1 ≤ |B| ≤ |A|)
// The third line contains an integer n (1 ≤ n ≤ |A|) - the
// minimum number of times a pattern should be found on the
// text.
////////////////////////////////////////////////////////////////
// Output
////////////////////////////////////////////////////////////////
// A single line, with the prefix of the original pattern used
// by the UNAL, if there is no such prefix then print
// "IMPOSSIBLE" (without the quotes)
////////////////////////////////////////////////////////////////
// Examples     # If the size of the pattern is M and the size #
// Input        # of the string is N, than we can solve the    #
// aaaaa        # problem for O(N log M) time; for all offsets #
// aaa          # 0 <= j < N, we make a binary search of the   #
// 4            # length of the pattern, zo in general after   #
// Output       # that we'll have all the required information #
// aa           #                                              #
// Input        # Cos in the example we have Hello World! I'm  #
// programming  # going to assume 128 alphabet size, with      #
// unal         # double hashing say:                          #
// 1            # P1 = 131, M1 = 1'000'000'009                 #
// Output       # P2 = 137, M2 = 1'000'000'007                 #
// IMPOSSIBLE   # then precompute powers and hashes for S and  #
// Input        # T respectively, and then do the binary srch. #
// abracadabra  # Then what? After that we get mapping         #
// abra         # length of prefix -> count, then we can start #
// 1            # from the rear and check greedily the maximum #
// Output       # lenght that is above the threshold           #
// abra         #                                              #
// Input        # Above the threshold,                         #
// Hello World! # maximum we search                            #
// H W          # until the count is found,                    #
// 5            # unless IMPOSSIBLE                            #
// Output       #                                              #
// IMPOSSIBLE   #                                              #
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
# include <algorithm>
# include <utility>
# include <map>
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
////////////////////////////////////////////////////////////////
template <typename A, typename B>
ostream& operator<<( ostream& os, const pair<A, B>& p ){
    return os << "(" << p.first << ", " << p.second << ")";
}
////////////////////////////////////////////////////////////////
OVERLOAD_OSTREAM_OPERATOR( map );
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
typedef unsigned long long u64;
typedef unsigned int u32;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
template <u64 P, u64 MOD>
class Hasher {
public:
    Hasher( const string& t, const string& s ):
        t( t ),
        s( s )
    { 
        const u32 n = t.size();
        p.resize(n);
        p[0] = 1;
        for( u32 i = 1; i < n; ++i ){
            p[i] = p[i - 1] * P % MOD;
        }

        h.resize(n + 1);
        h[0] = 0;
        for( u32 i = 0; i < n; ++i ){
            u64 y = t[i] * p[i] % MOD;
            h[i + 1] = (h[i] + y) % MOD;
        }

        const u32 m = s.size();
        g.resize(m + 1);
        g[0] = 0;
        for( u32 i = 0; i < m; ++i ){
            u64 y = s[i] * p[i] % MOD;
            g[i + 1] = (g[i] + y) % MOD;
        }
    }
    bool match( u32 i, u32 len ){
        const u32 n = t.size();
        // i:j, len = j - i + 1
        // j = i + len - 1
        // h[j + 1] - h[i]
        u64 y = (h[i + len] + MOD - h[i]) % MOD;
        // h[t[i:j]]*p[i] = h[j + 1] - h[i]
        y = y * p[n - 1 - i] % MOD;
        u64 w = g[len] * p[n - 1] % MOD;

        return y == w;        
    }
private:
    const string& t;
    const string& s;
    vector<u64> p;
    vector<u64> h;
    vector<u64> g;
};
////////////////////////////////////////////////////////////////
using HasherA = Hasher<131, 1'000'000'009>;
using HasherB = Hasher<137, 1'000'000'007>;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Emacs {
public:
    Emacs( const string& t, const string& s, u32 k ):
        t(t),
        s(s),
        k(k),
        a( HasherA( t, s )),
        b( HasherB( t, s ))
    {}
    string 
Above_the_threshold\
maximum_we_search\
until_the_count_is_found\
unless_IMPOSSIBLE() {
        const u32 n = t.size();
        map<u32, u32> f;
        for( u32 j = 0; j < n; ++j ){
            u32 len = binary_search( j );
            if( len ){ ++f[len]; }
        }
        u32 total = 0;
        for( auto it = f.rbegin(); it != f.rend(); ++it ){
            u32 len = it->first;
            u32 count = it->second;
            total += count;
            if( total >= k ){
                return s.substr(0, len);
            }
        }
        return "IMPOSSIBLE";
    }
private:
    const string& t; // the string 
    const string& s; // the pattern 
    u32 k;           // number of matches
    HasherA a;
    HasherB b;
    u32 binary_search( u32 j ){
        u32 l = 1;
        u32 u = min( s.size(), t.size() - j );
        while( l <= u ){
            u32 m = (l + u)/ 2;
            if( a.match( j, m ) and b.match( j, m )){
                l = m + 1;
            } else {
                u = m - 1;
            }
        }
        return u;
    }
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//                                         Светлините заглъхваха
//                                        залеза бавно разливаше
//                                                      огънчета
//                                                    по вълните
//                                                гаснещи горяха
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main(){
    ios::sync_with_stdio( false );
    cin.tie( nullptr );
    if( 0 ){
    } else {
        string t;
        string s;
        u32 k;
        getline( cin, t );
        getline( cin, s );
        cin >> k;
        Emacs emacs( t, s, k );
        cout << emacs.
Above_the_threshold\
maximum_we_search\
until_the_count_is_found\
unless_IMPOSSIBLE() << endl;
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Time                                                   139 ms
// Memory                                                3100 KB
