////////////////////////////////////////////////////////////////
// codeforces.com/problemset/problem/706/C
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// C. Hard problem
////////////////////////////////////////////////////////////////
// Vasiliyisfondofsolvingdifferenttasks.Todayhefoundonehewasn'ta
// bletosolvehimself,soheasksyoutohelp.Vasiliyisgivennstringscon
// sistingoflowercaseEnglishletters.Hewantsthemtobesortedinlexic
// ographicalorder(asinthedictionary),butheisnotallowedtoswapany
// ofthem.Theonlyoperationheisallowedtodoistoreverseanyofthem(fi
// rstcharacterbecomeslast,secondbecomesonebeforelastandsoon).To
// reversethei-thstringVasiliyhastospentciunitsofenergy.Heisinte
// restedintheminimumamountofenergyhehastospentinordertohavestri
// ngssortedinlexicographicalorder.StringAislexicographicallysma
// llerthanstringBifitisshorterthanB(|A|<|B|)andisitsprefix,orif
// noneofthemisaprefixoftheotherandatthefirstpositionwheretheydi
// ffercharacterinAissmallerthanthecharacterinB.Forthepurposeoft
// hisproblem,twoequalstringsnearbydonotbreaktheconditionofseque
// ncebeingsortedlexicographically.InputThefirstlineoftheinputco
// ntainsasingleintegern(2≤n≤100000)—thenumberofstrings.Thesecon
// dlinecontainsnintegersci(0≤ci≤10^9),thei-thofthemisequaltothe
// amountofenergyVasiliyhastospentinordertoreversethei-thstring.
// Thenfollownlines,eachcontainingastringconsistingoflowercaseEn
// glishletters.Thetotallengthofthesestringsdoesn'texceed100000.
// OutputIfitisimpossibletoreversesomeofthestringssuchthattheywi
// llbelocatedinlexicographicalorder,print-1.Otherwise,printthem
// inimumtotalamountofenergyVasiliyhastospent.ExamplesInput212ba
// acOutput1Input3131aabaacOutput1Input255bbbaaaOutput-1Input233
// aaaaaOutput-1NoteInthesecondsampleonehastoreversestring2orstr
// ing3.Toamountofenergyrequiredtoreversethestring3issmaller.Int
// hethirdsample,bothstringsdonotchangeafterreverseandtheygointh
// ewrongorder,sotheansweris-1.Inthefourthsample,bothstringscons
// istsofcharacters'a'only,butinthesortedorderstring"aa"shouldgo
// beforestring"aaa",thustheansweris-1.
//
# include <iostream>
# include <vector>
# include <algorithm>
# include <utility>
# include <string>
# include <limits>
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
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
typedef long long i64;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
typedef enum { LT, EQ, GT } cmp_t;
cmp_t ff( const string& s, const string& t ){
    int n = min( s.size(), t.size());
    int i = 0;
    for(; i < n and (s[i] == t[i]); ++i )
        ;
    if( i < n ){
        return (s[i] < t[i]) ? LT : GT;
    }
    if( s.size() == t.size() ){ return EQ; }
    return (s.size() < t.size()) ? LT : GT;
}
cmp_t fr( const string& s, const string& t ){
    int n = min( s.size(), t.size());
    int i = 0;
    int j = t.size() - 1;
    for(; i < n and (s[i] == t[j]); ++i, --j )
        ;
    if( i < n ){
        return (s[i] < t[j]) ? LT : GT;
    }
    if( s.size() == t.size() ){ return EQ; }
    return (s.size() < t.size()) ? LT : GT;
}
cmp_t rf( const string& s, const string& t ){
    auto cmp = fr( t, s );
    if( cmp == LT ){ return GT; }
    if( cmp == GT ){ return LT; }
    return EQ;
}
cmp_t rr( const string& s, const string& t ){
    int i = s.size() - 1;
    int j = t.size() - 1;
    for(; i >= 0 and j >= 0 and (s[i] == t[j]); --i, --j )
        ;
    if( i < 0 ){
        return (s.size() == t.size()) ? EQ : LT;
    }
    if( j < 0 ){ return GT; }
    return (s[i] < t[j]) ? LT : GT;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
i64 dp( int n, const vector<int>& c, const vector<string>& a ){

    const i64 mx = numeric_limits<i64>::max();

    vector<i64> f( n, mx );
    vector<i64> g( n, mx );
    
    int j = n - 1;

    f[j] = 0;
    g[j] = c[j];

    for( --j; j >= 0; --j ){
        if( f[j + 1] < mx ){
            auto cmp = ff( a[j], a[j + 1] );
            if( cmp != GT ){
                f[j] = f[j + 1];
            }
            cmp = rf( a[j], a[j + 1] );
            if( cmp != GT ){
                g[j] = c[j] + f[j + 1];
            }
        }
        if( g[j + 1] < mx ){
            auto cmp = fr( a[j], a[j + 1] );
            if( cmp != GT ){
                f[j] = min( f[j], g[j + 1] );
            }
            cmp = rr( a[j], a[j + 1] );
            if( cmp != GT ){
                g[j] = min( g[j], c[j] + g[j + 1]);
            }
        }
        if( f[j] == mx and g[j] == mx ){ return -1; }
    }
    return min( f.front(), g.front());
}
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
        vector<int> c( n );
        for( auto& y: c ){ cin >> y; }
        vector<string> a( n );
        for( auto& y: a ){ cin >> y; }
        cout << dp( n, c, a ) << '\n';
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// - Stop! Where you goin'?
// - To Nowhere
// - This direction
// - thnx:)
// - Just to remind you the caretaker hates knocking on the door
//   after 8 o'clock PM
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Time                                                    93 ms
// Memory                                                 600 KB
