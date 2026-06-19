# DMOPC '20 Contest 1 P2 - Victor's Moral Dilemma
from sys import stdin
input = stdin.readline

N,D = map(int, input().split())
A = list(map(int, input().split()))

for _ in range(D):
    ni = int(input())
    left = A[:ni]
    right = A[ni:]
    lsum = sum(left)
    rsum = sum(right)

    if lsum > rsum:
        print(lsum)
        A = right
    else:
        print(rsum)
        A = left
