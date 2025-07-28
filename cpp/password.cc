////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// B. Password
////////////////////////////////////////////////////////////////
// time limit per test2 seconds
// memory limit per test256 megabytes
////////////////////////////////////////////////////////////////
// Asterix, Obelix and their temporary buddies Suffix and Prefix
// has finally found the Harmony temple. However, its doors were
// firmly locked and even Obelix had no luck opening them.
// 
// A little later they found a string s, carved on a rock below
// the temple's gates. Asterix supposed that that's the password
// that opens the temple and read the string aloud. However,
// nothing happened. Then Asterix supposed that a password is
// some substring t of the string s.
// 
// Prefix supposed that the substring t is the beginning of the
// string s; Suffix supposed that the substring t should be the
// end of the string s; and Obelix supposed that t should be
// located somewhere inside the string s, that is, t is neither
// its beginning, nor its end.
// 
// Asterix chose the substring t so as to please all his
// companions. Besides, from all acceptable variants Asterix
// chose the longest one (as Asterix loves long strings). When
// Asterix read the substring t aloud, the temple doors opened.
// 
// You know the string s. Find the substring t or determine that
// such substring does not exist and all that's been written
// above is just a nice legend.
// 
// Input
// You are given the string s whose length can vary from 1 to
// 10^6 (inclusive), consisting of small Latin letters.
// 
// Output
// Print the string t. If a suitable t string does not exist,
// then print "Just a legend" without the quotes.
// 
// Examples
// Input
// fixprefixsuffix
// Output
// fix
// Input
// abcdabc
// Output
// Just a legend
// 
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
ostream& operator<<( ostream& os, const vector<T>& vec )
{
    string sep = "";
    for( const auto& value: vec ){
        os << sep << value;
        sep = " ";
    }
    return os;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
vector<int> zfunction( const string& s )
{
    const int n = s.size();
    
    vector<int> z(n);
    int l = 0;
    int r = 0;
    
    for( int j = 1; j < n; ++j ){
        if( r > j ){
            z[j] = min( r - j, z[j - l]);
        }
        while( j + z[j] < n && s[z[j]] == s[j + z[j]]){
            ++z[j];
        }
        if( j + z[j] > r ){
            l = j;
            r = j + z[j];
        }
    }
    return z;
}
////////////////////////////////////////////////////////////////
//                         1
//     0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
// s = f i x p r e f i x s u f f i x
// z = 0 0 0 0 0 0 3 0 0 0 0 1 3 0 0
////////////////////////////////////////////////////////////////
string Wraith_awaiting_launch_orders( const string& s )
{
    const int n = s.size();
    vector<int> z = zfunction( s );
    int maxz = 0;
    for( int j = 1; j < n; ++j ){
        if( z[j] == n - j ){
            if( maxz >= z[j] ){
                return s.substr( j );
            }
        }
        maxz = max( maxz, z[j] );
    }
    return "Just a legend";
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main()
{
    string s; cin >> s;
    cout << Wraith_awaiting_launch_orders( s ) << endl;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
