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
// feels like the good old days hacking with FORTRAN
constexpr i32 CAP = 200001;
// ---------------------------------------------------
i64 value[CAP];
vector<i32> adj[CAP];
i64 tin[CAP];
i64 path[CAP];
i64 subs[CAP]; // all caps
i64 tree[CAP]; // fenwick

i32 n, q;
i32 cntr = 0;
// ---------------------------------------------------
void dfs( i32 u, i32 t ){
  tin[u] = ++cntr;
  path[u] = path[t] + value[u];
  tree[tin[u]] = path[u];
  for( auto v: adj[ u ]){
    if( v != t ){ dfs( v, u ); }
  }
  subs[u] = cntr - tin[u] + 1;
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void constree() {
  for( i32 k = n; k > 0; --k ){
    tree[k] -= tree[k - (k & -k)];
  }
}
i64 sum( i32 k ){
  i64 s = 0;
  while( k > 0 ){
    s += tree[k];
    k -= k & -k;
  }
  return s;
}
void add( i32 k, i64 x ){
  while( k <= n ){
    tree[k] += x;
    k += k & -k;
  }
}
// ###################################################
i64 sumq( i32 s ){
  auto k = tin[s];
  return sum( k );
}
void changeq( i32 s, i64 x ){
  auto w = value[s];
  auto a = tin[s];
  auto b = a + subs[s];
  add( a, x - w );
  add( b, w - x );
  value[s] = x;
}
// ===================================================
void pusk() {
  tie( n, q ) = loadp<i32>(); dbg2( n, q );
  for( i32 k = 1; k <= n; ++k ){
    cin >> value[k];
  }
  for( i32 k = 1; k < n; ++k ){
    auto [a,b] = loadp<i32>();
    adj[a].push_back( b );
    adj[b].push_back( a );
  }
  dmp( value, n + 1 );
  dmp( adj, n + 1 );
  dfs( 1, 0 );
  dmp( tin, n + 1 );
  dmp( path, n + 1 );
  dmp( subs, n + 1 );
  dmp( tree, n + 1 );
  constree();
  dmp( tree, n + 1 );
  for( i32 j = 0; j < q; ++j ){
    auto [t,s] = loadp<i32>();
    if( t == 1 ){
      auto x = loads<i64>();
      changeq( s, x );
    } else {
      cout << sumq( s ) << nl;
    }
  }
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
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
////////                                      ////////
////////             Path Queries             ////////
////////                                      ////////
//////// You are given a rooted tree          ////////
//////// consisting of n nodes. The nodes are //////// 
//////// numbered 1,2,..,n, and node 1 is the //////// 
//////// root. Each node has a value.         ////////
////////                                      ////////
//////// Your task is to process following    //////// 
//////// types of queries:                    ////////
////////                                      ////////
//////// 1 change the value of node s to x    ////////
//////// 2 calculate the sum of values on the ////////
////////   path from the root to node s       ////////
////////                                      ////////
//////// [ Input ]                            ////////
//////// The first input line contains two    ////////
//////// integers n and q: the number of      ////////
//////// nodes and queries. The nodes are     ////////
//////// numbered 1,2,..,n. The next line has ////////
//////// n integers v_1,v_2,..,v_n: the value ////////
//////// of each node. Then there are n-1     ////////
//////// lines describing the edges. Each     ////////
//////// line contains two integers a and b:  ////////
//////// there is an edge between nodes a and ////////
//////// b. Finally, there are q lines        ////////
//////// describing the queries. Each query   ////////
//////// is either of the form "1 s x" or     ////////
//////// "2 s".                               ////////
////////                                      ////////
//////// [ Output ]                           ////////
//////// Print the answer to each query of    ////////
//////// type 2.                              ////////
////////                                      ////////
//////// [ Constraints ]                      ////////
////////                                      ////////
//////// 1 <= n, q <= 2e5                     ////////
//////// 1 <= a,b, s <= n                     ////////
//////// 1 <= v_i, x <= 1e9                   ////////
////////                                      ////////
//////// [ Example ]                          ////////
//////// Input:                               ////////
//////// 5 3                                  ////////
//////// 4 2 5 2 1                            ////////
//////// 1 2                                  ////////
//////// 1 3                                  ////////
//////// 3 4                                  ////////
//////// 3 5                                  ////////
//////// 2 4                                  ////////
//////// 1 3 2                                ////////
//////// 2 4                                  ////////
////////                                      ////////
//////// Output:                              ////////
//////// 11                                   ////////
//////// 8                                    ////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// log: Yeah I could be totally wrong here, but there
// is some question bothering me: What will happen
// with Europe when China GDP become namba one, and
// the glue that binds the American nation together
// disappear. Remember Trump saying: Europe is going
// to hell, but we have big beautiful ocean between us
// etc., what will stop the inferno in Moscow to
// unleash its bloodthirsty?( Yeah I'm still playing
// H3 ) By the way America is named after Amerigo
// Vespucci, which name on its turn has German
// origins. So even if China is not growing America is
// declining right this doesn't need proof otherwise
// why they have MAGA, I mean we were great but smth
// has happened and we've lost our greatness, of
// course they blame the left for this but that's
// their job to blame each other. So my statement is
// that the American decline has started when the idea
// of winner equals good and looser equals bad become
// dominant moral framework, I'm not an expert on
// American society, but my estimation is that this
// has happened around 80s or 90s. Thats explain a
// lots of things like why in America it is publicly
// acceptable to humiliate other people like Fox News
// going after transgenders or even mocking nations
// like Kazakhstan in the film Borat? Or why they have
// much more comedians, then they have jokes? So if
// you are loser you are bad unlucky cursed by Gods
// etc., so you have to be humiliated publicly to give
// lessons for the others. Which of course is bullshit
// or horseshit I'm not sure. Most of this winner
// mentality is based on someone else achievements
// like being proud of something you have nothing in
// common, so to feel happy with only proud without
// struggling for anything you need some losers to
// laugh at, so pride and winner mentality leads to
// arrogance, abuse, humiliation and hate, that is the
// reason why American nation is so divided, so if you
// wanna MAGA you need to learn how to respect each
// other and what human dignity is
