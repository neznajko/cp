////////////////////////////////////////////////////////////////
// leetcode.com/problems/minimum-score-triangulation-of-polygon/
////////////////////////////////////////////////////////////////
// 1039.MinimumScoreTriangulationofPolygonYouhaveaconvexn-sidedp
// olygonwhereeachvertexhasanintegervalue.Youaregivenanintegerar
// rayvalueswherevalues[i]isthevalueoftheithvertexinclockwiseord
// er.Polygontriangulationisaprocesswhereyoudivideapolygonintoas
// etoftrianglesandtheverticesofeachtrianglemustalsobeverticesof
// theoriginalpolygon.Notethatnoothershapesotherthantrianglesare
// allowedinthedivision.Thisprocesswillresultinn-2triangles.Youw
// illtriangulatethepolygon.Foreachtriangle,theweightofthattrian
// gleistheproductofthevaluesatitsvertices.Thetotalscoreofthetri
// angulationisthesumoftheseweightsoveralln-2triangles.Returnthe
// minimumpossiblescorethatyoucanachievewithsometriangulationoft
// hepolygon.Example1:Input:values=[1,2,3]Output:6Explanation:Th
// epolygonisalreadytriangulated,andthescoreoftheonlytriangleis6
// .Example2:Input:values=[3,7,4,5]Output:144Explanation:Therear
// etwotriangulations,withpossiblescores:3*7*5+4*5*7=245,or3*4*5
// +3*4*7=144.Theminimumscoreis144.Example3:Input:values=[1,3,1,
// 4,1,5]Output:13Explanation:Theminimumscoretriangulationis1*1*
// 3+1*1*4+1*1*5+1*1*1=13.Constraints:n==values.length3<=n<=501<
// =values[i]<=100
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
# include <algorithm>
# include <limits>
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Triangulation {
public:
    Triangulation( const vector<int>& a )
        : n( a.size()),
          a( a ),
          c( vector<vector<int>>( n, vector<int>( n )))
    {}
    int score() {
        return dp( 0, n - 1 );
    }
private:
    const int n;
    const vector<int>& a;
    vector<vector<int>> c;
    int dp( int i, int j ){
        if( i + 1 == j ){ return 0; }
        if( c[i][j] ){ return c[i][j]; }
        int res = numeric_limits<int>::max();
        int p = a[i] * a[j];
        for( int k = i + 1; k < j; ++k ){
            res = min( res, p * a[k] + dp( i, k ) + dp( k, j ));
        }
        return c[i][j] = res;
    }
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Solution {
public:
    int minScoreTriangulation( vector<int>& a ){
        return Triangulation( a ).score();
    }
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main() {
    if( 0 ){
    } else {
        vector<int> a{ 1, 2, 3 };
        cout << Solution().minScoreTriangulation( a ) << endl;
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// All w  e know the phrase "Great art is horseshit, buy tacos".
// Even some philosophers seem quite obsessed with searching for
// paradox i n everything. And if y o u search carefully you can
// probably find paradox in every b o o k, film, story, poem, or
// even a sentence, but do you know why? ............ Няма време
// Only because a story n e e d s a conflict; yeah, did you know
// this:) i f not don't worry, you are not the only one, paradox
// or absurd( sounds like псувня in Bulgarian ) equals conflict.
// Here is one rule in w r i t i n g or storytelling: you need a
// conflict that has to be resolved. This is a c t i n g like an
// engine for the ongoing motion. But extrapolating that rule as
// a general principle, guiding life and a l l is just bullshit,
// n o t horseshit! This i  s exactly what I'm repeating without
// success for so long. It i s the old traditional understanding
// o    f Zarathustra, Heraclitus, Hegel, Marx, You Name It; and
// even in t h e Eastern philosophies they talk about In and Yan
// as opposite forces, like opposite armies o r something. It is
// the understanding that conflict i  s a fundamental t h i n g,
// necessary for the existence not only o f a story, film, book,
// etc. but for the existence of life and everything. T h i s is
// j u s t wrong. The harmony, not the conflict between opposite
// things, is necessary and fundamental. It feels stupid to have
// to repeat this, but here I a m, saying it again. White is not
// g o o d and Black is not bad; t h e harmony between White and
// Black is good, and everything else is bad. We can pretty much
// live i n a w o r l d without conflicts, because conflicts are
// result of the will to f r e e d o m. But freedom i s also not
// fundamental, because w e only choose what is best; it depends
// on our understanding of good
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Runtime:                                   3ms | Beats 58.79%
// Memory:                                11.26MB | Beats 41.47%
