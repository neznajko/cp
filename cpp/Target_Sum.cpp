////////////////////////////////////////////////////////////////
// leetcode.com/problems/target-sum/description/
////////////////////////////////////////////////////////////////
// 494.TargetSumYouaregivenanintegerarraynumsandanintegertarget.
// Youwanttobuildanexpressionoutofnumsbyaddingoneofthesymbols'+'
// and'-'beforeeachintegerinnumsandthenconcatenatealltheintegers
// .Forexample,ifnums=[2,1],youcanadda'+'before2anda'-'before1an
// dconcatenatethemtobuildtheexpression"+2-1".Returnthenumberofd
// ifferentexpressionsthatyoucanbuild,whichevaluatestotarget.Exa
// mple1:Input:nums=[1,1,1,1,1],target=3Output:5Explanation:Ther
// eare5waystoassignsymbolstomakethesumofnumsbetarget3.-1+1+1+1+
// 1=3+1-1+1+1+1=3+1+1-1+1+1=3+1+1+1-1+1=3+1+1+1+1-1=3Example2:I
// nput:nums=[1],target=1Output:1Constraints:1<=nums.length<=200
// <=nums[i]<=10000<=sum(nums[i])<=1000-1000<=target<=1000
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
# include <algorithm>
# include <unordered_map>
# include <utility>
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
////////////////////////////////////////////////////////////////
template <typename A, typename B>
ostream& operator<<( ostream& os, const pair<A, B>& p ){
    return os << "(" << p.first << ", " << p.second << ")";
}
////////////////////////////////////////////////////////////////
OVERLOAD_OSTREAM_OPERATOR( vector );
OVERLOAD_OSTREAM_OPERATOR( unordered_map );
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// <> 2.1.51*: A heavy plate is placed on two rollers of
// different radii. It forms an angle α with the horizon. Find
// the acceleration of this plate. There is no slippage.
// Neglect the mass of the rollers.
// #############################################################
// ########################################### This is kind of  # 
// ######       ############################## a weird problem  # 
// #####               ####################### cos basically    ### 
// ####                       ################  nothing is given #
// ###########                       ######### And actually it  # 
// ########    ######                       ## doesn't matter   ###
// ######        ###########               ### if we have 2 or  #
// ####            ########    ####       #### more rollers, so #
// ####            ######        ############# we look at just  ##
// ######        ########        ############# one. There is no #
// ########    ############    #################################
// ##########################################  A   #############
// ## slippage betveen the surface and ###   ###### B ##########
// ## the roller, but there is between #  ############  ########
// ## it and the plate, cos of the ###  ################  ######
// ## reaction force they should go ##  ######  O ######  ######
// ## in different directions. Let ###  ################  ######
// ## the center of the roller O has ###  ############  ########
// ## speed v, if we look at a system ####   ######   ##########
// ## moving alongside O the roller will ####  C   #############
// rotate with angular speed v/r, where r is its radius and the
// plate will slide perpendicular to OB, that is at angle α,
// their directions will be opposite but aligned at the same
// angle, now if we move back to lab system the velocity of
// point B where they intersect is perpendicular to CB, so the
// plate will move in a direction perpendicular to CB, and
// basically this is it, the angle AOB is equal to α, the angle
// ACB is α/2, so the projection of mg over that line is:
// mgsin(α/2), hence the acceleration is gsin(α/2)             «
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class SwitcherMap {
public:
    SwitcherMap():
        bufr( vector<unordered_map<int,int>>( 2 ))
    {
        bufr[0][0] = 1;
    }
    void make_switch() {
        I = 1 - I;
    }
    unordered_map<int,int>& curr() {
        return bufr[1 - I];
    }
    unordered_map<int,int>& prev() {
        return bufr[I];
    }
private:
    int I = 0;
    vector<unordered_map<int,int>> bufr;
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// 1. やすいです 2. あついです 3. さむいです 4. おもしろいです
// 5. つまらないです 6. いそがしいです 7. ふるいです 8. いいです
// 9. しずかなです 10. にぎやかなです 11. きれいなです 12. ひまなです
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class TargetSum {
public:
    TargetSum( const vector<int>& a, int target ):
        n( a.size()),
        a( a ),
        target( target )
    {}
    int findWays() {
        for( int j = n - 1; j >= 0; --j ){
            switcher.curr().clear();
            for( auto& it: switcher.prev() ){
                switcher.curr()[ it.first + a[j] ] += it.second;
                switcher.curr()[ it.first - a[j] ] += it.second;
            }
            switcher.make_switch();
        }
        return switcher.prev()[ target ];
    }
private:
    const int n;
    const vector<int>& a;
    int target;
    SwitcherMap switcher;
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Solution {
public:
    int findTargetSumWays( vector<int>& nums, int target ){
        return TargetSum( nums, target ).findWays();
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
        vector<int> nums{ 1 };
        int target = 1;
        cout << Solution().findTargetSumWays( nums, target )
             << endl;
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Дебеланкото профуча покрай стъписаното момче със шеметна
// скорост. Гласът на продавачката все още преследваше мислите
// му: „Поничките свършиха“. Оставаха не повече от няколко
// минути до затварянето на сладкарница „Победа“, и въпреки че
// шансовете бяха малки, той заложи на „Всичко или Нищо“ в опита
// си да надбяга края на работното и време
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Runtime:                               114 ms | Beats 40.01 %
// Memory:                              37.06 MB | Beats 20.33 %
