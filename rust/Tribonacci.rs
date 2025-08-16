////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//                  leetcode.com/problems/n-th-tribonacci-number/
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//                                  1137. N-th Tribonacci Number
////////////////////////////////////////////////////////////////
//             The Tribonacci sequence Tn is defined as follows: 
//      T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2, for
//                                                        n >= 0
//                              Given n, return the value of Tn.
//                                                    Example 1:
//                                                  Input: n = 4
//                                                     Output: 4
//                                                  Explanation:
//                                           T_3 = 0 + 1 + 1 = 2
//                                           T_4 = 1 + 1 + 2 = 4
//                                                    Example 2:
//                                                 Input: n = 25
//                                               Output: 1389537
//                                                  Constraints:
//                                                  0 <= n <= 37
//      The answer is guaranteed to fit within a 32-bit integer,
//                                       ie. answer <= 2^31 - 1.
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
struct Solution;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// 沖縄の海はとてもきれいでした。
// この部屋はちょっと暑いです。
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
impl Solution {
    pub fn tribonacci( n: i32 ) -> i32 {
        let mut a = [ 0, 1, 1 ];
        for j in 3..=(n as usize) {
            a[j % 3] = a[(j - 3) % 3] +
                       a[(j - 2) % 3] +
                       a[(j - 1) % 3];
        }
        return a[( n % 3 ) as usize ];
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// <> 2.1.48: Between two identical smooth bars of mass m₁ each,
// a wedge of mass m₂ with an angle α is inserted. Determine the
// acceleration of the bodies.
// #############################################################
// ###      __m₂____      ####      Tʸ    T  ## The system will 
// ###      \      /      #### `.   .   .`   ## start moving    
// ###   _m₁_\ α  /__m₁   ####   `. . .`     ## due to the force
// ###  |    |\  /|    |  ####. . .`.`. . Tˣ ## of gravity and  
// ###  |    | \/ |    |  ####      .`.      ## the reaction    
// ###  |____|    |____|  ####      .  `.    ## force T between 
// ############################################ bodies, it is   
// ### directed perpendicular to the wedge planes and its 
// ### componets are: Tˣ = T cos(α/2) and Tʸ = T sin(α/2)
// #############################################################
// ### Now if we write Newton equations we get:
// ### Tˣ = m₁a₁ = T cos(α/2)                                (1)
// ### m₂g - 2Tʸ = m₂a₂, 2T sin(α/2) = m₂(g - a₂)            (2)
// #############################################################
// ### Two equations for the three unknown T, a₁ and a₂. Becoz
// ### bodies are in contact we have connections between their
// ### motions. So if the wedge drops at distance Δy the bars
// ### will move at distance Δx with relation tg(α/2) = Δx/Δy,
// ### cos Δx = (1/2)a₁Δt² and Δy = (1/2)a₂Δt², we have:
// ### tg(α/2) = a₁/a₂ - the missing piece in the puzzle:)
// #############################################################
// ### Dividing (2) by (1) we get 2tg(α/2) = m₂(g - a₂)/m₁a₁, zo
// ### 2m₁a₁tg(α/2) = 2m₁a₂tg²(α/2) = m₂(g - a₂), hence
// ### a₂ = m₂g/(m₂ + 2m₁tg²(α/2)), a₁ = a₂tg(α/2)             «
// #############################################################
// #############################################################
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
fn main() {
    println!( "{}", Solution::tribonacci( 25 ));
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// 53.Fred needs to choose a password for a certain website.
// Assume that he will choose an 8-character password, and that
// the legal characters are the lowercase letters a-z, the
// uppercase letters A-Z, and the numbers 0-9.
//
// (a) How many possibilities are there if he is required to
// have at least one lowercase letter in his password?
//
// Lets L is the event there is at least one lowercase letter.
// Here it is easier to find the probability P(Lᶜ) of the
// complementary event. Becoz if there are no lowercase letters,
// we have 26 + 10 variants for each password position, hence
// P(Lᶜ) = 36**8/62**8 = (18/31)**8 ≈ 0.0129, zo P(L) ≈ 0.9870
//
// (b) How many possibilities are there if he is required to
// have at least one lowercase letter and at least one uppercase
// letter in his password?
//
// Here we have to use the inclusion exclusion I'm afraid:)
// Let U is the event we have at least one uppercase letter,
// we are looking for P(L ∩ U), zo we have this:
// P(L ∪ U) = P(L) + P(U) - P(L ∩ U), now the complimentary of
// L ∪ U is the event that there are only digits, zo
// 1 - P(L ∪ U) = 10**8/62**8 = (5/31)**8, zo
// P(L ∩ U) = P(L) + P(U) - P(L ∪ U) = 2(1 - (18/31)**8) -
// (1 - (5/31)**8), this looks pretty ugly ofcource, but is equal
// approximately to P(L ∩ U) ≈ 0.9742
//     
// (c) How many possibilities are there if he is required to
// have at least one lowercase letter, at least one uppercase
// letter, and at least one number in his password?
//
// Now this is getting tedious, ok so we need another event:
// D there is at least one digit, zo:
// 1 = P(L ∪ U ∪ D) = P(L) + P(U) + P(D) - P(L ∩ U) - P(L ∩ D)
// - P(U ∩ D) + P(L ∩ U ∩ D), now we need to calculate:
// P(D) and P(U ∩ D) = P(L ∩ D), there might be shortcut but I
// don't see it so i go straightforward:
//
// P(Dᶜ) = 52**8/62**8 = (26/31)**8 zo P(D) = 1 - P(Dᶜ) ≈ 0.7552
// P(D ∪ U) = P(D) + P(U) - P(U ∩ D),
// 1 - P(D ∪ U) = P(only lowercase letters) = (13/31)**8, zo
// P(U ∩ D) = P(D) + P(U) + 1 - P(D ∪ U) - 1 =
// = 1 - (26/31)**8 + 1 - (18/31)**8 + (13/31)**8 - 1 =
// = 1 - (26/31)**8 - (18/31)**8 + (13/31)**8 ≈ 0.7432, zo
// P(L ∩ U ∩ D) = 1 - P(L) - P(U) - P(D) + P(L ∩ U) + P(L ∩ D)
// + P(U ∩ D) = 1 - (P(U) + P(D) - P(U ∩ D)) - P(L) + P(L ∩ U)
// + P(L ∩ D) = 1 - P(D ∪ U) - (P(L) + P(D) - P(L ∩ D)) + P(D)
// + P(L ∩ U) = 1 - 2P(D ∪ U) + P(D) + P(L ∩ U) =
// = 1 - 2(1 - (13/31)**8) + (1 - (26/31)**8) + (1 - (5/31)**8)
// = 1 + 2(13/31)**8 - (26/31)**8 - (5/31)**8 ≈ 0.7571
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// The dead black tree is on the hill
// I'm not telling which corner
// My sight goes steeply down, along the shore
// The sea ain't flat
// It's on the left, but it's not normal
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Runtime:                                 0 ms | Beats 100.00%
// Memory:                                2.14 MB | Beats 38.98%
