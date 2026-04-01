# USACO 2023 January Bronze P3 - Moo Operations
from sys import stdin
from collections import deque
Q = int(stdin.readline())

def moo(string: str) -> int:
    if string == 'MOO':
        return 0
    
    n = len(string)-3
    res = 999
    if 'OOO' in string: res = min(res,n+1)
    if 'OOM' in string: res = min(res,n+2)
    if 'MOO' in string: res = min(res,n)
    if 'MOM' in string: res = min(res,n+1)
    return res if res != 999 else -1

for i in range(Q):
    print(moo(stdin.readline().strip()))
