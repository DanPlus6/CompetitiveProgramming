# Author: DanPlus6 // David Fu
# Problem Name: COCI '17 Contest 1 #3 Lozinke
# Problem Code: coci17c1p3
# Problem URL:  https://dmoj.ca/problem/coci17c1p3
from sys import stdin
input = stdin.readline

class Node:
    def __init__(self):
        self.next = {}
        self.end = 0
    
root = Node()
def insert(s):
    head = root
    for c in s:
        head = head.next.setdefault(c,Node())
    head.end += 1

pwd = []
for _ in range(int(input())):
    pwd.append(input().strip())
    insert(pwd[-1])

res = 0
for s in pwd:
    seen = set()
    for i in range(len(s)):
        cur = root
        sub = ""
        for j in range(i,len(s)):
            if (c := s[j]) not in cur.next: break

            cur = cur.next[c]
            sub += c

            if cur.end and sub not in seen:
                seen.add(sub)
                res += cur.end
    res -= 1
print(res)
