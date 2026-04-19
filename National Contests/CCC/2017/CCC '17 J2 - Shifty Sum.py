# CCC '17 J2 - Shifty Sum
from sys import stdin
N = int(stdin.readline())
K = int(stdin.readline())

n = N
for i in range(K):
    n += N*10**(i+1)

print(n)
