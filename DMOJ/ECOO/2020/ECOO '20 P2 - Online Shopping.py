# Author: DanPlus6 // David Fu
# Problem Name: ECOO '20 P2 - Online Shopping
# Problem URL:  https://dmoj.ca/problem/ecoo20p2
# Problem Code: ecoo20p2
from collections import defaultdict
from sys import stdin
input = stdin.readline

for _ in range(int(input())):
    stores = defaultdict(list)

    for i in range(int(input())):
        for j in range(int(input())):
            stores[(inv:=input().strip().split())[0]].append((int(inv[1]),int(inv[2])))

    res = 0
    for k in range(int(input())):
        req,qt = input().strip().split()
        if not (qt:=int(qt)): continue

        stores[req].sort()
        for s in stores[req]:
            if qt >= s[1]:
                qt -= s[1]
                res += s[0]*s[1]
            elif qt < s[1]:
                res += s[0]*qt
                break
    print(res)
