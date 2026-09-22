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
i32 n;
vector<i32> P;
vector<i32> I;
vector<i32> M;
struct Node {
  i32 value;
  Node* left = nullptr;
  Node* ryte = nullptr;
  Node( i32 value ): value( value ){}
};
//////////////////////////////////////////////////////
// Node* build( i, l, r ):
//   u = P[i]
//   node = Node( u )
//   j = M[u]
//   if( j > l ){
//     node.left = build( i + 1, l, j - 1 )
//   }
//   if( j < r ){
//     node.ryte = build( i + 1 + j - l, j + 1, r )
//   }
//   return node
//////////////////////////////////////////////////////
// i - position of root in P
// l,r - tree range in I
Node* build( i32 i, i32 l, i32 r ){
  auto u = P[i];
  auto node = new Node( u );
  auto j = M[u];
  if( j > l ){
    node->left = build( i + 1, l, j - 1 );
  }
  if( j < r ){
    node->ryte = build( i + 1 + j - l, j + 1, r );
  }
  return node;
}
void preorder( Node* root ){
  if( !root ) return;
  cout << root->value << sp;
  preorder( root->left );
  preorder( root->ryte );
}
void inorder( Node* root ){
  if( !root ) return;
  inorder( root->left );
  cout << root->value << sp;
  inorder( root->ryte );
}
void postorder( Node* root ){
  if( !root ) return;
  postorder( root->left );
  postorder( root->ryte );
  cout << root->value << sp;
}
void pusk() {
  n = loads<i32>(); dbg( n );
  P = loadv<i32>( n ); dbg( P );
  I = loadv<i32>( n ); dbg( I );
  M.resize( n + 1 );
  for( i32 j = 0; j < n; ++j ){
    M[I[j]] = j;
  }
  dbg( M );
  Node* root = build( 0, 0, n - 1 );
# ifdef DeBug  
  preorder( root );
  cout << nl;
  inorder( root );
  cout << nl;
# endif  
  postorder( root );
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
////// Tree Traversals                          //////
//////                                          //////
////// There are three common ways to traverse  //////
////// the nodes of a binary tree:              //////
//////                                          //////
////// Preorder: First process the root, then   //////
////// the left subtree, and finally the right  //////
////// subtree.                                 //////
//////                                          //////
////// Inorder: First process the left subtree, //////
////// then the root, and finally the right     //////
////// subtree.                                 //////
//////                                          //////
////// Postorder: First process the left        //////
////// subtree, then the right subtree, and     //////
////// finally the root.                        //////
//////                                          //////
////// There is a binary tree of n nodes with   //////
////// distinct labels. You are given the       //////
////// preorder and inorder traversals of the   //////
////// tree, and your task is to determine its  //////
////// postorder traversal.                     //////
//////                                          //////
////// [Input]                                  //////
////// The first input line has an integer n:   //////
////// the number of nodes. The nodes are       //////
////// numbered 1,2,...,n. After this, there    //////
////// are two lines describing the preorder    //////
////// and inorder traversals of the tree. Both //////
////// lines consist of n integers. You can     //////
////// assume that the input corresponds to a   //////
////// binary tree.                             //////
//////                                          //////
////// [Output]                                 //////
////// Print the postorder traversal of the     //////
////// tree.                                    //////
//////                                          //////
////// [Constraints]                            //////
////// 1 ≤ n ≤ 1e5                              //////
//////                                          //////
////// [Example]                                //////
////// Input:                                   //////
////// 5                                        //////
////// 5 3 2 1 4                                //////
////// 3 5 1 2 4                                //////
//////                                          //////
////// Output:                                  //////
////// 3 1 4 2 5                                //////
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
