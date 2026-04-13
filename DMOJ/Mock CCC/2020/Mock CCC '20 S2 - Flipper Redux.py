# Mock CCC '20 S2 - Flipper Redux

# teacher's code
N = int(input())
arr = [list(map(int, input().split())) for i in range(N)]

ans = []
# rows
for i in range(N):
    if arr[i][0]:
        ans.append(f'R {i+1}')
        for j in range(N):
            arr[i][j] = 1 - arr[i][j]

# cols
for j in range(N):
    if arr[0][j]:
        ans.append(f'C {j+1}')
        for i in range(N):
            arr[i][j] = 1 - arr[i][j]

if sum([sum(arr[i]) for i in range(N)]):
    print(-1)
else:
    print(len(ans))
    for i in ans:
        print(i)


# broken -- my code ofc
"""
N = int(input())
puzzle = [list(map(int, input().split())) for i in range(N)]

ans = []
# rows
for r in range(N):
    if puzzle[r][0]:
        ans.append(f'R {r+1}')
        for i in range(N):
            puzzle[i][r] = 1 - puzzle[i][r]

# cols
for c in range(N):
    if puzzle[0][c]:
        ans.append(f'C {c+1}')
        for i in range(N):
            puzzle[i][c] = 1 - puzzle[i][c]

if sum([sum(i) for i in puzzle]):
    print(-1)
else:
    print(len(ans))
    for i in ans:
        print(i)
"""
