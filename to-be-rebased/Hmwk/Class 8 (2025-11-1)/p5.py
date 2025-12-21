# Appleby Contest '19 P4 - Rectangles
# dawg this was so easy, I was just procrastinating so hard,
#  not wanting to figure out what's an axis-aligned rectangle
from sys import stdin,stdout
N = int(stdin.readline())
pointss = set()
points = []

for i in range(N):
    point = tuple(map(int,stdin.readline().split()))
    pointss.add(point)
    points.append(point)

ans = 0
for i in range(N):
    xi,yi = points[i]
    for j in range(i+1,N):
        xj,yj = points[j]
        if (xi,yj) in pointss and (xj,yi) in pointss:
            ans = max(ans, (abs(xi-xj)*abs(yi-yj)))

stdout.write(str(ans))
