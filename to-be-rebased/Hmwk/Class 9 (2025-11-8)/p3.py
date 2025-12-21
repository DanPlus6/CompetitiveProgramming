# Mock CCC '23 Contest 1 J3 - Pairing Gifts
from sys import stdin
N,K,M = map(int,stdin.readline().split())
aarr = list(map(int,stdin.readline().split()))

# Orz bruce
# "if you don't know what you're doing, throw a hashmap at it"
barr = list(map(int,stdin.readline().split()))
Bmap = {}
ind = 0
for j in barr:
    Bmap[j] = ind; ind += 1

# lwk feels like two sum
res = 0
for i in range(N):
    b = M-aarr[i]
    if b in Bmap.keys() and abs(i-Bmap[b]) >= K: res += 1

print(res)

