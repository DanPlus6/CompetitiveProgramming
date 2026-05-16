# 3127. Make a Square with the Same Color
class Solution:
    def canMakeSquare(self, grid: list[list[str]]) -> bool:
        global b
        global w
        b,w = 0,0
        def getRange(x1,x2,y1,y2):
            global b
            global w
            b = 0
            w = 0
            for i in range(x1,x2+1):
                for j in range(y1,y2+1):
                    print((i,j),grid[i][j])
                    if grid[i][j] == "B": b += 1
                    else: w += 1
        
        getRange(0,1,0,1)
        if (b != 2 and w != 2): return True

        getRange(1,2,0,1)
        if (b != 2 and w != 2): return True

        getRange(0,1,1,2)
        if (b != 2 and w != 2): return True

        getRange(1,2,1,2)
        if (b != 2 and w != 2): return True
        
        return False

