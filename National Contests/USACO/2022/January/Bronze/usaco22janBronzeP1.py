# USACO 2022 January Bronze P1 - Herdle
from sys import stdin
C = 3
ans = []
for i in range(C):
    ans += list(stdin.readline().strip('\n'))
ges = []
for i in range(C):
    ges += list(stdin.readline().strip('\n'))

g,y = 0,0
for i in range(C*C):
    if ges[i] == ans[i]:
        ges[i] = 0
        ans[i] = 0
        g += 1

for i in ges:
    if i == 0: continue
    for j in range(C*C):
        if ans[j] == i:
            ans[j] = '0'
            y += 1
            break

print(g); print(y)
