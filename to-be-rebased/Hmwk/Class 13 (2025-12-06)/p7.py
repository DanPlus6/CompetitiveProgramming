# SAC '22 Code Challenge 3 P3 - Bob Sort
from sys import stdin
from math import log10
N = int(stdin.readline())
arr = list(map(int,stdin.readline().split()))


R = int(log10(max(arr))+1)
for r in range(1,R+1):
    # WHAT THE FRICK WHY ISNT PYTHON TLE
    # arr.sort(key=lambda x: int(str(x)[-r:]))
    arr.sort(key=lambda x: x % 10**r)

    if r != R:
        print(' '.join([str(i) for i in arr]))
    else:
        print(' '.join([str(i) for i in arr]))

