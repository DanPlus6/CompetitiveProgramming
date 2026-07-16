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

