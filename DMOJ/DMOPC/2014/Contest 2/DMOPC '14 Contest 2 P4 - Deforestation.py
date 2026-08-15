# DMOPC '14 Contest 2 P4 - Deforestation
from sys import stdin
N = int(stdin.readline())
psm = {}
for i in range(N):
    m = int(stdin.readline())
    try:
        psm[i] = m + psm[i-1]
    except KeyError:
        psm[i] = m

for i in range(int(stdin.readline())):
    a,b = map(int,stdin.readline().split())
    try:
        print(psm[b]-psm[a-1])
    except KeyError:
        print(psm[b])
        