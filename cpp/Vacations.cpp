////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// codeforces.com/problemset/problem/699/C
////////////////////////////////////////////////////////////////
//C.VacationsVasyahasndaysofvacations!SohedecidedtoimprovehisITs
//killsanddosport.Vasyaknowsthefollowinginformationabouteachofth
//isndays:whetherthatgymopenedandwhetheracontestwascarriedoutint
//heInternetonthatday.Forthei-thdaytherearefouroptions:thegymisc
//losedandthecontestisnotcarriedout;thegymisclosedandthecontesti
//scarriedout;thegymisopenandthecontestisnotcarriedout;thegymiso
//penandthecontestiscarriedout.OneachofdaysVasyacaneitherhaveare
//storwritethecontest(ifitiscarriedoutonthisday),ordosport(ifthe
//gymisopenonthisday).FindtheminimumnumberofdaysonwhichVasyawill
//havearest(itmeans,hewillnotdosportandwritethecontestatthesamet
//ime).TheonlylimitationthatVasyahas—hedoesnotwanttodothesameact
//ivityontwoconsecutivedays:itmeans,hewillnotdosportontwoconsecu
//tivedays,andwritethecontestontwoconsecutivedays.InputThefirstl
//inecontainsapositiveintegern(1≤n≤100)—thenumberofdaysofVasya's
//vacations.Thesecondlinecontainsthesequenceofintegersa1,a2,...,
//an(0≤ai≤3)separatedbyspace,where:aiequals0,ifonthei-thdayofvac
//ationsthegymisclosedandthecontestisnotcarriedout;aiequals1,ifo
//nthei-thdayofvacationsthegymisclosed,butthecontestiscarriedout
//;aiequals2,ifonthei-thdayofvacationsthegymisopenandthecontesti
//snotcarriedout;aiequals3,ifonthei-thdayofvacationsthegymisopen
//andthecontestiscarriedout.OutputPrinttheminimumpossiblenumbero
//fdaysonwhichVasyawillhavearest.RememberthatVasyarefuses:todosp
//ortonanytwoconsecutivedays,towritethecontestonanytwoconsecutiv
//edays.ExamplesInput41320Output2Input71332123Output0Input222Out
//put1NoteInthefirsttestVasyacanwritethecontestonthedaynumber1an
//ddosportonthedaynumber3.Thus,hewillhavearestforonly2days.Inthe
//secondtestVasyashouldwritecontestsondaysnumber1,3,5and7,inothe
//rdaysdosport.Thus,hewillnothavearestforasingleday.Inthethirdte
//stVasyacandosporteitheronadaynumber1ornumber2.Hecannotdosporti
//ntwodays,becauseitwillbecontrarytothehislimitation.Thus,hewill
//havearestforonlyoneday.
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
# include <algorithm>
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
////////////////////////////////////////////////////////////////
OVERLOAD_OSTREAM_OPERATOR( vector );
////////////////////////////////////////////////////////////////ˣʸ
////////////////////////////////////////////////////////////////α
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// <> 2.1.49*: A load is suspended from the free end of a thread
// attached to the wall and thrown over a roller. The roller is
// fixed to a block of mass m0, which can slide along a
// horizontal plane without friction. At the initial moment, the
// thread with the load is deflected from the vertical by an
// angle α and then released. Determine the acceleration of the
// block if the angle formed by the thread with the vertical
// does not change during the motion of the system. What is the
// mass of the load?
// |____________            O________P      OP = AC = AB = X
// |           o\ `          \       \      OA = PC
// |          /  \`           \       \     ∠(ABQ) = α
// |     +---+    \            \    Q  \  
// |     | M |    `\            \.......\ C  T \ | Tˣ = T sin α
// +-----+---+-+  ` \          A \  .   `       \| Tʸ = T cos α
// |           |  `α \   QC = x   \ .  `         +
// |           |  `   m  QB = y    \. `          |
//                `                 \`           | mg
//                                  B
// T - Tsinα = Mw, w - acceleration of M( дубъл ве )
// Tˣ = Tsinα = maˣ
// mg - Tʸ = mg - Tcosα = maʸ, a - acceleration of m
// from AQB sinα = AQ/AB = (X - x)/X, zo x = X(1 - sinα) that is
// aˣ = w(1 - sinα)
// cosα = QB/AB = y/X, y = Xcosα, aʸ = wcosα
//
// T(1 - sinα) = Mw
// Tsinα = maˣ = mw(1 - sinα), zo
// (1 - sinα)/sinα = M/m(1 - sinα), m = Msinα/(1 - sinα)²      «
//
// aʸ = wcosα
// mg - Tcosα = maʸ
// Tsinα = mw(1 - sinα), zo
// mg - cosαmw(1 - sinα)/sinα = mwcosα, zo
// g = wcosα((1 - sinα)/sinα + 1) = wcosα(1 - sinα + sinα)/sinα
//   = w cosα/sinα, w = gtgα                                   «
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
typedef enum { REST, GYM, CON } activity_t;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Vacations {
public:
    Vacations( const vector<int>& a ):
        n( a.size()),
        a( a ),
        c( vector<vector<int>>( n, vector<int>( CON + 1, -1 )))
    {}
    int min_Rest_Days() {
        return dp( 0, REST );
    }
private:
    const int n;
    const vector<int>& a;
    vector<vector<int>> c;
    int dp( int j, activity_t y ){
        if( j >= n ){ return 0; }
        if( c[j][y] != -1 ){ return c[j][y]; }
        int result;
        switch( a[j] ){
        case 0:
            result = 1 + dp( j + 1, REST );
            break;
        case 1:
            if( y != CON ){
                result = dp( j + 1, CON );
            } else {
                result = 1 + dp( j + 1, REST );
            }
            break;
        case 2:
            if( y != GYM ){
                result = dp( j + 1, GYM ); 
            } else {
                result = 1 + dp( j + 1, REST );
            }
            break;
        case 3:
            if( y == GYM ){
                result = dp( j + 1, CON );
            } else if( y == CON ){
                result = dp( j + 1, GYM );
            } else {
                result = min( dp( j + 1, GYM ),
                              dp( j + 1, CON ));
            }
            break;
        default: break;
        }
        return c[j][y] = result;
    }
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main() {
    ios::sync_with_stdio( false );
    cin.tie( nullptr );
    if( 0 ){
    } else {
        int n; cin >> n;
        vector<int> a( n );
        for( auto& y: a ){ cin >> y; }
        cout << Vacations( a ).min_Rest_Days() << endl;
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Exercise 1.4.3. Prove that ∩{(0, 1/n): 1 ≤ n < ∞ } = ø
// Notice that this demonstrates that the intervals in the
// Nested Interval Property must be closed for the conclusion of
// the theorem to hold
//
// From the Archimedean Property it follows that for each real
// number y > 0 there exist n ∈ N satisfying 1/n < y, zo we
// can't have a real number y > 0 that is an element of all
// intervals (0, 1/n), the only candidate dzero would be a
// common element if we had [0, 1/n) intervals                 «
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// It was an evening in the city. I was in my office, standing
// by the window and staring at the lights of the flying
// vehicles, lingering, trying to grasp every bit from the end
// of the working day, just chilling, smoking cigarettes, and
// listening to the radio. They were playing really good stuff
// there, classical music, you know. It was some foreign station;
// I had no idea what they were talking about, but the only
// radio worth listening to is the one you don’t understand
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Time                                                    77 ms
// Memory                                                 100 KB
