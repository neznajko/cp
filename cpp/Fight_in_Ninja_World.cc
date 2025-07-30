////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Fight in Ninja World                     www.hackerearth.com/
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
# include <unordered_set>
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
// 1 <= T <= 20
// 1 <= N <= 10^5
// 1 <= A, B <= 2*10^4
////////////////////////////////////////////////////////////////
//         0 1 2 3 4 5 | a =  , b =     | a =      | a = 
//   prev: 0 3 2 3 2 3 |                | b =      | b =
//   size: 1 1 1 1 1 1 | opp_a =        |          |
//    opp: 0 0 0 0 0 0 | opp_b =        |          |
// groups: {}          |                |          |
//                     | register_fight | find_set | union_sets 
// 1 2
// 2 3
// 2 4
// 2 5
class Disjoint_Set_Union
{
public:
    static const int CAP = 20001;
    vector <int> prev;
    vector <int> size;
    vector <int> opp;
    unordered_set <int> groups;
    //
    Disjoint_Set_Union()
        : prev( vector <int> ( CAP )),
          size( vector <int> ( CAP, 1 )),
          opp( vector <int> ( CAP ))
    {
        for( int j = 1; j < CAP; ++j ){
            prev[j] = j;
        }
    }
    int find_set( int v ){
        if( v == prev[v] ){ return v; }
        return prev[v] = find_set( prev[v]);
    }
    int union_sets( int a, int b ){
        a = find_set(a);
        b = find_set(b);
        if( a != b ){
            if( size[a] < size[b]){ swap( a, b ); }
            prev[b] = a;
            size[a] += size[b];
        }
        return a;
    }
    void register_fight( int a, int b ){
        a = find_set( a );
        b = find_set( b );
        if( opp[a] == opp[b] ){ // both nil
            opp[a] = b;
            opp[b] = a;
            groups.insert( a );
        } else {
            if( opp[a] == 0 ){
                // put a as second parameter cos of this:
                // if( size[a] < size[b]){ swap( a, b ); }
                a = union_sets( opp[b], a );
            } else if( opp[b] == 0 ){
                b = union_sets( opp[a], b );
            } else { // cross
                if( opp[a] == b ) return; // repetition
                // merge
                // a with opp[b] and b with opp[a]
                // |a|...|opp[a].....[opp[b]|... |b|
                // reset
                int opp_a = opp[a];
                int opp_b = opp[b];
                opp[a] = opp[opp_a] = opp[b] = opp[opp_b] = 0;
                groups.erase( a );
                groups.erase( opp_a );
                groups.erase( b );
                groups.erase( opp_b );
                a = union_sets( a, opp_b );
                b = union_sets( b, opp_a );
                opp[a] = b;
                opp[b] = a;
                groups.insert( a );
            }
        }
    }
    int Raikage_army_max_size() {
        int max_size = 0;
        for( int v: groups ){
            max_size += max( size[v], size[opp[v]]);
        }
        return max_size;
    }
};
////////////////////////////////////////////////////////////////
int main()
{
    int t; cin >> t;
    for( int i = 1; i <= t; ++i ){
        int n; cin >> n;
        auto dsu = Disjoint_Set_Union();
        for( int j = 0; j < n; ++j ){
            int a; cin >> a;
            int b; cin >> b;
            dsu.register_fight( a, b );
        }
        printf( "Case %d: %d\n", i, dsu.Raikage_army_max_size());        
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// 52. A certain class has 20 students, and meets on Mondays and
// Wednesdays in a classroom with exactly 20 seats. In a certain
// week, everyone in the class attends both days. On both days,
// the students choose their seats completely randomly (with one
// student per seat). Find the probability that no one sits in
// the same seat on both days of that week.
////////////////////////////////////////////////////////////////
// Let's call the students A B C D .. and number the chairs from
// 1 to 20. The thing here is that the arrangement of the
// students in the first day is irrelevant becoz we want to
// compare their arrangements on the second day relative to
// that, so we can assume students on the first day are sorted:
// A B C D .. T. Then we have to look at all permutations on the
// second day. So the sample space is n! where n = 20.
////////////////////////////////////////////////////////////////
// If Pj is the probability that jth student is on the same
// chair we have Pj = (n-1)!/n! = 1/n. To find the probablity
// that at least one student is on the same chair we have to use
// the inclusion exclusion stuff, so what is Pi ∩ Pj that is we
// have ith and jth students on same chairs; this is (n-2)!/n!,
// there are C(n,2) such i and j, so when we sum we'll get:
// C(n,2)(n-2)!/n! = ... = 1/2!; similar for k students, zo the
// probability that at least one student is on the same chair is
// P = 1 - 1/2! + 1/3! - 1/4! + ... - 1/20!, let expand e^x, we
// have e^x = 1 + x + x^2/2! + ..., zo:
// e^-1 = 1 - 1 + 1/2! - 1/3! + ... = 1 - ( 1 - 1/2! + ... ), zo
// P is nearly 1 - e^-1. That is the probability that everyone
// is on a different chair is 1/e                              «
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// RESULT:                                              Accepted
// Score:                                                    100
// Time (sec):                                             0.651
// Memory (KiB):                                             664        
