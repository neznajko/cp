// -*- c-file-style: "gnu" -*-
//////////////////////////////////////////////////////
// 12. Let us generalize exercise 11 even further, b y
// assuming that there are m different sizes o f disks
// a n d e x a c t l y n(k) disks of size k. Determine 
// A(n1,...,nm) and B(n1,...,nm) t h e minimum numbers
// of moves that a r e needed to transfer a tower when
// equal-size disks are considered to be (a) identical
// and (b) distinct.
// 
//     ***     (a) This looks like a cake or smth, but
//    _____    we have s = {* - ~ | =}, m = |s| = 5, 
//    _____    with n = (1,3,2,1,2), so we transefer 
//    _____    all {* - ~ |} disck from peg A to B, 
//   ~~~~~~~   then the 2 = disks from A to C, and 
//   ~~~~~~~   finally the *-~| disks from B to C, in
//  |||||||||  the general case this should look smth
// =========== like thus:
// =========== A(n1,...,nm) = A(n1,...,n{m-1}) +
// nm + A(n1,...,n{m-1}) = 2A(n1,...,n{m-1}) + nm = 
// 2( 2A(n1,...,n{m-2}) + n{m-1} ) + nm =
// 4A(n1,...,n{m-2}) + 2n{m-1} + nm =
// = sum{i=1..m}2^{m-i}ni
//
// (b) B(k) := B(n1,...,nk);
//     B(m) = B(m-1) + nm + B(m-1) + nm + B(m-1) =
//          = 3B(m-1) + 2nm = 
//          = 3( 3B(m-2) + 2n{m-1} ) + 2nm =
//          = 3^2B(m-2) + 3^12n{m-1} + 3^02n{m} =
//          = 3^2( 3B(m-3) + 2n{m-2} ) + ... =
//          = 3^3B(m-3) + 3^2n{m-2} + ... =
//          = 2( sum{i=0,m-1} 3^i*n[m-i] ) така че ...
//////////////////////////////////////////////////////
// 23. Let G be the event that a certain individual is
// guilty of a certain robbery. In gathering evidence, it
// is learned that an event E1 occurred, and a little
// later it is also learned that another event E2 also
// occurred. Is it possible that individually, these
// pieces of evidence increase the chance of guilt (so
// P(G|E1) > P(G) and P(G|E2) > P(G)), but together
// they decrease the chance of guilt (so P(G|E1,E2) < P(G))?
//
// I'm not sure bout the algebraic proof but geometricaly
// kinda clear whats going on, let E := E1, F := F2, then
// P(G|EF) can not only be < P(G) but directly zero, cos
// P(EF) might be > 0 but the intersection EF to be
// outside G, then GEF is empty and P(G|EF) = P(GEF)/P(EF)
// is dzero
//////////////////////////////////////////////////////
// 24. Is it possible to have events A₁, A₂, B, C with
// P(A₁|B) > P(A₁|C) and P(A₂|B) > P(A₂|C), yet
// P(A₁∪A₂|B) < P(A₁∪A₂|C)? If so, find an example
// (with a "story" interpreting the events, as well as
// giving specific numbers); otherwise, show that it is
// impossible for this phenomenon to happen
//
// Oh no not a story, blast off I suspect it's possible.
// P(A₁∪A₂|B) = P(A₁|B) + P(A₂|B) - P(A₁A₂|B)
// P(A₁∪A₂|C) = P(A₁|C) + P(A₂|C) - P(A₁A₂|C), zo if
// A₁ and A₂ are intersecting its possible if P(A₁A₂|B)
// is substracting more from P(A₁|B) + P(A₂|B) then
// P(A₁A₂|C) from P(A₁|B) + P(A₂|B), yea I'm not giving a
// story!
//////////////////////////////////////////////////////
# include <bits/stdc++.h>
//////////////////////////////////////////////////////
// 2.2.36. A rocket of mass m hovers above the surface
// of the Earth. How much fuel per unit time must it
// consume to achieve this, if the exhaust gas
// velocity is u? How will the result change if the
// rocket ascends with an acceleration a?
//
// Yea so the force by the fuel is Δp/Δt = Δmu/Δt so
// to equalize the gravity it must equal mg, zo
// Δm/Δt = mg/u, in case of acceleration, we can
// substitute g with g + a, Δm/Δt = m(a + g)/u
//////////////////////////////////////////////////////
# undef DeBug
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
using namespace std;
//////////////////////////////////////////////////////
using i32 =  int32_t;
using u32 = uint32_t;
using i64 =  int64_t;
using u64 = uint64_t;
//////////////////////////////////////////////////////
constexpr char  nl = '\n';
constexpr char  sp =  ' ';
constexpr char tab = '\t';
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
template <typename T>
inline T loads() {
    T y; cin >> y;
    return y;
}
//////////////////////////////////////////////////////
template <typename T>
istream& operator>>( istream& s, vector<T>& v ){
    for( auto& y: v ){ s >> y; }
    return s;
}
//////////////////////////////////////////////////////
template <typename T>
inline vector<T> loadv( u32 n ){
    vector<T> y( n ); cin >> y;
    return y;
}
//////////////////////////////////////////////////////
template <typename T>
inline vector<vector<T>> loadt( u32 n, u32 m ){
    vector<vector<T>> y( n, vector<T>( m )); cin >> y;
    return y;
}
//////////////////////////////////////////////////////
template <typename T>
inline pair<T,T> loadp() {
    pair<T,T> y;
    cin >> get<0>( y ) >> get<1>( y );
    return y;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
inline void vrooom() {
  cin.tie( nullptr )->sync_with_stdio( false );
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
# define OVERLOAD_OSTREAM_OPERATOR( Container )                \
template <typename... T>                                       \
ostream& operator<<( ostream& os, const Container<T...>& con ){\
    os << "[";                                                 \
    string sep = "";                                           \
    for( const auto& y: con ){                                 \
        os << sep << y;                                        \
        sep = " ";                                             \
    }                                                          \
    return os << "]";                                          \
}
////////////////////////////////////////////////////////////////
OVERLOAD_OSTREAM_OPERATOR( vector );
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////
# ifdef DeBug
  template<typename T>
  inline void debug( string name, T x, string sep="\n" ){
    cerr << name << "=" << x << sep;
  }
# define dbg( x, ... ) debug( #x, x, ##__VA_ARGS__ )
# else
# define dbg( x, ... )
# endif
//####################################################
//////////////////////////////////////////////////////
# define dbg2(a,b) dbg(a,","); dbg(b)
# define on( x ) ( x ).begin(),( x ).end()
# define siz( a ) (i32) (a).size()
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
enum { BLACK, WHITE, GRAY, RED, 
       BLUE, ORANGE, MAGENTA, BROWN };
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////................
//////////////////////////////////////................
//////////////////////////////////////................
//////////////////////////////////////................
//####################################################
///////////////////////////////////////// /  /////////
//////////////////////////////////////// /  //////////
/////////////////////////////////////// /  ///////////
////////////////////////////////////// /  ////////////
template <typename T>
vector<T> vec( T* p, i32 n ){
  return vector<T>( p, p + n );
}
# ifdef DeBug
# define dmp( p, n ) cerr << #p << "=" << vec( p, n ) << nl;
# else
# define dmp( p, n )
# endif
///////////////////////////////////// /  /////////////
//////////////////////////////////// /  //////////////
/////////////////////////////////// /  ///////////////
////////////////////////////////// /  ////////////////
constexpr i32 M = 2e5;
i32 state_cntr = 0;
struct State {
  i32 len = 0;
  i32 link = 0;
  array<i32,26> t;  
} st[ M ];
i32 new_state(){
  return ++state_cntr;
}
ostream& operator<<( ostream& s, const State& p ){
  s << p.len << sp << p.link << "{";
  for( i32 i = 0; i < 26; ++i ){
    if( p.t[i] ){
      s << 'a' + i << sp;       
    }
  }
  return s << "}";
}
// cp-algorithms.com:

// Let last be the state corresponding to the entire
// string before adding the character c. (Initially we
// set last = 0, and we will change last in the last
// step of the algorithm accordingly.)

// Create a new state cur, and assign it with len(cur)
// = len(last) + 1. The value link(cur) is not known
// at the time.

// Now we do the following procedure: We start at the
// state last. While there isn't a transition through
// the letter c, we will add a transition to the state
// cur, and follow the suffix link. If at some point
// there already exists a transition through the
// letter c, then we will stop and denote this state
// with p.

// If we haven't found such a state p, then we
// reached the fictitious state −1, then we can just
// assign link(cur) = 0 and leave.

// Suppose now that we have found a state p, from
// which there exists a transition through the letter
// c. We will denote the state, to which the
// transition leads, with q.

// Now we have two cases. Either len(p) + 1 = len(q),
// or not.

// If len(p) + 1 = len(q), then we can simply assign
// link(cur) = q and leave.

// Otherwise it is a bit more complicated. It is
// necessary to clone the state q: we create a new
// state clone, copy all the data from q (suffix link
// and transition) except the value len. We will
// assign len(clone) = len(p) + 1 .
//
// After cloning we direct the suffix link from cur to
// clone, and also from q to clone.
//
// Finally we need to walk from the state p back using
// suffix links as long as there is a transition
// through c to the state q, and redirect all those to
// the state clone .

// In any of the three cases, after completing the
// procedure, we update the value last with the state
// cur.
void bld( const string& s ){
  st[0].link = -1;
  i32 last = 0;
  for( auto c: s ){
    i32 curr = new_state();
    st[ curr ].len = st[ last ].len + 1;
    i32 p = last;
    while( true ){
      st[ p ].t[c - 'a'] = curr;
      p = st[p].link;
      if( p == -1 or 
          st[ p ].t[c - 'a'] ) break;
    }
    if( p != -1 ){
      i32 q = st[ p ].t[c - 'a'];
      if( st[ p ].len == st[ q ].len - 1 ){
        st[ curr ].link = q;
      } else {
        i32 clone = new_state();
        st[ clone ] = st[ q ];
        st[ clone ].len = st[ p ].len + 1;
        st[ q ].link = st[ curr ].link = clone;
        while( p != -1 and st[ p ].t[ c - 'a'] == q ){
          st[ p ].t[ c - 'a'] = clone;
          p = st[ p ].link;
        }
      }
    }
    last = curr;
  }
}
bool checkpat( const string& pat ){
  i32 j = 0;
  for( auto c: pat ){
    j = st[ j ].t[ c - 'a'];
    if( !j ) return false;
  }
  return true;
}
void pusk() {
  auto s = loads<string>(); dbg( s );
  bld( s );
  auto k = loads<i32>();
  while( k-- ){
    auto pat = loads<string>(); dbg( pat );
    if( checkpat( pat )){
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
int main() {
  vrooom();
  if( 0 ){
  } else {
    pusk();
  }}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////                                          //////  
////// Finding Patterns                         //////
//////                                          //////
////// Given a string and patterns, check for   //////
////// each pattern if it appears in the        //////
////// string.                                  //////
//////                                          //////
////// [ Input ]                                //////
////// The first input line has a string of     //////
////// length n. The next input line has an     //////
////// integer k: the number of patterns.       //////
////// Finally, there are k lines that describe //////
////// the patterns. The string and the         //////
////// patterns consist of characters a–z.      //////
//////                                          //////
////// [ Output ]                               //////
////// For each pattern, print "YES" if it      //////
////// appears in the string and "NO"           //////
////// otherwise.                               //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 ≤ n ≤ 1e5                              //////
////// 1 ≤ k ≤ 5e5                              //////
////// the total length of the patterns is at   //////
////// most 5e5                                 //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// aybabtu                                  //////
////// 3                                        //////
////// bab                                      //////
////// abc                                      //////
////// ayba                                     //////
//////                                          //////
////// Output:                                  //////
////// YES                                      //////
////// NO                                       //////
////// YES                                      //////
//////                                          //////
//////////////////////////////////////////////////////
///////////////////////////////////////////########///
///////////////////////////////////////////########///
///////////////////////////////////////////########///
// log: Всички сега пък покрай годишнини   ########
// от Шипки от възтания почнаха да говорят ### ####
// за саможертва искам да попитам мислите ###  ### 
// ли че някой гнусен евродепутат ще си  ##   ##   
// жертва тлъстата заплата и желанието   #     #
// сичко да му е наред за някви идеали? Не разбира се
// така че преди да проповядвате за саможертва трябва
// да учите хората да не бъдат самовлюбени задници
