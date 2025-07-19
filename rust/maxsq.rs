////////////////////////////////////////////////////////////////
use std::cmp::min;
use std::cmp::max;
////////////////////////////////////////////////////////////////
// https://leetcode.com/problems/maximal-square/
////////////////////////////////////////////////////////////////
struct Solution;
////////////////////////////////////////////////////////////////
impl Solution {
    pub fn maximal_square( mat: Vec<Vec<char>> ) -> i32 {
        return Add_OnComplete( NotEnoughMinerals( mat ));
    }
}
////////////////////////////////////////////////////////////////
#[ allow( non_snake_case )]
fn Add_OnComplete( mut dp: Vec<Vec<i32>> ) -> i32 {
    let mut maxsq = 0;
    let m = dp.len();
    let n = dp[0].len();
    for i in ( 0..m ).rev() {
        for j in ( 0..n ).rev() {
            if dp[i][j] == 1 {
                let a = dp[i + 1][j + 1];
                let b = dp[i + 1][j];
                let c = dp[i][j + 1 ];
                dp[i][j] = 1 + min( a, min( b, c ));
                maxsq = max( maxsq, dp[i][j].pow( 2 ));
            }
        }
    }
    return maxsq;
}
////////////////////////////////////////////////////////////////
#[ allow( non_snake_case )]
fn NotEnoughMinerals( mat: Vec<Vec<char>> ) -> Vec<Vec<i32>> {
    let m = mat.len();
    let n = mat[0].len();
    let mut dp = vec![vec![0; n + 1]; m + 1];
    for i in 0..m {
        for j in 0..n {
            dp[i][j] = (mat[i][j] as u8 - b'0') as i32;
        }
    }
    return dp
}
////////////////////////////////////////////////////////////////
fn main() {                              ////////
    let mat = vec![                     ////////
        vec!['1','0','0','1','1'],     ////////
        vec!['0','1','1','1','1'],    ////////
        vec!['0','0','1','1','1'],
        vec!['0','1','0','1','0'],
    ];
    let result = Solution::maximal_square( mat );
    println!( "{}", result );
}
////////////////////////////////////////////////////////////////
// Runtime                                   7 ms | Beats 51.85%
// Memory                                9.26 MB | Beats 100.00%
