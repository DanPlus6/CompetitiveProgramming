# USACO 2024 February Bronze P1 - Palindrome Game
from sys import stdin
T = int(stdin.readline())
C = [stdin.readline().strip() for i in range(T)]

for i in range(T):
    print('E') if C[i][-1] == '0' else print('B')
