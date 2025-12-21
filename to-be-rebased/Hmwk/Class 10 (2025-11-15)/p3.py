# Mock CCC '22 Contest 2 J3 - Figure Skating Fun
from sys import stdin

def main():
    N = int(stdin.readline())
    S = list(map(int, stdin.readline().split()))

    l,r = 0,sum(S)
    for i in range(N):
        cur = S[i]
        l += cur; r -= cur
        if l == r:
            return i+1

    return 'Andrew is sad.'


print(main())
