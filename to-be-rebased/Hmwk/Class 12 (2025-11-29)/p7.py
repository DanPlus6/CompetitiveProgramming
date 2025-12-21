# New Year's '17 P1 - Mr. N and Presents
from sys import stdin
from collections import deque
Q = int(stdin.readline())

# Orz bruce, taught me fake operations
fake = deque()
real = {} # question is easy cuz all numbers distinct
for i in range(Q):
    op,x = stdin.readline().split()
    if op == 'F':
        fake.appendleft((x,i))
        real[x] = i
    elif op == 'E':
        fake.append((x,i))
        real[x] = i
    else:
        real[x] = -1

for i,j in fake:
    if j == real[i]: print(i)
