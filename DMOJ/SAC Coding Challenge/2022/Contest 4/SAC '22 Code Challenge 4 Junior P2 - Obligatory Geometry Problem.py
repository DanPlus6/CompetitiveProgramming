# SAC '22 Code Challenge 4 Junior P2 - Obligatory Geometry Problem
from sys import stdin
N,Q = map(int,stdin.readline().split())
polygons = {}
translation = {'square':1,'circle':2,'triangle':3}
res = []
for i in range(Q):
    op,shape,elem = stdin.readline().split()
    if op == 'get':
        try:
            # print(1) if polygons[elem] == translation[shape] else print(0)
            res.append(1) if polygons[elem] == translation[shape] else res.append(0)
        except KeyError: res.append(0) # print(0)
    else: polygons[elem] = translation[shape]

for i in res: print(i)
