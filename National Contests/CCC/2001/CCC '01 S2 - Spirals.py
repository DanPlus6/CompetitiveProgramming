# CCC '01 S2 - Spirals
from sys import stdin
input = stdin.readline
from math import sqrt, ceil

X = int(input())
Y = int(input())

slen = ceil(sqrt(Y-X)) + 2
grid = [[' ' for i in range(slen)] for j in range(slen)]

dirr = [1, 0, -1, 0]
dirc = [0, 1, 0, -1]

r = slen//2
c = slen//2-1
k = 0
i = X
while i <= Y:
    for d in range(4):
        if d == 0 or d == 2: k+=1
        j = 1
        while j <= k and i <= Y:
            grid[r][c] = f"{i} "
            r += dirr[d]
            c += dirc[d]
            j += 1
            i += 1

for row in grid: 
    print(*row)
