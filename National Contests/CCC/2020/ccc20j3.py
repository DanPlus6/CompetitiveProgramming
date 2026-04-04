# CCC '20 J3 - Art
N = int(input())
x,y = [],[]
for i in range(N):
    xi,yi = map(int, input().split(','))
    x.append(xi); y.append(yi)

print(f"{min(x)-1},{min(y)-1}")
print(f"{max(x)+1},{max(y)+1}")
