# The Cosmic Era P3 - Battle Positions
from sys import stdin
I = int(stdin.readline())
N = int(stdin.readline())
J = int(stdin.readline())

stations = {}
for i in range(I):
    stations[i+1] = 0

for i in range(J):
    l,r,k = map(int,stdin.readline().split())
    for j in range(l,r+1): stations[j] += k

res = 0
for i in stations.values():
    if i < N: res += 1
print(res)

# how can we do this in O(n)?

