# USACO 2020 January Bronze P1 - Word Processor
from sys import stdin
N,K = map(int,stdin.readline().split())
W = list(stdin.readline().split())

k = 0
hold = ""
for i in W:
    length = len(i)
    if (length + k) <= K:
        k += length
        hold += " "+i if hold else i
    else:
        print(hold)
        k,hold = length,i

print(hold)
