# Posters
from sys import stdin
X,Y,N = map(int,stdin.readline().split())
grid = [[0 for i in range(X)] for i in range(Y)]

for i in range(N):
    x1,y1,x2,y2 = map(int,stdin.readline().split())
    for j in range(y1-1,y2):
        for k in range(x1-1,x2):
            grid[j][k] = 1

print(sum([sum(i) for i in grid]))
