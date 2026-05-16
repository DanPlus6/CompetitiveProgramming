# 3128. Right Triangles
class Solution:
    def numberOfRightTriangles(self, grid: list[list[int]]) -> int:
        rows = [0 for i in range(len(grid))]
        cols = [0 for i in range(len(grid[0]))]

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]:
                    rows[i] += 1
                    cols[j] += 1
        
        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]:
                    res += (rows[i]-1)*(cols[j]-1)
        
        return res


