# CCC '21 S1 - Crazy Fencing
from sys import stdin
N = int(stdin.readline())
H = list(map(int, stdin.readline().split()))
W = list(map(int, stdin.readline().split()))

res = 0
lh = H[0]
for i in range(N):
    h = H[i+1]
    w = W[i]
    res += (lh+h) * w / 2
    lh = h

print(res)
