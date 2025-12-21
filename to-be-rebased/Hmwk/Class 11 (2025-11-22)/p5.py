# CCC '17 S1 - Sum Game
from sys import stdin
def main() -> int:
    N = int(stdin.readline())
    SW_psa = {}
    for i,v in enumerate(list(map(int,stdin.readline().split()))):
        try:
            SW_psa[i] = v + SW_psa[i-1]
        except KeyError:
            SW_psa[i] = v
    SE_psa = {}
    for i,v in enumerate(list(map(int,stdin.readline().split()))):
        try:
            SE_psa[i] = v + SE_psa[i-1]
        except KeyError:
            SE_psa[i] = v

    if sum(SW_psa.values()) == sum(SE_psa.values()): return N

    res = 0
    for i in range(N):
        if SW_psa[i] == SE_psa[i]:
            res = max(i+1,res)

    return res

print(main())
