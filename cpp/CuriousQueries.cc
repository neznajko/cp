////////////////////////////////////////////////////////////////
// hackerearth.com/                              Curious Queries
////////////////////////////////////////////////////////////////
// You are given an array A of length N. You are asked Q queries
// Each query is of the form L, R and the answer is the sum of 
// A[i] for all i such that 0 <= i <= L and A[i] > A[R]
//
// Print an array B of length Q such that B[i] is the answer to
// the ith query.
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
# include <iostream>
# include <cstdint>
# include <vector>
# include <tuple>
# include <utility>
# include <algorithm>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
using u32 = uint32_t;
////////////////////////////////////////////////////////////////
constexpr char nl = '\n';
constexpr char sp = ' ';
////////////////////////////////////////////////////////////////
void inc( vector<u32>& bit, u32 k, u32 y ){
    while( k < bit.size()){
        bit[k] += y;
        k += k & -k;
    }
}
////////////////////////////////////////////////////////////////
u32 sum( const vector<u32>& bit, u32 k ){
    u32 _sum = 0;
    while( k > 0 ){
        _sum += bit[k];
        k -= k & -k;
    }
    return _sum;
}
////////////////////////////////////////////////////////////////
int main() {
    ios_base::sync_with_stdio( false );
    cin.tie( NULL );
    
    u32 t; cin >> t;
    while( t-- ){
        u32 n, q; cin >> n >> q;
        vector<pair<u32,u32>> a( n ); // i, y
        for( u32 j = 0; j < n; ++j ){
            u32 y; cin >> y;
            a[j] = make_pair( j + 1, y ); // BITは１から始まるです
        }
        vector<tuple<u32,u32,u32>> queries( q ); // j, l, w
        for( u32 j = 0; j < q; ++j ){
            u32 l, r; cin >> l >> r;
            // A[i] > A[r] <=> A[i] >= A[r] + 1
            queries[j] = make_tuple( j, l + 1, a[r].second + 1 );
        }
        sort( a.begin(), a.end(), []( const auto& x, const auto& y ){
            return y.second < x.second;
        });
        sort( queries.begin(), queries.end(), []( const auto&x, const auto& y ){
            return get<2>( y ) < get<2>( x );
        });
        vector<u32> b( q );
        vector<u32> bit( n + 1 );
        u32 h = 0;
        u32 k = 0;
        while( k < q ){
            const auto [j,l,u] = queries[k];
            if( h < n and a[h].second >= u ){
                inc( bit, a[h].first, a[h].second );
                ++h;
            } else {
                b[j] = sum( bit, l );
                ++k;
            }
        }                       
        for( auto y: b ){
            cout << y << sp;
        }
        cout << nl;
    }
}
////////////////////////////////////////////////////////////////
// Time (sec)                                       Memory (KiB)
// 0.79063                                          1612
