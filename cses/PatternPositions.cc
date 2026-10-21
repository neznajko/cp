// -*- c-file-style: "gnu" -*-
//////////////////////////////////////////////////////
# include <iostream>
# include <string>
# include <vector>
# include <cstdint>
# include <array>
//////////////////////////////////////////////////////
using namespace std;
//////////////////////////////////////////////////////
constexpr char nl = '\n';
constexpr char sp = ' ';
//////////////////////////////////////////////////////
inline void vrooom() {
  cin.tie( nullptr )->sync_with_stdio( false );
}
//////////////////////////////////////////////////////
enum { BLACK, WHITE,  GRAY,    RED, 
       BLUE,  ORANGE, MAGENTA, BROWN };
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
using state_t = int32_t;
///////////////////////////////////// /  /////////////
constexpr int32_t ALPHACOUNT = 26;
constexpr state_t t0 = 0;
struct Record {
  int32_t len = 0;
  int32_t pos = -1;
  state_t prev = t0;
  array<state_t,ALPHACOUNT> next {};
};
//////////////////////////////////// /  //////////////
struct Automaton { // オスカル
  static Automaton cons( const string& T ){
    Automaton automaton;
    automaton.build( T );
    return automaton;
  }
  vector<Record> rec;
  state_t AVAIL = t0;
  state_t last = AVAIL;
  state_t NEWSTATE() { return ++AVAIL; }
  state_t CLONE( state_t p, state_t q ){
    auto clone = NEWSTATE();
    rec[ clone ] = rec[ q ];
    len( clone ) = len( p ) + 1;
    return clone;
  }
  state_t& prev( state_t u ){ return rec[ u ].prev; }
  state_t& next( state_t u, char c ){
    return rec[ u ].next[ c - 'a' ];
  }
  int32_t& len( state_t u ){ return rec[ u ].len; }
  int32_t& pos( state_t u ){ return rec[ u ].pos; }
  void initialize( int32_t cap ){
    rec.resize( cap );
    prev( t0 ) = -1;
  }
  void build( const string& T ){
    initialize( T.size() << 1 );
    for( char c: T ){
      addchar( c );
    }
  }
  void addchar( char c ){
    // a) 新しい状態を作成
    auto curr = NEWSTATE();
    pos( curr ) = pos( last ) + 1;
    // b) make new transitions starting from last
    auto p = last;
    do {
      next( p, c ) = curr;
      p = prev( p );
    } while( p >= t0 and !next( p, c ));
    // c) make suffix links
    last = curr;
    if( p < t0 ) return;
    auto q = next( p, c );
    if( len( p ) + 1 == len( q )){
      prev( curr ) = q;
      return; 
    }
    // d) clone
    auto clone = CLONE( p, q );
    prev( q ) = prev( curr ) = clone;
    do {
      next( p, c ) = clone;
      p = prev( p );
    } while( p >= t0 and next( p, c ) == q );
  }
  int32_t make_query( const string& P ){
    state_t p{ t0 };
    for( auto c: P ){
      if( !( p = next( p, c ))) return -1;
    }
    return pos( p ) - P.size() + 2;
  }
};
/////////////////////////////////// /  ///////////////
////////////////////////////////// /  ////////////////
void pusk() {
  string T; cin >> T;
  auto automaton = Automaton::cons( T );
  int32_t k; cin >> k;
  while( k-- ){
    string P; cin >> P;
    cout << automaton.make_query( P ) << nl;
  }
}
//////////////////////////////////////////////////////
// C 34. Prove or disprove: If n is an integer and
// n > 2, then there exists a prime p such that
// n < p < n!.
// #    @@  @@    ####################################
// #  @@  @@  @   ######  ###  #######################
// # @          @ ####  ###  #########################
// #  @@  @@  @@  ##             #####################
// # @          @   #  ###  ##########################
// # @  @@  @@  @ ###  ###  ##########################
// # @          @ ###          #######################
// #  @@@@  @@@@  ###  ###  ##########################
// # @          @ ###  ###  ######  ##################
// #  @@@@  @@@@  ###          ###  ############  ####
// # @          @ ###  ###  ######  ######  #####  ###
// #  @@@@  @@@@  ###  ###  ######  #######  ####  ###
// #  @@  @@  @@  ###          ###  ###  ###   #######
// # @  @@  @@  @ ###  ###  #######    #######   #####
// #  @@      @@  ####################################
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
////// Pattern Positions                        //////
//////                                          //////
////// Given a string and patterns, find for    //////
////// each pattern the first position          //////
////// (1-indexed) where it appears in the      //////
////// string.                                  //////
//////                                          //////
////// Input                                    //////
////// The first input line has a string of     //////
////// length n. The next input line has an     //////
////// integer k: the number of patterns.       //////
////// Finally, there are k lines that describe //////
////// the patterns. The string and the         //////
////// patterns consist of characters a–z.      //////
//////                                          //////
////// Output                                   //////
////// Print the first position for each        //////
////// pattern (or -1 if it does not appear at  //////
////// all).                                    //////
//////                                          //////
////// Constraints                              //////
////// 1 ≤ n ≤ 1e5                              //////
////// 1 ≤ k ≤ 5e5                              //////
////// the total length of the patterns is at   //////
////// most 5e5                                 //////
//////                                          //////
////// Example                                  //////
////// Input:                                   //////
////// aybabtu                                  //////
////// 3                                        //////
////// bab                                      //////
////// abc                                      //////
////// a                                        //////
//////                                          //////
////// Output:                                  //////
////// 3                                        //////
////// -1                                       //////
////// 1                                        //////
//////                                          //////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
///////////////////////////////////////////########///
///////////////////////////////////////////########///
// log:                                    ########
//                                         ### ####
//                                        ###  ### 
//                                       ##   ##   
//                                       #     #
