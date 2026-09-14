// -*- c-file-style: "gnu" -*-
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
# include <bits/stdc++.h>
//////////////////////////////////////////////////////
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
template <typename K, typename V>
ostream& operator<<( ostream& os, const pair<K,V>& p );
////////////////////////////////////////////////////////////////
OVERLOAD_OSTREAM_OPERATOR( vector );
////////////////////////////////////////////////////////////////
template <typename K, typename V>
ostream& operator<<( ostream& os, const pair<K,V>& p ){
    return os << "{"
              << p.first
              << ","
              << p.second
              << "}";
}
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
# define siz( a ) ((i32) a.size())
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
constexpr i32 N = 1e7;
constexpr i32 Q = sqrt( N );
vector<i32> L(Q+1);
vector<i32> T1(N+1,-1);
vector<pair<i32,i32>> T2(N+1,{-1,-1});

void initialize() {
  for( i32 i = 0; i <= Q; ++i ){
    L[i] = i*i;
    T1[i*i] = i;
  }
  for( i32 i = 0; i <= Q; ++i ){
    for( i32 j = i; j <= Q and L[i] + L[j] <= N; ++j ){
      T2[L[i] + L[j]] = { T1[L[i]], T1[L[j]] };
    }
  }
}
//////////////////////////////////////////////////////
// Legendre's three-square theorem states that a
// natural number n can be expressed as the sum of
// three squares of integers if and only if it is not
// of the form n = 4^a(8b + 7), where a and b are
// non-negative integers.                    -- Gemini
//////////////////////////////////////////////////////
bool ck( i32 n ){ // return true if n != 4^a(8b + 7)
  if( n < 7 ) return true; // n = 7 for a = b = 0
  while( n % 4 == 0 ) n /= 4; // strip 4^a
  return n % 8 != 7;
}
tuple<i32,i32,i32> solve3( i32 n ){
  for( auto a2: L ){
    if( T2[n - a2].first != -1 ){
      return { T1[a2],T2[n - a2].first,T2[n - a2].second };
    }
  }
  return {};
}
tuple<i32,i32,i32,i32> solve4( i32 n ){
  // n = a²
  if( T1[n] != -1 ){
    return {T1[n],0,0,0};
  }
  // n = a² + b²
  if( T2[n].first != -1 ){
    return {T2[n].first,T2[n].second,0,0};
  }
  // n = a² + b² + c²
  if( ck( n )){
    auto [a,b,c] = solve3( n );
    return {a,b,c,0};
  }
  // n = a² + b² + c² + d²
  for( auto a2: L ){
    if( ck( n - a2 )){
      auto [b,c,d] = solve3( n - a2 );
      return {T1[a2],b,c,d};
    }
  }
  return {};
}
void pusk() {
  initialize();
  auto t = loads<i32>();
  while( t-- ){
    auto n = loads<i32>();
    auto [a,b,c,d] = solve4( n );
    printf( "%i %i %i %i\n", a, b, c, d );
  }
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//（〜を）おねがいします
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
////// Sum of Four Squares                      //////
//////                                          //////
////// A well known result in number theory is  //////
////// that every non negative integer can be   //////
////// represented as the sum of four squares   //////
////// of non negative integers. You are given  //////
////// a non-negative integer n. Your task is   //////
////// to find four non negative integers a, b, //////
////// c and d such that n = a² + b² + c² + d². //////
//////                                          //////
////// [Input]                                  //////
////// The first line has an integer t: the     //////
////// number of test cases. Each of the next t //////
////// lines has an integer n.                  //////
//////                                          //////
////// [Output]                                 //////
////// For each test case, print four non       //////
////// negative integers a, b, c and d that     //////
////// satisfy n = a² + b² + c² + d².           //////
//////                                          //////
////// [Constraints]                            //////
////// 1 ≤ t ≤ 1000                             //////
////// 0 ≤ n ≤ 1e7                              //////
////// the sum of all n is at most 1e7          //////
//////                                          //////
////// [Example]                                //////
////// Input:                                   //////
////// 3                                        //////
////// 5                                        //////
////// 30                                       //////
////// 322266                                   //////
//////                                          //////
////// Output:                                  //////
////// 2 1 0 0                                  //////
////// 1 2 3 4                                  //////
////// 314 159 265 358                          //////
//////                                          //////
//////////////////////////////////////////////////////
///////////////////////////////////////////########///
///////////////////////////////////////////########///
///////////////////////////////////////////########///
// log:                                    ########
//                                         ### ####
//                                        ###  ### 
//                                       ##   ##   
//                                       #     #
//
// 21. If c² = ab and (a,b) = 1, prove that a and b
// are perfect squares.
//
// In the factorization of c² all primes are in the
// form p^(2k), so if (a,b) = 1, that means a and b
// have no common primes in their factorization, so
// if a or b are not perfect squares then in the ryte
// side there will be some prime of the form p^n where
// n is odd and this can't match the c² factorization
//
// 11. An exit poll in an election is a survey taken
// of voters just after they have voted. One major use
// of exit polls has been so that news organizations
// can try to figure out as soon as possible who won
// the election, before the votes are officially
// counted. This has been notoriously inaccurate in
// various elections, sometimes because of selection
// bias: the sample of people who are invited to and
// agree to participate in the survey may not be
// similar enough to the overall population of voters.
// Consider an election with two candidates, Candidate
// A and Candidate B. Every voter is invited to
// participate in an exit poll, where they are asked
// whom they voted for; some accept and some refuse.
// For a randomly selected voter, let A be the event
// that they voted for A, and W be the event that they
// are willing to participate in the exit poll.
// Suppose that P(W|A) = 0.7 but P(W|Ac) = 0.3. In
// the exit poll, 60% of the respondents say they
// voted for A (assume that they are all honest),
// suggesting a comfortable victory for A. Find P(A),
// the true proportion of people who voted for A.
//
// P(W|A)P(A) = P(A|W)P(W)
// P(W|B)P(B) = P(B|W)P(W)
//
// P(W|A)P(A)   P(A|W)
// ---------- = ------, B := Ac, P(B) = 1 - P(A)
// P(W|B)P(B)   P(B|W)
//
// P(W|A) = .7, P(A|W) = .6
// P(W|B) = .3  P(B|W) = .4, x := P(A)
//
// .7x          .6
// --------- =  ---, .28x = .18(1 - x) = .18 - .18x
// .3(1 - x)    .4
//
// .46x = .18, x = P(A) = .18/.46 = 9/23 = 39%
//
// <> 2.2.32*. In a cylinder under a piston of mass M,
// N balls of mass m each are bouncing, elastically
// striking the piston and the bottom of the
// cylinder. The force of gravity acting on the piston
// is balanced by the impacts of the balls. The
// distance between the bottom of the cylinder and the
// piston is h. The total energy of each ball is the
// same. To what height will the balls bounce if the
// piston is quickly removed? N ≫ 1.
//
// Let's consider one ball, and let υ is its speed at
// the bottom of the cylinder and u vhen it hits the
// piston, zo we have:
// h = υt - ½gt²
// u = υ - gt, vhere t is the time of flight betveen
// bot and top, for time duration vhen the ball is
// acting on the piston Δt we have F = Δp/Δt = 2mu/Δt
// zo the average force is <f> = (FΔt + 0*2t)/(Δt + 2t)
// ≈ 2mu/2t = mu/t, for N balls N<f> = Mg ve get the
// third equation: Nmu = Mgt, zo we have thus:
// h = υt - ½gt²
// u = υ - gt
// Nmu = Mgt, for the unknown t, u, and υ after that
// the desired height is H = υ²/2g
//
// Nmu = Nm(υ - gt) = Mgt,
// Nmυ = Nmgt + Mgt = gt(Nm + M)
//
// υ = h/t + ½gt,
// υ - ½gt = υ - Nmυ/2(Nm + M) = h/t = hg(Nm+M)/Nmυ
// υ(2(Nm+M) - Nm)/2(Nm+M) = hg(Nm+M)/Nmυ,
// υ(Nm+2M)/2(Nm+M) = hg(Nm+M)/Nmυ,
// υ² = 2gh(Nm+M)²/Nm(Nm+2M),
// H = υ²/2g = h(Nm+M)²/Nm(Nm+2M)
//
// 10. Let Q[n] be the minimum number of moves needed
// to transfer a tower of n disks from A to B if all
// moves must be clockwise — that is, from A to B, or
// from B to the other peg, or from the other peg to
// A. Also let R[n] be the minimum number of moves
// needed to go from B back to A under this
// restriction. Prove that
//
// Q[0] = 0, Q[n] = 2R[n-1] + 1
// R[0] = 0, R[n] = Q[n] + Q[n-1] + 1
//
//  A   B, zo Q[n] is moving n discs clockwise one
//    C    step R[n] is ccw, to accomplish Q[n] we
//         move n-1 discs ccw from A to C then base
// disk from A to B and then n-1 disks ccw from C to B
// zo Q[n] = R[n-1] + 1 + R[n-1] = 2R[n-1] + 1, for
// R[n] clearly we can mov cw two times but there is a
// shortcut so to speak we move ccw from B to A then
// cw base disc from B to C then cw from A to B, cw
// from C to A the base this and ccw from B to A:
// R[n] = R[n-1] + 1 + Q[n-1] + 1 + R[n-1] =
//      = 2R[n-1] + 1 + Q[n-1] + 1 = Q[n] + Q[n-1] + 1
//////////////////////////////////////////////////////
