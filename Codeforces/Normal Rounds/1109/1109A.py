# Author: DanPlus6 // David Fu
# Problem Name: A. Iskander and Drawings
# Problem URL:  https://codeforces.com/contest/2244/problem/A
from sys import stdin
input = stdin.readline

T = int(input())
for _ in range(T):
    n = int(input())
    
    mxl = tmp = 0
    for c in input().strip():
        if c == '#':
            tmp += 1
        else:
            mxl = max(tmp,mxl)
            tmp = 0
    mxl = max(tmp,mxl)

    print((mxl+1)//2)
