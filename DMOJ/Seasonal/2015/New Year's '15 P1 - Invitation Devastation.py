# New Year's '15 P1 - Invitation Devastation
from sys import stdin
input = stdin.readline

BASE = input()
for _ in range(int(input())):
    print(BASE.replace('>', input().strip()))
