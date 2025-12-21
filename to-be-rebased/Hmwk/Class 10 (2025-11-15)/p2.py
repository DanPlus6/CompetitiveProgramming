# Mock CCC '22 Contest 2 J2 - Snowboarding Championship
from sys import stdin
N,A,B = map(int,stdin.readline().split())
O = [list(map(int,stdin.readline().split())) for i in range(N)]

a,t = 0,0
for i in range(N):
    cur = O[i]
    a += 1 if cur[0] < A else 2
    t += 1 if cur[1] < B else 2

if a < t:
    print('Andrew wins!')
elif t < a:
    print('Tommy wins!')
else:
    print('Tie!')
