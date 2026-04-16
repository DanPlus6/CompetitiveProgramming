# DWITE '07 R2 #3 - Floor Plan
from sys import stdin
from collections import deque
R = int(stdin.readline())
C = int(stdin.readline())

_r,_c = R-1,C-1

floor = []
roomCoords = {1:[],2:[],3:[],4:[],5:[]}
for i in range(R):
    floor.append(row := list(stdin.readline()))
    for j in range(C):
        if row[j] in ['1','2','3','4','5']:
            roomCoords[int(row[j])] = [i,j]    


# dirR = [-1, 1, 0, 0] # up, down, left, right
# dirC = [0, 0, -1, 1]
def bfs(cur):
    # cur = startingPlace
    v = [[0 for i in range(C)] for i in range(R)] # [cur]
    q = deque()
    
    res = 1
    r,c = cur[0],cur[1] # cur[0],cur[1]
    # setup
    if r != 0 and floor[up := r-1][c] == '.': # up
        res += 1
        q.append([up,c])
        v[up][c] = 1
    if r != _r and floor[down := r+1][c] == '.': # down
        res += 1
        q.append([down,c])
        v[down][c] = 1
    if c != 0 and floor[r][left := c-1] == '.': # left
        res += 1
        q.append([r,left])
        v[r][left] = 1
    if c != _c and floor[r][right := c+1] == '.': # right
        res += 1
        q.append([r,right])
        v[r][right] = 1

    if not q: return 1
    
    # loop
    while q:
        cur = q.popleft()
        r,c = cur[0],cur[1]

        if r != 0 and not v[up := r-1][c] and floor[up][c] == '.': # up
            res += 1
            q.append([up,c])
            v[up][c] = 1
        if r != _r and not v[down := r+1][c] and floor[down][c] == '.': # down
            res += 1
            q.append([down,c])
            v[down][c] = 1
        if c != 0 and not v[r][left := c-1] and floor[r][left] == '.': # left
            res += 1
            q.append([r,left])
            v[r][left] = 1
        if c != _c and not v[r][right := c+1] and floor[r][right] == '.': # right
            res += 1
            q.append([r,right])
            v[r][right] = 1
    
    return res


for i in range(1,6):
    print(bfs(roomCoords[i]))



