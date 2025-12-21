# BPC 1 S1 - Homework Questions
from sys import stdin
from collections import Counter
N = int(stdin.readline())
ct = Counter(list(map(int, stdin.readline().split())))

# Orz bruce
print(' '.join([str(i) for i in sorted(set([k//2 for k,v in ct.items() if (v % 2) and not (k%2)]))]))
