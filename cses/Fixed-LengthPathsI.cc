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
//                                    [ False Season ]
//
//                            All leaves fall the same
//                     Not by wind, the branch is sick
//                                     Autumn is a lie
//
//                                            DeepSeek
//
// Example 2.4.5 (Unanimous agreement). The article
// "Why too much evidence can be a bad thing" by Lisa 
// Zyga [30] says:
//
// Under ancient Jewish law, if a suspect on trial was
// unanimously found guilty by all judges, then the
// suspect was acquitted. This reasoning sounds
// counterintuitive, but the legislators of the time
// had noticed that unanimous agreement often
// indicates the presence of systemic error in the
// judicial process.
//
// There are n judges deciding a case. The suspect has
// prior probability p of being guilty. Each judge
// votes whether to convict or acquit the suspect.
// With probability s, a systemic error occurs (e.g.,
// the defense is incompetent). If a systemic error
// occurs, then the judges unanimously vote to convict
// (i.e., all n judges vote to convict)
//
// Whether a systemic error occurs is independent of
// whether the suspect is guilty. Given that a
// systemic error doesn’t occur and that the suspect
// is guilty, each judge has probability c of voting
// to convict, independently. Given that a systemic
// error doesn’t occur and that the suspect is not
// guilty, each judge has probability w of voting to
// convict, independently. Suppose that
//
// 0 < p < 1, 0 < s < 1, and 0 < w < 1/2 < c < 1.
//
// (a) For this part only, suppose that exactly k out
// of n judges vote to convict, where k < n. Given
// this information, find the probability that the
// suspect is guilty.
//
// G - suspect is guilty
// C - judge vote to convict
// K - k out of n judges vote to convict
//
// P(G) = p - prior prob of guilty
// P(C|¬S,G) = c
// P(C|¬S,¬G) = w
//
// P(G|K) = ?, here we assume ¬S, zo P(C|G) = c, and
// P(C|¬G) = w
// P(G|K) = P(K|G)P(G)/P(K)
//
// P(K|G) = C(n,k)c^k(1 - c)^(n-k)
// P(G) = p
// P(K) = P(K|G)P(G) + P(K|¬G)P(¬G);
// P(K|¬G) = C(n,k)w^k(1 - w)^(n-k)
// P(¬G) = 1 - p, and the ugly looking formula:
// 
// P(G|K) = pc^k(1 - c)^(n-k)/ 
//          pc^k(1 - c)^(n-k) + (1-p)w^k(1 - w)^(n-k)
//
// (b) Now suppose that all n judges vote to convict.
// Given this information, find the probability that
// the suspect is guilty.
//
// S - syserr
// N - n out of n judges vote to convict
//
// P(S) = s
//
// P(G|N) = ?
// If k judges vote to convict we are sure there is
// no syserr but here we can have unanimous agreement
// without systematic error, zo we condition on S
//
// P(G|N) = P(N|G)P(G)/P(N)
//
// P(N|G) = P(N|G,S)P(S) + P(N|G,¬S)P(¬S)
// P(N|G,S) = 1
// P(N|G,¬S) = c^n, zo
// P(N|G) = s + c^n(1-s)
//
// P(N|¬G) = P(N|¬G,S)P(S) + P(N|¬G,¬S)P(¬S) =
//         = s + w^n( 1 - s)
//
// P(G|N) = p( s + c^n(1-s))/
//          p( s + c^n(1-s)) + (1-p)(s + w^n(1-s))
//
// (c) Is the answer to (b), viewed as a function of
// n, an increasing function? Give a short, intuitive
// explanation in words.
//
// Yeeeeeaaaah!!!
//
//////////////////////////////////////////////////////
constexpr i32 N = 2e5; // max nodes
//////////////////////////////////////////////////////
i32 n, k; // number of vertices, path len
vector<i32> adj[N + 1]; // adjacency list
//////////////////////////////////////////////////////
void load() {
  tie( n, k ) = loadp<i32>(); dbg2( n, k );
  for( i32 j = n - 1; j > 0; --j ){
    auto [a,b] = loadp<i32>();
    adj[a].push_back( b );
    adj[b].push_back( a );
  }
  dmp( adj, n + 1 );  
}
//////////////////////////////////////////////////////
i32 subs[N + 1]; // sub tree size
bool removed[N + 1]; // centroid decomposition
//////////////////////////////////////////////////////
void dfs_subsize( i32 u, i32 t ){
  subs[u] = 1;
  for( auto v: adj[u] ){
    if( removed[v] or v == t ){ continue; }
    dfs_subsize( v, u );
    subs[u] += subs[v];
  }
}
//////////////////////////////////////////////////////
i32 centroid;
i32 treesize;
i32 halflife;
//////////////////////////////////////////////////////
bool iscentroid( i32 u, i32 t ){
  if( treesize - subs[u] > halflife ){ return false; }
  for( auto v: adj[u]){
    if( removed[v] or v == t ){ continue; }
    if( subs[v] > halflife ){ return false; }
  }
  return true;
}
//////////////////////////////////////////////////////
void dfs_centroid( i32 u, i32 t ){
  if( iscentroid( u, t )){
    centroid = u;
  } else {
    for( auto v: adj[u]){
      if( removed[v] or v == t ){ continue; }
      dfs_centroid( v, u );
    }
  }
}
//////////////////////////////////////////////////////
i32 find_centroid( i32 u ){
  centroid = 0; // reset( for debugging )
  dfs_subsize( u, 0 );
  treesize = subs[u];
  halflife = treesize / 2;
  dfs_centroid( u, 0 );
  return centroid;
}
//////////////////////////////////////////////////////
vector<i32> cntr; // path counters per path len
i32 pathlen = -1; // current path len
i64 total = 0; // total paths of len k
//////////////////////////////////////////////////////
void fill_cntrs( i32 u, i32 t ){
  ++pathlen;
  if( pathlen < cntr.size( )){
    ++cntr[pathlen];
  } else {
    cntr.push_back( 1 );
  }
  for( auto v: adj[u]){
    if( removed[v] or v == t ){ continue; }
     fill_cntrs( v, u );
  }  
  --pathlen;
}
//////////////////////////////////////////////////////
i64 count_paths( i32 u, i32 t ){
  i64 paths = 0;
  ++pathlen;
  if( pathlen <= k ){
    if( k - pathlen < cntr.size( )){
      paths += cntr[k - pathlen];
    }
    for( auto v: adj[u]){
      if( removed[v] or v == t ){ continue; }
      paths += count_paths( v, u );
    }
  }
  if( --pathlen == 0 ){
    fill_cntrs( u, t );
  }
  return paths;
}
//////////////////////////////////////////////////////
void decompose( i32 u ){
  auto c = find_centroid( u );
  dbg2( u, c );
  cntr = {1}; // reset counters
  total += count_paths( c, 0 );
  dbg( total );
  removed[c] = true;
  for( auto v: adj[c] ){
    if( removed[v] ){ continue; }
    decompose( v );
  }
}
//////////////////////////////////////////////////////
void pusk() {
  load();
  decompose( 1 );
  cout << total << nl;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//                      [ The Blackmailer’s Sequence ]
//  
//                             Watson counts the steps
//                     Shifting through the London fog
//                            French spy fades in mist
//  
//                                              Gemini
//
// 4. Are there any starting and ending configurations
// of n disks on three pegs that are more than 2^n — 1
// moves apart, under Lucas's original rules?
//
// Lets name the pegs A B C, and the disks 1,2,...n,
// with nth disk having the largest size, say
// initially all disks are on A under Lucas's original
// rules:), by the way in Sherlock Holmes there is one
// character Eduardo Lucas a french blackmailer in the
// "Adventures of the Second Stain", and I'm pretty
// sure he borrowed the name from the French
// mathematician Edouard Lucas who has invented this
// puzzle, anyway so we can move the nth disc anywhere
// by moving the [1:n-1] disks somewhere for 2^(n-1)-1
// moves plus moving the nth disk for total 2^(n-1)
// moves, zo we can achieve any position from the
// initial for maximum: 2^(n-1) + 2^(n-2) + ... + 1
// = 2^n - 1 moves. The process seems reversible so
// similarly we can achieve the initial position from
// any arrangement for maximum 2^n - 1 moves. Now lets
// we have arbitrary initial arrangement so we can
// free the nth disk for 2^(n-1) - 1 moves putting
// disks [1:n-1] in initial state somewhere, then
// moving the nth disk for 2^(n-1) moves, next we can
// distribute the [1:n-1] disks in any arrangement for
// 2^(n-1) - 1 moves totally 2^n - 1 moves so this
// seems like the largest distance possible
//
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
////// Fixed-Length Paths I                     //////
//////                                          //////
////// Given a tree of n nodes, your task is to //////
////// count the number of distinct paths that  //////
////// consist of exactly k edges.              //////
//////                                          //////
////// [Input]                                  //////
////// The first input line contains two        //////
////// integers n and k: the number of nodes    //////
////// and the path length. The nodes are       //////
////// numbered 1,2,...,n. Then there are n-1   //////
////// lines describing the edges. Each line    //////
////// contains two integers a and b: there is  //////
////// an edge between nodes a and b.           //////
//////                                          //////
////// [Output]                                 //////
////// Print one integer: the number of paths.  //////
//////                                          //////
////// [Constraints]                            //////
////// 1 <= k <= n <= 2e5                       //////
////// 1 <= a,b <= n                            //////
//////                                          //////
////// [Example]                                //////
////// Input:                                   //////
////// 5 2             1---2                    //////
////// 1 2                /                     //////
////// 2 3               3                      //////
////// 3 4              / \                     //////
////// 3 5             4   5                    //////
//////                                          //////
////// Output:                                  //////
////// 4                                        //////
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
