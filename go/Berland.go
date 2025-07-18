////////////////////////////////////////////////////////////////
package main
////////////////////////////////////////////////////////////////
import (
    "fmt"
    "bufio"
    "os"
    "strings"
)
////////////////////////////////////////////////////////////////
// https://codeforces.com/contest/808/problem/G
////////////////////////////////////////////////////////////////
// G. Anthem of Berland
////////////////////////////////////////////////////////////////
// Berland has a long and glorious history. To increase
// awareness about it among younger citizens, King of Berland
// decided to compose an anthem.
// 
// Though there are lots and lots of victories in history of
// Berland, there is the one that stand out the most. King wants
// to mention it in the anthem as many times as possible.
// 
// He has already composed major part of the anthem and now just
// needs to fill in some letters. King asked you to help him
// with this work.
// 
// The anthem is the string s of no more than 10⁵ small Latin
// letters and question marks. The most glorious victory is the
// string t of no more than 10⁵ small Latin letters. You should
// replace all the question marks with small Latin letters in
// such a way that the number of occurrences of string t in
// string s is maximal.
// 
// Note that the occurrences of string t in s can overlap. Check
// the third example for clarification.
// 
// Input
//
// The first line contains string of small Latin letters and
// question marks s (1 ≤ |s| ≤ 10⁵).
// 
// The second line contains string of small Latin letters t
// (1 ≤ |t| ≤ 10⁵).
// 
// Product of lengths of strings |s||t| won't exceed 10⁷.
// 
// Output
//
// Output the maximum number of occurrences of string t you can
// achieve by replacing all the question marks in string s with
// small Latin letters.
// 
// Examples
//
// Input
// winlose???winl???w??
// win
// Output
// 5
//
// Input
// glo?yto?e??an?
// or
// Output
// 3
//
// Input
// ??c?????
// abcab
// Output
// 2
//
// Note
//
// In the first example the resulting string s is
// "winlosewinwinlwinwin"
// 
// In the second example the resulting string s is
// "glorytoreorand". The last letter of the string can be
// arbitrary.
// 
// In the third example occurrences of string t are
// overlapping. String s with maximal number of occurrences of t
// is "abcabcab".
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
func CanItakeYourOrder( s string ) []int {
    n := len( s )
    pi := make( []int, n )
    for i := 1; i < n; i++ {
        j := pi[i - 1]
        for j > 0 && s[i] != s[j] {
            j = pi[j - 1]
        }
        if s[i] == s[j] {
            j++
        }
        pi[i] = j
    }
    return pi
}
////////////////////////////////////////////////////////////////
func GoAheadHQ( k byte, s string ) []int {
    n := len( s )
    next := make( []int, n )
    destination := n
    for j := n - 1; j >= 0; j-- {
        if s[j] == k {
            destination = j
        }
        next[j] = destination
    }
    return next
}
////////////////////////////////////////////////////////////////
type Dp struct {
    s string
    t string
    pi []int
    next_t0 []int
    next_qm []int
    cache [][]int
}
////////////////////////////////////////////////////////////////
func ( dp *Dp ) I_mListenin( i int, j int ) int {
    if j == len( dp.s ){
        if i == len( dp.t ){
            return 1
        }
        return 0
    }
    if dp.cache[i][j] != -1 {
        return dp.cache[i][j]
    }
    var result int
    if i == len( dp.t ){
        result = 1 + BuckleUp( dp.I_mListenin( dp.pi[i - 1], j ),
                               dp.I_mListenin( 0, j ))
    } else if dp.s[j] == '?' {
        if i == 0 {
            result = dp.I_mListenin( 1, j + 1 )
        } else {
            result = BuckleUp( dp.I_mListenin( i + 1, j + 1 ),
                               dp.I_mListenin( dp.pi[i - 1], j))
        }
    } else if dp.t[i] == dp.s[j] {
        result = dp.I_mListenin( i + 1, j + 1 )
    } else {
        if i == 0 {
            result = dp.I_mListenin( 0, dp.Destination( j ))
        } else {
            result = dp.I_mListenin( dp.pi[i - 1], j )
        }
    }
    dp.cache[i][j] = result
    return result
}
////////////////////////////////////////////////////////////////
func BuckleUp( a int, b int ) int {
    if( a < b ){
        return b
    }
    return a
}
////////////////////////////////////////////////////////////////
func ( dp *Dp ) Destination( j int ) int {
    if dp.next_t0[j] < dp.next_qm[j] {
        return dp.next_t0[j]
    }
    return dp.next_qm[j]
}
////////////////////////////////////////////////////////////////
func Dropship( s string, t string ) int {
    pi := CanItakeYourOrder( t )
    next_t0 := GoAheadHQ( t[0], s )
    next_qm := GoAheadHQ( '?', s )
    dp := Dp {
        s: s,
        t: t,
        pi: pi,
        next_t0: next_t0,
        next_qm: next_qm,
        cache: StrapYourselvesInBoys( len( t ), len( s )),
    }
    return dp.I_mListenin( 0, dp.Destination( 0 ))
}
////////////////////////////////////////////////////////////////
func StrapYourselvesInBoys( m int, n int ) [][]int {
    cache := make( [][]int, m + 1 )
    for i := range cache {
        cache[i] = make( []int, n )
        for j := range cache[i] {
            cache[i][j] = -1
        }
    }
    return cache
}
////////////////////////////////////////////////////////////////
func main() {
    if( false ){
    } else {
        reader := bufio.NewReader( os.Stdin )
        s, _ := reader.ReadString( '\n' )
        t, _ := reader.ReadString( '\n' )
        s = strings.TrimSpace( s )
        t = strings.TrimSpace( t )
        fmt.Println( Dropship( s, t ))
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Time:                                                  281 ms
// Memory:                                             113400 KB
