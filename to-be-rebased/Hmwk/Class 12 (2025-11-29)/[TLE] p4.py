# Bob's Lights Game
from sys import stdin
def main() -> int:
    N,M = map(int,stdin.readline().split())

    lights = [0 for i in range(N)]
    for i in range(M):
        l,r = map(int,stdin.readline().split())
        for i in range(l-1,r): lights[i] += 1
    
    res = 0
    for i in lights:
        if i & 1: res += 1
    return res

    
print(main())