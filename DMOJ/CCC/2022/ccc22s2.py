# CCC '22 S2 - Good Groups
# efficient O(n) solution | Orz Bruce
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



# Naieve solution
"""
X = int(stdin.readline())
same = [list(stdin.readline().split()) for i in range(X)]
Y = int(stdin.readline())
dif = [list(stdin.readline().split()) for i in range(Y)]
G = int(stdin.readline())
PLC = [list(stdin.readline().split()) for i in range(G)]

res = 0              
for group in PLC:
    rmS = []
    for smR in same:
        if (smR[0] in group and smR[1] not in group) or (smR[1] in group and smR[0] not in group):
            res += 1
            rmS.append(smR)
    rmD = []
    for difR in dif:
        if difR[0] in group and difR[1] in group:
            res += 1
            rmD.append(difR)

    for i in rmS: same.remove(i)
    for i in rmD: dif.remove(i)

print(res)
"""
