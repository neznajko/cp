////////////////////////////////////////////////////////////////
// ADV04F1 - Four Chips (Hard)
////////////////////////////////////////////////////////////////
// There is a n × 1 board. Its cells are numbered with integers
// from 1 to n. First four cells have indistinguishable chips in
// them. In one turn you can move one chip to the neighbouring
// cell or move it symmetrically relatively any other chip
// (i.e. if you move a chip in cell 10 symmetrically relative to
// the chip in cell 13 it will end up in cell 16), given that
// the chip won't leave the board and each cell will have no
// more than one chip. You need to determine the minimum number
// of turns needed to reach a certain configuration of chips.
////////////////////////////////////////////////////////////////
// Input
// The first line of input contains number T - the amount of
// test cases. Next T lines consist of four integers a1, a2, a3
// and a4 — the numbers of cells where the chips should be in
// the final configuration.
////////////////////////////////////////////////////////////////
// Constraints
// 1 ≤ T ≤ 10000
// 1 ≤ a1 < a2 < a3 < a4 ≤ n
// n = 70
////////////////////////////////////////////////////////////////
// Output
// For each test case print single integer - the answer to the
// problem in the statement.
////////////////////////////////////////////////////////////////
// Example
// Input:
// 2
// 1 2 3 4
// 1 3 4 6
// 
// Output:
// 0
// 1
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
# include <iostream>
# include <array>
# include <bitset>
# include <algorithm>
# include <vector>
# include <string.h>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
# define BOARDSIZ 70
# define NOFCHIPS 4
////////////////////////////////////////////////////////////////
typedef array <int,NOFCHIPS> chip_t;
typedef bitset <BOARDSIZ+1> brd_t;
typedef char i8;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
ostream &operator<<( ostream&_,const chip_t&chip ){_<<"[";string 
sep="";for(const auto&value:chip){_<<sep<<value;sep=", ";}return 
_<<"]";}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// +--------+--------+--------+--------+
// |        |   24   |  16    |   8    |
// +--------+--------+--------+--------+
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
struct Node {
    int dist = 0;
    chip_t chip;
    brd_t brd;
    Node( const chip_t& chip ):
        chip( chip ),
        brd( SetACourse( chip )){
    }
    brd_t SetACourse( const chip_t& chip ){
        brd_t brd;
        for( const auto& ofst: chip ){
            brd.set( ofst );
        }
        return brd;
    }
    Node MakeItHappen( int from, int to ) const {
        Node node = *this;
        ++node.dist;
        node.chip[ from ] = to;
        sort( node.chip.begin(), node.chip.end() );
        node.brd.set( chip[ from ], 0 );
        node.brd.set( to );
        return node;
    }
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
ostream&operator<<( ostream&_, const Node&node ){ return _<<node.
dist<<" "<<node.chip<<" "<<node.brd<<endl;}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
struct Deque {
    int dp = 0;
    vector <Node> deq;
    void push( const Node& node ){
        deq.push_back( node );
    }
    Node pop() {
        return deq[ dp++ ];
    }
    bool empty() const {
        return dp == deq.size();
    }
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
namespace glob {
    Deque deq;
    i8 cache
    [ BOARDSIZ + 1 ]
    [ BOARDSIZ + 1 ]
    [ BOARDSIZ + 1 ]
    [ BOARDSIZ + 1 ];
}
////////////////////////////////////////////////////////////////
void SoundsFun( int from, int to, const Node& node ){
    if( to <= 0 ||
        to > BOARDSIZ ||
        node.brd.test( to )) return;
    Node next = node.MakeItHappen( from, to );
    i8 &cached = glob::cache
        [ next.chip[ 0 ]]
        [ next.chip[ 1 ]]
        [ next.chip[ 2 ]]
        [ next.chip[ 3 ]];
    if( cached != -1 ) return;
    cached = next.dist;
    glob::deq.push( next );
}
////////////////////////////////////////////////////////////////
void AaanyTimeYou_reReady( const Node& node ){
    for( int i = 0; i < NOFCHIPS; ++i ){
        for( int d: { -1, 1 }){
            int to = node.chip[i] + d;
            SoundsFun( i, to, node );
        }
        for( int j = 0; j < NOFCHIPS; ++j ){
            if( i == j ) continue;
            int to = 2 * node.chip[j] - node.chip[i];
            SoundsFun( i, to, node );
        }
    }
}
////////////////////////////////////////////////////////////////
void OhYeeaaahh___() {
    Node start({ 1, 2, 3, 4 });
    glob::cache[ 1 ][ 2 ][ 3 ][ 4 ] = start.dist;
    glob::deq.push( start );
    while( !glob::deq.empty() ){
        AaanyTimeYou_reReady( glob::deq.pop() );
    }
}
////////////////////////////////////////////////////////////////
int main() {
    if( 0 ){
    } else {
        glob::deq.deq.reserve( 1'000'000 );
        memset( glob::cache, -1, sizeof( glob::cache ));
        OhYeeaaahh___();
        int T; cin >> T;
        while( T-- ){
            chip_t goal;
            for( int j = 0; j < NOFCHIPS; ++j ){
                int ofst; cin >> ofst;
                goal[j] = ofst;
            }
            sort( goal.begin(), goal.end() );
            cout << ( int ) glob::cache
                [ goal[ 0 ]]
                [ goal[ 1 ]]
                [ goal[ 2 ]]
                [ goal[ 3 ]] << endl;
        }
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// TIME                                                     0.53
// MEM                                                       64M
