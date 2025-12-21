# Posters
from sys import stdin
from collections import deque
N = int(stdin.readline())
S = stdin.readline().strip()

fbunique = set()
psa = []
for i in range(N):
    fbunique.add(S[i])
    psa.append(fbunique.copy())

bfunique = set()
ssa = deque()
for i in range(N-1,-1,-1):
    bfunique.add(S[i])
    ssa.appendleft(bfunique.copy())

res = 0
for i in range(N):
    left = psa[i]
    right = ssa[i]

    res = max(res,len(left & right))

print(res)

