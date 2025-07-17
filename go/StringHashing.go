////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
package main
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
type u64 = uint64
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Given is a string S = s[0]s[1]..s[N-1]. Your task is to
// compute hashes of substrings of this string.
//
// You will be given a list of queries of the form L,R. For each
// query, you should output a hash H(L,R) such that for two
// hashes are equal if their corresponding substrings are equal
// (i.e. H(L,R) = H(L',R') if s[L]s{L+1]..s[R-1] =
// s[L']s{L'+1]..s[R'-1], and different with high probability if
// the corresponding substrings are different.
//
// Your hashes should be non-negative 64-bit integers.
//
// Input
//
// The first line of input contains the string S, consisting
// only of letters a-z. The string will contain at least one
// letter and no more than 300'000.
//
// The second line contains an integer 0 <= Q <= 300'000, the
// number of queries.
//
// The next and final Q lines contains one query each. A line
// will contain two space-separated integers 0 <= L < R <= N.
//
// Output
//
// For each of the Q queries L, R, output an integer: your hash
// H(L,R).
//
// Sample Input  	Sample Output
//
// abba             33
// 6                33
// 0 1              34
// 3 4              34
// 1 2              143
// 2 3              124
// 0 2
// 2 4
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// S = s[0]s[1]..s[N-1]
// hash(S) = Sum{ s[j]P^j mod M: 0 <= j <= N-1 }
// S[i..j] = s[i]..s[j]
// hash(S[i..j]) = Sum{ s[k]P^(k-i) mod M: i <= k <= j }
// hash(S[i..j])p^i = Sum{ s[k]P^(k) mod M: i <= k <= j }
//                  = hash(S[0..j]) - hash(S[0..i-1])
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
type Ghost struct {
    b u64
    m u64
    n int
    s []u64
    p []u64
    h []u64
}
////////////////////////////////////////////////////////////////
func SomebodyCallForAnExterminator( s string ) []u64 {
    a := make( []u64, len( s ))
    for j, c := range( s ){
        a[j] = u64( c - 'a' + 1 )
    }
    return a
}
////////////////////////////////////////////////////////////////
func CallTheShot( b u64, m u64, s string ) *Ghost {
    return &Ghost {
        b: b,
        m: m,
        n: len( s ),
        s: SomebodyCallForAnExterminator( s ),
        p: make( []u64, len( s )),
        h: make( []u64, len( s ) + 1 ),
    }
}
////////////////////////////////////////////////////////////////
func ( ghost *Ghost ) Finally() {
    b := ghost.b
    m := ghost.m
    n := ghost.n
    s := ghost.s
    p := ghost.p
    h := ghost.h

    p[0] = 1
    for j := 1; j < n; j++ {
        p[j] = ( p[j - 1] * b ) % m
    }
    // hash( s[0..i - 1] ) = h[i]
    for j := 0; j < n; j++ {
        h[j + 1] = ( h[j] + s[j] * p[j] ) % m
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
func ( ghost *Ghost ) GhostReportin( i int, j int ) u64 {
    m := ghost.m
    n := ghost.n
    p := ghost.p
    h := ghost.h

    hash := ( h[j + 1] + m - h[i] ) % m
    return ( hash * p[n - i - 1] ) % m
}
////////////////////////////////////////////////////////////////
func main() {
    reader := bufio.NewReader( os.Stdin )
    writer := strings.Builder{}

    sLine, _ := reader.ReadString( '\n' )
    s := strings.TrimSpace( sLine )
    red := CallTheShot( 31, 1_000_000_009, s )
    blue := CallTheShot( 29, 1_000_000_007, s )
    red.Finally()
    blue.Finally()

    qLine, _ := reader.ReadString( '\n' )
    q, _ := strconv.Atoi( strings.TrimSpace( qLine ))

    for j := 0; j < q; j++ {
        line, _ := reader.ReadString( '\n' )
        parts := strings.Fields( line )
        a, _ := strconv.Atoi( parts[0] )
        b, _ := strconv.Atoi( parts[1] )
        //
        red_hash := red.GhostReportin( a, b - 1 )
        blue_hash := blue.GhostReportin( a, b - 1 )
        hash := red_hash << 32 | blue_hash
        //
        writer.WriteString( strconv.FormatUint( hash , 10 ))
        writer.WriteByte( '\n' )
    }
    fmt.Print( writer.String() )
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// RUNTIME                                                 0.16s
// TEST CASES                                                7/7
