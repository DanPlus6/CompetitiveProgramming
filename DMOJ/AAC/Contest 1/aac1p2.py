# An Animal Contest 1 P2 - Alpaca Racing
from sys import exit
from math import floor
N,D,USES,X = map(int, input().split())
speeds = [int(input()) for _ in range(N)]

P = int(input())

change = (100-X)/100
for i in range(N):
    while speeds[i] >= P:
        if USES >= 1:
            speeds[i] = floor(speeds[i] * change)
            USES -= 1
        else:
            print("NO")
            exit(0)
print("YES")
