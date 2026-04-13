# SAC '22 Code Challenge 3 Junior P2 - Normal Lines
from sys import stdin
x1,y1 = map(int,stdin.readline().split())
x2,y2 = map(int,stdin.readline().split())

if x1 == x2: print('y-axis')
elif y1 == y2: print('x-axis')
else: print('neither')
