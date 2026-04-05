# USACO 2022 February Bronze P1 - Sleeping in Class
from sys import stdin
def main():
    N = int(stdin.readline())
    M = list(map(int,stdin.readline().split()))
    Sum = sum(M)

    if Sum == 0: return 0
    if N&1 and len(set(M)) == 1: return N-1

    psa = set()
    last = 0
    for j in M:
        psa.add(j+last)
        last += j

    factors = []
    for j in range(1,int(Sum**0.5)+1):
        if Sum % j == 0:
            factors.append(j)
            if j*j != Sum: factors.append(Sum//j)
    factors.sort()
    
    for j in factors:
        for k in range(j,Sum+1,j):
            if k not in psa:
                break
        else:
            return N-Sum//j
    else:
        return N-1

for i in range(int(stdin.readline())):
    print(main())

