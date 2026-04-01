# Problem J2: Olympic Scores
from sys import stdin
input = stdin.readline
from collections import defaultdict

scores = [int(input()) for _ in range(5)]

D = int(input())

print(D*(sum(scores)-max(scores)-min(scores)))


