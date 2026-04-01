# CCC '17 J1 - Quadrant Selection
from sys import stdin
X = int(stdin.readline())
Y = int(stdin.readline())

if X > 0 and Y > 0:
    print(1)
elif X < 0 and Y > 0:
    print(2)
elif X < 0 and Y < 0:
    print(3)
elif X > 0 and Y < 0:
    print(4)
