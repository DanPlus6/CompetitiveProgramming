# CCC '16 J1 - Tournament Selection
from sys import stdin
wins = 0
for i in range(6):
    if stdin.readline().strip('\n') == 'W':
        wins += 1
if wins == 1 or wins == 2:
    print(3)
elif wins == 3 or wins == 4:
    print(2)
elif wins == 5 or wins == 6:
    print(1)
else:
    print(-1)
