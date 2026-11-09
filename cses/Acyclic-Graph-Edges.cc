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
typedef enum { BLACK, WHITE, GRAY, RED, 
               BLUE, ORANGE, MAGENTA, BROWN } colour_t;
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
i32 n, m;
vector<vector<i32>> adj;
vector<colour_t> dirty;
void explore( i32 u ){
  dirty[ u ] = GRAY;
  for( auto v: adj[ u ]){
    switch( dirty[ v ]){
    case  GRAY: cout << v << sp << u << nl;
    case BLACK: continue;
    case WHITE: explore( v );
    }}
  dirty[ u ] = BLACK;
}
void dfs() {
  dirty.resize( n + 1, WHITE );
  for( i32 u = 1; u <= n; ++u ){
    if( dirty[ u ] == WHITE ){
      explore( u );
    }}}
void pusk() {
  cin >> n >> m; dbg2( n, m );
  adj.resize( n + 1 );
  while( m-- ){
    i32 a, b;
    cin >> a >> b; dbg2( a, b );
    adj[a].push_back( b );
    adj[b].push_back( a );
  }
  dbg( adj );
  dfs();
}
/*////////////////////////////////////////////////////
// 27. Suppose that there are     5 blood types in the
// population,       named type 1 through type 5, with
// probabilities p1,p2,...,p5.   A crime was committed
// by two individuals. A suspect, who has blood type 1,
// has prior probability p of being     guilty. At the
// crime scene,     blood evidence is collected, which
// shows that one of the criminals has  type 1 and the
// other has type 2. Find the    posterior probability
// that the suspect is guilty,      given the evidence.
// Does the evidence make it       more likely or less
// likely that the suspect is guilty,     or does this
// depend on the values of the parameters  p,p1,...,p5?
// If it depends on these values,        give a simple
// criterion for when the       evidence makes it more
// likely that the suspect is guilty. 高い「たかい」
######################################################
######################################################
######################################################
######################################################
######################################################
######################################################
######################################################
######################################################
######################################################
######################################################
//////////////////////////////////////////////////////
// 2.2.38. A water jet boat moves in still water.
// The resistance force of the water opposing the
// boat's motion is F = kv². The velocity of the water
// being ejected relative to the boat is u. Determine
// the boat's steady-state velocity, given that the
// cross-sectional area of the water stream drawn in
// by the engine is S and the density of water is ρ.
// 菓「カ」
######################################################
######################################################
######################################################
######################################################
######################################################
######################################################
######################################################
######################################################
######################################################
######################################################
######################################################
////////////////////////////////////////////////////*/
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
////// Acyclic Graph Edges                      //////
//////                                          //////
////// Given an undirected graph, your task is  //////
////// to choose a direction for each edge so   //////
////// that the resulting directed graph is     //////
////// acyclic.                                 //////
//////                                          //////
////// [ Input ]                                //////
////// The first input line has two integers n  //////
////// and m: the number of nodes and edges.    //////
////// The nodes are numbered 1,2,...,n.  After //////
////// this, there are m lines describing the   //////
////// edges. Each line has two distinct        //////
////// integers a and b: there is an edge       //////
////// between nodes a and b.                   //////
//////                                          //////
////// [ Output ]                               //////
////// Print m lines describing the directions  //////
////// of the edges. Each line has two integers //////
////// a and b: there is an edge from node a to //////
////// node b. You can print any valid          //////
////// solution.                                //////
//////                                          //////
////// [ Constraints ]                          //////
////// 1 ≤ n ≤ 1e5                              //////
////// 1 ≤ m ≤ 2e5                              //////
////// 1 ≤ a,b ≤ n                              //////
//////                                          //////
////// [ Example ]                              //////
////// Input:                                   //////
////// 3 3                                      //////
////// 1 2                                      //////
////// 2 3                                      //////
////// 3 1                                      //////
//////                                          //////
////// Output:                                  //////
////// 1 2                                      //////
////// 3 2                                      //////
////// 3 1                                      //////
//////                                          //////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
///////////////////////////////////////////########///
///////////////////////////////////////////########///
// log: They have asked one random hip hop ########
// artist:) what is the     namba one most ### ####
// important fyorst priority thing in the ###  ### 
// World and he has answered: MYSELF! So ##   ##   
// that's normal in English I and 1 looks #     #
// same in Bulgarian for example       A is the fyorst
// letter and I is Аз,      so when you say that being
// fyorst is good and  second is bad or being a winner
// is good and looser is bad thats the same  as saying
// that I = good or that there is no objective good in
// this World, unfortunately this   egoism is true not
// only for random rappers   but for countries as well
