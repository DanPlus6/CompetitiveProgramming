# Music Notes
from sys import stdin
N,Q = map(int,stdin.readline().split())
A = [int(stdin.readline()) for i in range(N)]
T = [int(stdin.readline()) for i in range(Q)]
psa = [A[0]]
for i in range(1,N):
    psa.append(psa[i-1]+A[i])

for i in T:
    for j in range(N):
        if i < psa[j]:
            print(j+1)
            break


