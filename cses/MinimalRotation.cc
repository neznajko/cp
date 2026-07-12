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
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
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
# define key( p ) p.first
# define val( p ) p.second
////////////////////////////////////////////////////////////////
template <typename K, typename V>
ostream& operator<<( ostream& os, const pair<K,V>& p ){
    return os << "{"
              << key( p )
              << ","
              << val( p )
              << "}";
}
////////////////////////////////////////////////////////////////
OVERLOAD_OSTREAM_OPERATOR( vector );
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
//                                     [ Overclocked ]
//
//                                 Spark of neon light, 
//                      caught within the glowing gate. 
//                               The clock is dreaming.
//
//                                              Gemini
//
// <> 2.2.4*. In a time-of-flight mass spectrometer, a
// source emits a bunch of charged particles. The
// particles first travel freely and pass through the
// first detector D1, located at a distance L from a
// grid. Beyond the grid, an electric force F,
// directed perpendicular to the grid, acts on the
// particles. Under the action of this force, the
// particles reverse their direction and fly back
// through the grid, passing the second detector D2,
// which is located at the same distance L from the
// grid. The initial speed of the emitted particles
// depends on the source voltage, but its exact value
// is unknown. By varying the source voltage, the time
// interval Δt between the signals of the two
// detectors is measured, and its minimum value is
// determined. Find the mass of a particle. How can
// the masses of the particles be determined if the
// source emits several types of particles with
// different masses?
//                    Let the angle of the beam with
// `.       :<---- F  the vertical is α, the time from
//   `.|D1  :         D1 to the grid and from the grid
//     |.   :<----    to D2 is Δτ = L/υsinα, if Δt is
//       `. :         the time the particle is beyond
//         `:<----    the grid:) we have thus:
//          :`     
//        .`:<----        .      zo sinα = FΔt/2mυ
//     |.`  :           .` `.
//    .|D2  :<----   p.`. . .`.p the total time of
//  .`      :          FΔt       flight is:
// `   < L >:<----
//                    ΔT = 2Δτ + Δt =
// = 2L/υsinα + 2mυsinα/F, so as a function of
// x := υsinα ΔT(x) = 2L/x + 2mx/F, to find the 
// minimum we can use the derivative:
// ΔT(x)' = - 2L/x² + 2m/F = 0, 2L/x² = 2m/F,
// LF = mx², x = √(LF/m), the minimum ΔT is:
// ΔT = 2(L/x + mx/F) = 2(L/√(LF/m) + m√(LF/m)/F) =
// = 2(√(mL/F) + √(mL/F)) = 4√(mL/F), zo
// ΔT² = 16(mL/F), m = ΔT²F/16L, if we have different
// masses we just plot the time of flight as a 
// function of the voltage I guess and we should see
// different spectrums and minimums smth like thus
//
//////////////////////////////////////////////////////
// Yea that's a two pointer gem that according to
// DeepSeek is called Canonical Minimal Rotation
// Algorithm or Shiloach-Duval Algorithm based on
// their papers in the 80s. Yeah I first started with
// Suffix Array with sorting which notoriously fails
// for n=1e6:) There is also a Booth's algorithm that
// uses KMP prefix/failure function, but after staring
// at the code and understanding nothing have felt
// that KMP is not necessary at all, was very excited
// but didn't manage to implement it correctly and as
// usual with string algorithms have ended learning a
// new one:)
i32 CMR( const string& s ){
  i32 n = s.length();
  i32 i = 0;
  i32 j = 1;
  i32 k = 0;
  auto t = s + s;
  while( i < n and j < n and k < n ){
    if( t[i + k] == t[j + k] ){
      ++k;
    } else
    if( t[i + k] > t[j + k] ){
      i = i + k + 1;
      if( i == j ){
        ++i;
      }
      k = 0;
    } else {
      j = j + k + 1;
      if( j == i ){
        ++j;
      }
      k = 0;
    }
  }
  return min( i, j );
}
//////////////////////////////////////////////////////
void pusk() {
  auto s = loads<string>();
  dbg( s );
  auto i = CMR( s );
  dbg( i );
  auto m = s.substr( i ) + s.substr(0, i );
  cout << m << nl;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//                                       [ Aftermath ]
//
//                               The sand slowly falls,
//                                  erasing the memory 
//                                of the sudden strike.
//
//                                              Gemini
//
// 2.2.5*. A sandbox of mass M lies on a horizontal
// surface, with the coefficient of friction between
// them equal to μ. A bullet of mass m enters the box
// at an angle α to the vertical with speed v and
// almost instantaneously becomes embedded in the
// sand. After what time following the bullet's impact
// will the box, having started moving, come to a
// stop? For what value of α will the box not move at
// all?
//
// Lets Δt is the time of the impact we have:
//
// y: mυcosα = RΔt
// x: mυsinα - (M+m)u = μRΔt
//
// mυ(sinα - μcosα) = (M+m)u,
// u = mυ(sinα - μcosα)/(M+m),
// after that the sandbox + bullet is moving with
// acceleration a = μg and will stop after t = u/μg,
// 
// t = mυ(sinα - μcosα)/μg(M+m)
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
////// Minimal Rotation                         //////
//////                                          //////
////// A rotation of a string can be generated  //////
////// by moving characters one after another   //////
////// from beginning to end. For example, the  //////
////// rotations of acab are acab, caba, abac,  //////
////// and baca.  Your task is to determine the //////
////// lexicographically minimal rotation of a  //////
////// string.                                  //////
//////                                          //////
////// [Input]                                  //////
////// The only input line contains a string of //////
////// length n. Each character is one of a–z.  //////
//////                                          //////
////// [Output]                                 //////
////// Print the lexicographically minimal      //////
////// rotation.                                //////
//////                                          //////
////// [Constraints]                            //////
////// 1 <= n <= 1e6                            //////
//////                                          //////
////// [Example]                                //////
////// Input:                                   //////
////// acab                                     //////
//////                                          //////
////// Output:                                  //////
////// abac                                     //////
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
