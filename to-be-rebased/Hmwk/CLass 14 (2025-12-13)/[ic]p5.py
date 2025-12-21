# USACO 2022 February Bronze P2 - Photoshoot 2
from sys import stdin

def main() -> int:
    N = int(stdin.readline())
    a,lM = list(map(int,stdin.readline().split())),list(map(int,stdin.readline().split()))
    M = {}
    for i in range(N):
        M[lM[i]] = i

    if a == lM: return 0

    res = 0
    while a != lM:
        for i in range(N-1,-1,-1):
            cur = a[i]
            if cur != lM[i]:
                if M[cur] == 0:
                    a.pop(i)
                    a = [cur] + a
                    res += 1
                    break
                else:
                    a.pop(i)
                    a.insert(M[cur],cur)
                    res += 1
                    break

    return res

print(main())
