# CCC '12 J3 - Icon Scaling
from sys import stdin
input = stdin.readline

multiplier = int(input())
for i in range(multiplier): print('*'*multiplier + 'x'*multiplier + '*'*multiplier)
for i in range(multiplier): print(' '*multiplier + 'x' * multiplier*2)
for i in range(multiplier): print('*'*multiplier + ' '*multiplier + '*' * multiplier)
