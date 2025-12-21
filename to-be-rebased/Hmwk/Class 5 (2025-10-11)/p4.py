# CCC '18 S1 - Voronoi Villages
from sys import stdin
def main() -> float:
    N = int(stdin.readline())
    V = sorted([int(stdin.readline()) for i in range(N)])

    if N == 3:
        return ((V[1]-V[0])/2 + (V[2]-V[1])/2)
    
    nSize = float('inf')
    for i in range(1,N-1):
        cur = V[i]
        nSize = min(nSize,((cur-V[i-1])/2 + (V[i+1]-cur)/2))

    return nSize

print(main())
