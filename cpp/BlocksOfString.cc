////////////////////////////////////////////////////////////////
// https://basecamp.eolymp.com/en/problems/1309 
////////////////////////////////////////////////////////////////
// Blocks of string
////////////////////////////////////////////////////////////////
// The Block of the string S at position i is the largest 
// substring S that starts at position i and matches a prefix of 
// S. The length of the block at position 0 is considered to be 
// zero.
// 
// Find the lengths of the blocks of string S for all positions.
// 
// Input
// One string S (∣S∣≤10^6).
// 
// Output
// Print a single line containing the lengths of the blocks of 
// string S for all positions.
// 
// Examples
// Input #1
// abaabaab
// Answer #1
// 0 0 1 5 0 1 2 0
////////////////////////////////////////////////////////////////
# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec){
    string sep = "";
    for(const auto& value: vec){
        os << sep << value;
        sep = " ";
    }
    return os;
}
////////////////////////////////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //
    string s;
    getline(cin,s);
    int n = s.size();
    vector<int> z(n);
    int l = 0;
    int r = 0; // [l,r)
    for(int j = 1; j < n; ++j){
        if(j < r){
            z[j] = min(z[j - l], r - j);
        }
        while(j + z[j] < n && s[z[j]] == s[j + z[j]]){
            ++z[j];
        }
        if( j + z[j] > r){
            l = j, r = j + z[j];
        }
    }
    cout << z << endl;
}
//////////////////////////////////// ///////////////////////////
//////////////////////////////////// ///////////////////////////
/////// /// /// /// //  /// /// ///  ///////////////////////////
////// / / / / / / / / / /   / / / / ///////////////////////////
///////  / /// ///   / / // //   / / ///////////////////////////
////// / / / / / / /// / // // /// / ///////////////////////////
/////// / / /// /// //  //// // ///  ///////////////////////////
////////////////////// /////////////////////////////////////////
////////////////////// /////////////////////////////////////////
