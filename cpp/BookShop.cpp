////////////////////////////////////////////////////////////////
// https://cses.fi/problemset/task/1159/
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
# include <utility>
# include <algorithm>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
// 3 10
// 2 6 3
// 8 5 4
// 3 5 2
////////////////////////////////////////////////////////////////
ostream& operator<<( ostream& os, const pair<int,int>& p ){
    return os << "(" << p.first << "," << p.second << ")";
}
////////////////////////////////////////////////////////////////
template <typename T>
ostream& operator<<( ostream& os, const vector<T>& vec ){
    os << "[";
    string sep = "";
    for( const auto& y: vec ){
        os << sep << y;
        sep = " ";
    }
    return os << "]";
}
////////////////////////////////////////////////////////////////
int Make_up_your_mind( int W, const vector<pair<int,int>>& wv ){
    int n = wv.size();
    vector<int> f(W + 1);
    for( int i = 0; i < n; ++i ){
        int w = wv[i].first;
        int v = wv[i].second;
        for( int j = W; j >= w; --j ){
            f[j] = max( f[j], f[j - w] + v );
        }
    }
    return f[W];
}
////////////////////////////////////////////////////////////////
int main() {
    int n; cin >> n;
    int W; cin >> W;
    vector<int> wvec( n ); for( auto& y: wvec ) cin >> y;
    vector<int> vvec( n ); for( auto& y: vvec ) cin >> y;
    vector<int> kvec( n ); for( auto& y: kvec ) cin >> y;
    vector<pair<int,int>> wv; wv.reserve( 100'000 );
    for( int j = 0; j < n; ++j ){
        int w = wvec[j];
        int v = vvec[j];
        int k = kvec[j];
        int c = 1;
        while( k > c ){
            wv.emplace_back( c * w, c * v );
            k -= c;
            c *= 2;
        }
        wv.emplace_back( k * w, k * v );
    }
    cout << Make_up_your_mind( W, wv ) << endl;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Result:                                              ACCEPTED
