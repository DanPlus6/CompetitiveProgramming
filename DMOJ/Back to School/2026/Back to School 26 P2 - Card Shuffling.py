# Author: DanPlus6 // David Fu
# Problem Name: Back to School '26 P2 - Card Shuffling
# Problem URL:  https://dmoj.ca/problem/bts26p2
# Problem Code: bts26p2
from sys import stdin,exit
input = stdin.readline

N = int(input())
if N <= 1:
    print(0)
    exit()

a = list(map(int,input().split()))

res = 0
for i in range(N-1):
    if a[i] > a[i+1]: res +=1

print(res.bit_length())

