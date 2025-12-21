# Arcadia Computing Contest 1 P3 - ScanTron
from sys import stdin
N = int(stdin.readline())
ans = stdin.readline().strip()
will = stdin.readline().strip()

total = 0
for i in range(N-1):
    if ans[i+1] == will[i]: total += 1

# O(1) memory is crazy
res = 0
a,b = 0,0
for i in range(N-1):
    res = max((total-b + a),res)
    if ans[i] == will[i]: a += 1
    if ans[i+1] == will[i]: b += 1
    

print(res)
