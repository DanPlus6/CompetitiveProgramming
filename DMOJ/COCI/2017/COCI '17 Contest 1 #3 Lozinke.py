# Author: DanPlus6 // David Fu
# Problem Name: COCI '17 Contest 1 #3 Lozinke
# Problem Code: coci17c1p3
# Problem URL:  https://dmoj.ca/problem/coci17c1p3
from collections import defaultdict
from sys import stdin
input = stdin.readline

db = defaultdict(int)

for _ in range(int(input())):
    db[input().strip()] += 1

res = 0
for ki,vi in db.items():
    if vi>1: res += vi*(vi-1)
    for kj,vj in db.items():
        if ki == kj: continue
        elif ki in kj: res += vi*vj
print(res)
