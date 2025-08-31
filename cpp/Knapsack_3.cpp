////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// dmoj.ca/problem/knapsack
////////////////////////////////////////////////////////////////
// Knapsack 3
////////////////////////////////////////////////////////////////
// RogerandGeorgerunatransportcompany.OnedaytheirbossVictortells
// themtotransportsomesubsetoftheNgoodstoanotherwarehouse.Rogero
// bservesthattherearen[i]ofthei-thitem,eachtakingupv[i]volumein
// theirtruck,andwillgivethemaprofitofp[i]each.Georgeislookingat
// thetrucks,andobservesthatthereareMofthesetrucks.Thei-thtruckh
// asacapacityofc[i],butwillcostf[i]dollarsforrefueling.Theymust
// driveexactlyonetruck.Canyouhelpthemmaximizetheirprofit?Constr
// aintsForallsubtasks:1<=N,M,c[i]<=50001<=n[i],v[i],p[i],f[i]<=
// 10**9InputSpecificationThefirstlinecontainstwointegers,N,M.Th
// enextNlinescontainthreeintegers,n[i],v[i],p[i].ThenextMlinesc
// ontaintwointegers,c[i],f[i].OutputSpecificationOutputoneinteg
// er,themaximumprofittheycanhave.SampleInput1321232343451052010
// SampleOutput116ExplanationforSampleOutput1RogerandGeorgecange
// taprofitof26fromtransportingtheitems,butmustpay10fortheirtruc
// k.SampleInput241110101910281010210110SampleOutput2-10Explanat
// ionforSampleOutput2Thereisonlyonetypeoftruckavailableinthisca
// se,andunfortunatelynoneoftheitemscanfitinthistruck.BecauseRog
// erandGeorgearen'tverysmart,theymustdriveatruckeveniftheywould
// makemoreprofitnotdrivingatruck.
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
//////////////////////////////////////////////////////////////// や
//////////////////////////////////////////////////////////////// す
typedef long long i64;
typedef unsigned long long u64;
//////////////////////////////////////////////////////////////// い
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Knapsack {//                       ###################### i
public://                                ##########    ######## n
    Knapsack( const vector<int>& n,//    ##                    
              const vector<int>& v,//    ##    ############    
              const vector<int>& p,//    ######    ############ e
              const vector<int>& c,//                       ### x
              const vector<int>& f )://  ####    ##    ######## p
        n( n ),//                        ###    ##    ######### e
        v( v ),//                        ######      ########## n
        p( p ),//                        ######       ######### s
        c( c ),//                        ####    ####    ###### i
        f( f )//                         ##    #########    ### v
    {}//                                 ###################### e
    void maxprofit() {
        int M = c.size();
        int maxcap = *max_element( c.begin(), c.end());
        precompute( maxcap );
        i64 neg = numeric_limits<i64>::min();
        u64 pos = 0;
        bool haspos = false;
        for( int j = 0; j < M; ++j ){
            if( f[j] > dp[c[j]] ){
                neg = max( neg, (i64)dp[c[j]] - f[j] );
            } else {
                pos = max( pos, dp[c[j]] - f[j] );
                haspos = true;
            }
        }
        if( haspos ){
            cout << pos << endl;
        } else {
            cout << neg << endl;
        }
    }
private:
    const vector<int>& n;
    const vector<int>& v;
    const vector<int>& p;
    const vector<int>& c;
    const vector<int>& f;
    vector<u64> dp;
    void precompute( int cap ){
        dp.resize( cap + 1 );
        int N = n.size();
        for( int i = 0; i < N; ++i ){
            for( int j = cap; j >= v[i]; --j ){
                int maxk = min( n[i], j/ v[i] );
                for( int k = 0; k <= maxk; ++k ){
                    dp[j] = max( dp[j], dp[j - k*v[i]] + k*p[i] );
                }
            }
        }
    }
};
////////////////////////////////////////////////////////////////₁₂²
//////////////////////////////////////////////////////////////// 
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// 2.1.52: The accelerations of stars that are part of a binary
// star are a₁ and a₂. What is the mass of the second star if
// the mass of the first is m₁?
//
// Zo ok if we take the center of mass to be positioned at dzero
// we'll have 0 = (r₁m₁ + r₂m₂)/(m₁ + m₂), as vectors, zo
// r₁m₁ = r₂m₂, as absolute values, on the other hand we have
// ω² = a₁/r₁ = a₂/r₂, zo a₁/a₂ = r₁/r₂ = m₂/m₁, that is
// m₂ = m₁a₁/a₂                                                «
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main() {
    ios::sync_with_stdio( false );
    cin.tie( nullptr );
    if( 0 ){
    } else {
        int N,
            M; cin >> N >> M;
        vector<int> n( N ),
                    v( N ),
                    p( N );
        for( int j = 0; j < N; ++j ){
            cin >> n[j] >> v[j] >> p[j];
        }
        vector<int> c( M ),
                    f( M );
        for( int j = 0; j < M; ++j ){
            cin >> c[j] >> f[j];
        }
        Knapsack(n, v, p, c, f).maxprofit();
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Петела кукуригаше на стоборо
// Между плевелите бодро звучеше мотика
// В ръцета на майстора чукът ехтеше високо
// Дърветата пазеха тайната скрита
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
