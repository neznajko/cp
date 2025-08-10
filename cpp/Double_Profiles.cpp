////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
# include <algorithm>
# include <utility>
# include <unordered_map>
# include <unordered_set>
////////////////////////////////////////////////////////////////
// C. Double Profiles
////////////////////////////////////////////////////////////////
// You have been offered a job in a company developing a large
// social network. Your first task is connected with searching
// profiles that most probably belong to the same user.
// The social network contains n registered profiles, numbered
// from 1 to n. Some pairs there are friends (the "friendship"
// relationship is mutual, that is, if i is friends with j, then
// j is also friends with i). Let's say that profiles i and j
// (i ≠ j) are doubles, if for any profile k (k ≠ i, k ≠ j) one
// of the two statements is true: either k is friends with i and
// j, or k isn't friends with either of them. Also, i and j can
// be friends or not be friends.
// Your task is to count the number of different unordered pairs
// (i, j), such that the profiles i and j are doubles. Note that
// the pairs are unordered, that is, pairs (a, b) and (b, a) are
// considered identical.
// Input
// The first line contains two space-separated integers n and m
// (1 ≤ n ≤ 10^6, 0 ≤ m ≤ 10^6), — the number of profiles and
// the number of pairs of friends, correspondingly.
// Next m lines contains descriptions of pairs of friends in the
// format "v u", where v and u (1 ≤ v, u ≤ n, v ≠ u) are numbers
// of profiles that are friends with each other. It is
// guaranteed that each unordered pair of friends occurs no more
// than once and no profile is friends with itself.
// Output
// Print the single integer — the number of unordered pairs of
// profiles that are doubles.
// Please do not use the %lld specificator to read or write
// 64-bit integers in С++. It is preferred to use the %I64d
// specificator.
// Examples
// Input
// 3 3
// 1 2
// 2 3
// 1 3
// Output
// 3
// Input
// 3 0
// Output
// 3
// Input
// 4 1
// 1 3
// Output
// 2
// Note
// In the first and second sample any two profiles are doubles.
// In the third sample the doubles are pairs of profiles (1, 3)
// and (2, 4).
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
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
typedef unsigned long long u64;
typedef unsigned int u32;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
const u64 P = 1'000'003;
////////////////////////////////////////////////////////////////
vector<u64> p;
vector<u64> q;
////////////////////////////////////////////////////////////////
void initialize( u32 n ){
    p.resize( n + 1 );
    q.resize( n + 1 );
    p[0] = 1;
    for( u32 j = 1; j <= n; ++j ){
        p[j] = p[j - 1] * P;
        q[j] = j * p[j];
    }
}
u64 adjacency_hash( const vector<u32>& adj ){
    u64 h = 0;
    for( u32 v: adj ){
        h += q[v];
    }
    return h;
}
////////////////////////////////////////////////////////////////
// Гората бе обагрена с есенни цветове,
// спрял до потока, еленът се вгледаше в невидимото,
// дърветата мълчаха,
// листата им се носеха тихо от вятъра
////////////////////////////////////////////////////////////////
int main() {
    if( 0 ){
     } else {
        u32 n, m;
        scanf( "%d %d", &n, &m );
        vector<vector<u32>> adj( n + 1 ); // 1-based
        unordered_set<u32> selfish;
        initialize( n );
        for( u32 i = 0; i < m; ++i ){
            u32 u, v;
            scanf( "%d %d", &u, &v );
            adj[u].push_back( v );
            adj[v].push_back( u );
            selfish.insert( u );
            selfish.insert( v );
        }
        ////////////////////////////////////////////////////////
        unordered_map<u64,u64> f;
        vector<u64> hashes( n + 1 );
        for( u32 u = 1; u <= n; ++u ){
            u64 h = adjacency_hash( adj[u] );
            ++f[h];
            hashes[u] = h;
        }
        u64 total = 0;
        for( const auto& pair: f ){
            u64 c = pair.second;
            if( c > 1 ){
                total += c * (c - 1) / 2;
            }
        }
        f.clear();
        for( u32 u: selfish ){
            u64 h = hashes[u] + q[u];
            ++f[h];
        }
        for( const auto& pair: f ){
            u64 c = pair.second;
            if( c > 1 ){
                total += c * (c - 1) / 2;
            }
        }
        printf( "%I64d\n", total );
   }
}
////////////////////////////////////////////////////////////////
// 34. Prove that
//     (a) (a,b)|(a + b, a - b);
//
//     (a,b) is the GCD of a and b, zo it divides both a and b,
//     GCD can be written as linear combo, so we can write:
//     (a + b, a - b) = λ(a + b) + ν(a - b), for some λ,ν ∈ Z,
//     so we have (a + b, a - b) = a(λ + ν) + b(λ - ν), and
//     since (a,b)|a and (a,b)|b, (a,b)|(a + b, a - b)         «
//
//     (b) if a is odd and b is even, then (a,b) = (a + b,a - b)
//
//     Let g = (a + b, a - b), cos of (a) we have to prove only
//     that g|(a,b). g divides a + b and a - b, so we can write
//     a + b = λg, and a - b = ϰg for some λ,ϰ ∈ Z. Now becoz
//     a is odd and b is even, a ± b are odd, that is g is odd,
//     zo adding and substracting the equations:
//     | a + b = λg
//     | a - b = ϰg, will give us:
//     | 2a = (λ + ϰ)g
//     | 2b = (λ - ϰ)g, that means λ ± ϰ are even numbers, zo
//     a = ωg and b = μg, for some ω,μ ∈ Z. Now we can write
//     (a,b) as linear combo (a,b) = αa + βb for some α,β ∈ Z;
//     (a,b) = αa + βb = αωg + βμg = (αω + βμ)g => g|(a,b)     «
//
//     (c) if a and b are odd, then 2(a,b) = (a + b, a - b)
//
//     a ± b are even, (a,b) is odd zo 2(a,b) divides 
//     (a + b, a - b). As in (b), 4 g := (a + b, a - b) we have:
//     | 2a = (λ + ϰ)g
//     | 2b = (λ - ϰ)g, now directly from (a,b) = αa + βb
//     2(a,b) = α2a + β2b = α(λ + ϰ)g + β(λ - ϰ)g =
//            = [α(λ + ϰ) + β(λ - ϰ)]g, that is g|2(a,b)       «
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Time                                                  2483 ms
// Memory                                              111800 KB
