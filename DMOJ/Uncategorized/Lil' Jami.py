# Lil' Jami
from sys import stdin
input = stdin.readline

N,K = map(int, input().split())

arr = [0]*N
for _ in range(K):
    arr[int(input())] += 1

psa = [arr[0]]
for i in range(1, N):
    psa.append(arr[i] + psa[i-1])
del arr

for i in range(int(input())):
    a,b = map(int, input().split())
    left = psa[a-1] if a > 0 else 0
    print(psa[b] - left)
