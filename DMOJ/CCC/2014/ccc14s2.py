# CCC '14 S2 - Assigning Partners
def main() -> bool:
    from sys import stdin
    N = int(stdin.readline())
    A = stdin.readline().strip('\n').split()
    B = stdin.readline().strip('\n').split()

    if N%2 != 0:
        return False
        
    pairing = {}
    for i in range(N):
        a = A[i]
        b = B[i]
        if a == b:
            return False        
        try:
            if pairing[b] != a:
                return False           
        except KeyError:
            pairing.update({a:b})
            pairing.update({b:a})

    return True
print('good') if main() else print('bad')
