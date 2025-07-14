////////////////////////////////////////////////////////////////
use std::io;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// spoj.com/problems/NAJPF/
////////////////////////////////////////////////////////////////
// NAJPF - Pattern Find
// #kmp-algorithm
////////////////////////////////////////////////////////////////
// Your task is so simple given a string and a pattern. You find
// the pattern on the given string. If found print how many time
// found the pattern and their index. Otherwise print ‘Not Found’
////////////////////////////////////////////////////////////////
// Input
// The input line consists of a number T (1 ≤ T ≤ 50) test cases.
// For each case given two string number A,B. the string and the
// pattern  1 ≤ |A|, |B| ≤ 10^6
// 
// All character will be lowercase Latin character. And | | is
// the length of string.
////////////////////////////////////////////////////////////////
// Output
// For each case print the number (found pattern from the given
// string) next line their positions. Otherwise print 'Not Found'
// without quotes.
// 
// Output a blank line between two cases.
// 
// Example
// Input:
// 3
// ababab ab
// aaaaa bbb
// aafafaasf aaf
// 
// Output:
// 3
// 1 3 5
// 
// Not Found
// 
// 1
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
fn systems_functional() -> String {
    let mut input = String::new();
    io::stdin().read_line( &mut input ).unwrap();
    return input.trim().to_string();
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
fn roger() -> ( String, String ){
    let line = systems_functional();
    let mut tuple = line.split_ascii_whitespace();
    let txt = tuple.next().expect( "wow!" ).to_string();
    let key = tuple.next().expect( "what is this?" ).to_string();
    return ( txt, key );
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
fn i_dentify_target( s: &str ) -> Vec<usize> {
    let n = s.len();
    let bytes = s.as_bytes();
    let mut pi: Vec<usize> = vec![ 0; n ];
    for i in 1..n {
        let mut j = pi[i - 1];
        while j > 0 && bytes[i] != bytes[j] {
            j = pi[j - 1];
        }
        if bytes[i] == bytes[j] {
            j += 1;
        }
        pi[i] = j;
    }
    return pi;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
fn nav_comm_locked( txt: &str, key: &str ){
    let s = format!( "{}#{}", key, txt );
    let pi = i_dentify_target( &s );
    let len = key.len();
    let n = s.len();
    let mut offsets = Vec::new();
    for j in len + 1..n {
        if pi[ j ] == len {
            offsets.push( j - 2 * len + 1 );
        }
    }
    if offsets.is_empty() {
        println!( "Not Found" );
    } else {
        println!( "{}", offsets.len() );
        for off in offsets {
            print!( "{} ", off );
        }
        println!();
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
fn main() {
    let t: i32 = systems_functional().parse().expect( "oo" );
    for _ in 0..t {
        let ( txt, key ) = roger();
        nav_comm_locked( &txt, &key );
        println!();
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// TIME                                                     0.07
// MEM                                                       13M
