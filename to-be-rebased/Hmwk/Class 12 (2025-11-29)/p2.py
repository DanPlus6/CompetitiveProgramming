# SAC '22 Code Challenge 3 P1 - Hair Hazards
from sys import stdin
h = int(stdin.readline())
S = int(stdin.readline())
for i in range(int(stdin.readline())):
    h -= S
    print(h)
