# CCC '26 J2 - Olympic Scores
from sys import stdin
input = stdin.readline

scores = [int(input()) for _ in range(5)]

D = int(input())

print(D*(sum(scores)-max(scores)-min(scores)))


