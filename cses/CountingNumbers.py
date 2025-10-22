def nonconseq( n ):
    prev = n % 10
    n //= 10
    while n > 0:
        curr = n % 10
        n //= 10
        if curr == prev: return False
        prev = curr
    return True
################################################################
def count_nonconseq( n ):
    count = 0
    while n >= 0:
        if( nonconseq( n )): count += 1
        n -= 1
    return count
################################################################
def number_of_digits( n ):
    count = 0
    while True:
        n //= 10
        count += 1
        if n == 0: break
    return count
################################################################
def number_to_list( n ):
    ls = []
    while True:
        ls.append( n % 10 )
        n //= 10
        if n == 0: break
    return ls
################################################################
MAXDIGITS = 19
POW9 = [1] * MAXDIGITS
PREF = [1] * MAXDIGITS
################################################################
def precompute():
    for j in range( 1, MAXDIGITS ):
        POW9[j] = POW9[j - 1] * 9
        PREF[j] = PREF[j - 1] + POW9[j]
################################################################
def f( n ):
    dg = number_to_list( n )
    k = len( dg ) - 1
    count = PREF[k] + (dg[k] - 1) * POW9[k]
    while k > 0:
        k -= 1
        if dg[k] == 0:
            if k > 0 and dg[k - 1] == 0: return count
            continue
        count += (dg[k] - int( dg[k] > dg[k + 1])) * POW9[k]
        if dg[k] == dg[k + 1]: return count
    return count + 1
################################################################
def main( a, b ):
    precompute()
    if False: pass
    else:
        if a > 0:
            print( f( b ) - f( a - 1 ))
        else:
            print( f( b ))
################################################################
if __name__ == '__main__':
    a, b = map( int, input().split() )
    main( a, b )
