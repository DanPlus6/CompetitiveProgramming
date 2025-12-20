# more efficient solution
class Solution:
    def sortMatrix(self, grid: list[list[int]]) -> list[list[int]]:
        n = len(grid)
        start = n - 1
        while start >= 0:
            cur = []
            row = start
            col = 0
            while row < n:
                cur.append(grid[row][col])
                row += 1
                col += 1
            cur.sort(reverse=True)
            row = start
            col = 0
            for num in cur:
                grid[row][col] = num
                row += 1
                col += 1
            start -= 1
        start = 1
        while start < n:
            cur = []
            col = start
            row = 0
            while col < n:
                cur.append(grid[row][col])
                row += 1
                col += 1
            cur.sort()
            col = start
            row = 0
            for num in cur:
                grid[row][col] = num
                row += 1
                col += 1
            start += 1
        return grid


# my solution
"""
class Solution:
    def sortMatrix(self, grid: list[list[int]]) -> list[list[int]]:
        n = len(grid)
        t = 2*n-3
        lower_diagonals = [[] for i in range(t-t//2)]

        for i in range(1,n):
            for j in range(i+1):
                lower_diagonals[i-1].append(grid[n-1-i+j][j])
        
        upper_diagonals = [[] for i in range(t//2)]
        for i in range(1,n-1):
            for j in range(i+1):
                upper_diagonals[i-1].append(grid[j][n-1-i+j])
        
        # return lower_diagonals+upper_diagonals
    
        for i in range(len(lower_diagonals)):
            cur = lower_diagonals[i]
            lower_diagonals[i] = sorted(cur,reverse=True)
        
        for i in range(len(upper_diagonals)):
            cur = upper_diagonals[i]
            upper_diagonals[i] = sorted(cur)
        
        for i in range(1,n):
            for j in range(i+1):
                grid[n-1-i+j][j] = lower_diagonals[i-1][j]
       
        for i in range(1,n-1):
            for j in range(i+1):
                grid[j][n-1-i+j] = upper_diagonals[i-1][j]

        return grid
"""

print(Solution.sortMatrix(None,[[1,7,3],[9,8,2],[4,5,6]]))

