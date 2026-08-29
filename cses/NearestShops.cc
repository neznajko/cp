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
using Node = tuple<i32,i32,i32>;
ostream& operator<<( ostream& s, const Node& node ){
  return s << "("
           << get<0>( node ) << " "
           << get<1>( node ) << " "
           << get<2>( node ) << ")";    
}
//////////////////////////////////////////////////////
template <typename T>
struct Deque {
  static constexpr i32 CAP = 1e6;
  vector<T> bufr;
  i32 front = 0;
  i32 rear = 0;
  Deque() {
    bufr.resize( CAP );
  }
  void push( const T& x ){
    bufr[rear++] = x;
  }
  const T& pop() {
    return bufr[front++];
  }
  bool empty() {
    return front == rear;
  }
};
template <typename T>
ostream& operator<<( ostream& s, const Deque<T>& deq ){
  s << "{";
  string sep = "";
  for( i32 i = deq.front; i < deq.rear; ++i ){
    s << sep << deq.bufr[i];
    sep = " ";
  }
  return s << "}";
}
//////////////////////////////////////////////////////
i32 inf;
i32 n, m;
vector<i32> anime;
vector<vector<i32>> adj;
////////////////////////////////////////////////// P&G
// deq = [] # { vertex, dist, nearshop }
// dist = [inf]*(n + 1)
// nearshop = [0]*(n + 1)
// for s in anime:
//   dist[s] = 0
//   nearshop[s] = s;
//   deq.push({ s, 0, s })
// while deq:
//   u,d,s = deq.pop()
//   for v in adj[u]:
//     if v == s: continue
//     if d + 1 < dist[v]:
//       dist[v] = d + 1
//       nearshop[v] = s
//       deq.push({ v, dist[v], s })
//     else:
//       t = nearshop[v]
//       if t == s: continue
//       b = dist[v] + d + 1
//       if dist[s] == 0 or dist[s] > b:
//         dist[s] = b
//         nearshop[s] = t
//       if dist[t] == 0 or dist[t] > b:
//         dist[t] = b
//         nearshop[t] = s
// for s in [1..n]:
//   if dist[s] == 0 or dist[s] == inf: print( -1 )
//   else: print( dist[s] )
//
// 3-1*-2*
// deq=[]
// dist=[inf,]
// nearshop=[0,]
// u=,d=,s=
// v=,t=,b=
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
vector<i32> dist;
vector<i32> nearshop;
Deque<Node> deq;
//////////////////////////////////////////////////////
void bfs() {
  dist.resize( n + 1, inf );
  nearshop.resize( n + 1, 0 );
  for( auto s: anime ){
    dist[s] = 0;
    nearshop[s] = s;
    deq.push({ s, 0, s });
  }
  dbg( dist );
  dbg( deq );
  while( !deq.empty()){
    auto [u,d,s] = deq.pop();
    for( auto v: adj[u] ){
      if( v == s ) continue;
      if( d + 1 < dist[v] ){
        dist[v] = d + 1;
        nearshop[v] = s;
        deq.push({ v, dist[v], s });
      } else {
        auto t = nearshop[v];
        if( t == s ) continue;
        auto b = dist[v] + d + 1;
        if( dist[s] == 0 or dist[s] > b ){
          dist[s] = b;
          nearshop[s] = t;
        }
        if( dist[t] == 0 or dist[t] > b ){
          dist[t] = b;
          nearshop[t] = s;
        }
      }
    }
  }
}
//////////////////////////////////////////////////////
void pusk() {
  tie( n,m ) = loadp<i32>(); dbg2( n, m );
  inf = m + 1;
  auto k = loads<i32>();
  anime = loadv<i32>( k ); dbg( anime );
  adj.resize( n + 1 );
  for( i32 j = 0; j < m; ++j ){
    auto [a,b] = loadp<i32>();
    adj[a].push_back( b );
    adj[b].push_back( a );
  }
  dbg( adj );
  bfs();
  for( i32 s = 1; s <= n; ++s ){
    if( dist[s] == 0 or dist[s] == inf ){
      cout << -1 << sp;
    } else {
      cout << dist[s] << sp;
    }
  }
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////

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
////// Nearest Shops                            //////
//////                                          //////
////// There are n cities and m roads. Each     //////
////// road is bidirectional and connects two   //////
////// cities. It is also known that k cities   //////
////// have an anime shop. If you live in a     //////
////// city, you of course know the local anime //////
////// shop well if there is one. You would     //////
////// like to find the nearest anime shop that //////
////// is not in your city. For each city,      //////
////// determine the minimum distance to        //////
////// another city that has an anime shop.     //////
//////                                          //////
////// [Input]                                  //////
////// The first line has three integers n, m   //////
////// and k: the number of cities, roads and   //////
////// anime shops. The cities are numbered     //////
////// 1,2,...,n. The next line contains k      //////
////// integers: the cities that have an anime  //////
////// shop. Finally, there are m lines that    //////
////// describe the roads. Each line has two    //////
////// integers a and b: there is a road        //////
////// between cities a and b.                  //////
//////                                          //////
////// [Output]                                 //////
////// Print n integers: for each city, the     //////
////// minimum distance to another city with an //////
////// anime shop. If there is no such city,    //////
////// print -1 instead.                        //////
//////                                          //////
////// [Constraints]                            //////
////// 1 ≤ k ≤ n ≤ 1e5                          //////
////// 0 ≤ m ≤ 2e5                              //////
//////                                          //////
////// [Example]                                //////
////// Input:                                   //////
////// 9 6 4                                    //////
////// 2 4 5 7                                  //////
////// 1 2                                      //////
////// 1 3                                      //////
////// 1 8                                      //////
////// 2 4                                      //////
////// 3 4                                      //////
////// 5 6                                      //////
//////                                          //////
////// Output:                                  //////
////// 1 1 1 1 -1 1 -1 2 -1                     //////
//////                                          //////
//////////////////////////////////////////////////////
///////////////////////////////////////////########///
///////////////////////////////////////////########///
///////////////////////////////////////////########///
// log: Yea don't understand nofhing from  ########
// economics but the wild capitalism in US ### ####
// will fail against what they have in    ###  ### 
// China cos this is not the Soviet      ##   ##   
// communism, it seems the main conflict  #     #
// is private vs public property, back in the Ancient
// Greece with Aristotle vs Plato debate so to speak;
// communism prove wrong but capitalism also is wrong
// cos it tends to turn itself into selfishness and
// creates monsters which are more powerful then the
// country and suddenly politicians start working for
// the interest of few. Obviously I'm also not very
// familiar with the Chinese system, but it seems they
// have found some way to balance this private vs
// public conflict, so if you wanna have a chance
// against China you have to stop fighting in the both
// extremes and find a way how to balance that stuff
