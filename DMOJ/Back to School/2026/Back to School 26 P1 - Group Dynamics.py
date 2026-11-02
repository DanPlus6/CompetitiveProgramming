# Author: DanPlus6 // David Fu
# Problem Name: Back to School '26 P1 - Group Dynamics
# Problem URL:  https://dmoj.ca/problem/bts26p1
# Problem Code: bts26p1
from sys import stdin,exit
input = stdin.readline

N = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

if sum(a) != sum(b):
    print("NO")
    exit()

        
ifA = sum(i&1 for i in a)
ifB = sum(i&1 for i in b)

if ifA != ifB:
    print("NO")
    exit()
elif not ifA:
    print("YES") if a==b else print('NO')
    exit()
print("YES")
