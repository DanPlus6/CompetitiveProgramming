from collections import defaultdict, deque
from sys import stdin
input = stdin.readline

def main():
    r = int(input())
    c = int(input())

    d = defaultdict(list) # this makes it so that it automatically creates an empty array so we dont have to check if one already exists for current x value
    for i in range(r):
        ln = input().split()
        for j in range(c):
            d[int(ln[j])].append((i,j))

    #print(d)

    possible = deque()
    possible.append((r - 1, c - 1))
    visited = [[False] * c for i in range(r)]
    
    while possible:
        a, b = possible.popleft()
        x = (a + 1) * (b + 1)

        if visited[a][b]: continue
        
        for i in d[x]:
            if i == (0, 0):
                return "yes"
            
            possible.append(i)

        visited[a][b] = True
                        
    return "no"
        
print(main())
