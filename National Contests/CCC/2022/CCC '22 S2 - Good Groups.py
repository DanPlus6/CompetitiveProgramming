# CCC '22 S2 - Good Groups
from sys import stdin
X = int(stdin.readline())
SAME = [list(stdin.readline().split()) for i in range(X)]
Y = int(stdin.readline())
DIF = [list(stdin.readline().split()) for i in range(Y)]
G = int(stdin.readline())
res = 0
groups = {}
for i in range(G):
    group = list(stdin.readline().split())
    groups[group[0]] = i
    groups[group[1]] = i
    groups[group[2]] = i

for rule in SAME:
    if groups[rule[0]] != groups[rule[1]]:
        res += 1
for rule in DIF:
    if groups[rule[0]] == groups[rule[1]]:
        res += 1
print(res)


