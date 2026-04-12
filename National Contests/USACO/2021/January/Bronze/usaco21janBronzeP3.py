# USACO 2021 January Bronze P3 - Just Stalling
N = int(input())
A = sorted(list(map(int, input().split())))
B = sorted(list(map(int, input().split())))


throwAHashmapAtIt = []
for i in range(N-1,-1,-1):
    curCow = A[i]
    pos = 0
    for j in B:
        if j >= curCow:
            pos += 1
    throwAHashmapAtIt.append(pos-len(throwAHashmapAtIt))

prod = 1
for i in throwAHashmapAtIt:
    prod *= i
print(prod)

