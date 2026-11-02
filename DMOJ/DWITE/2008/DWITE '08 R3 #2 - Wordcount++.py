# DWITE '08 R3 #2 - Wordcount++
from sys import stdin
input = stdin.readline

for _ in range(5):
    ln = input().strip() + '.'
    ct = tmp = 0
    for c in ln:
        if c.isalpha():
            tmp += 1
        else:
            ct += 1 if tmp > 3 else 0
            tmp = 0
    print(ct)
