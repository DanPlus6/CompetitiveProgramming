#revised code (not be as efficient as other's persons)
class Solution:
    def findMissingAndRepeatedValues(self, grid: list[list[int]]) -> list[int]:
        n = len(grid)
        size = n*n
        count = [0] * (size+1)

        for i in range(n):
            for o in range(n):
                count[grid[i][o]] += 1
        
        ans = [0,0]
        for i in range(1,size+1):
            if count[i] == 2:
                ans[0] = i
            elif count[i] == 0:
                ans[1] = i

        return ans

#other person's code (more efficient, u should learn from him fr) (inspired revised code)
"""
class Solution:
    def findMissingAndRepeatedValues(self, grid: list[list[int]]) -> list[int]:
        n = len(grid)
        size = n * n

        count = [0] * (size + 1) #use array instead of dict, which is faster
        
        for i in range(n): #david, you gon have to do this someday
            for j in range(n):
                count[grid[i][j]] += 1

        a, b = -1, -1
        
        for num in range(1, size + 1):
            if count[num] == 2:
                a = num
            elif count[num] == 0:
                b = num
                
        return [a, b]
"""
        
#old code (works but less efficient)
"""
class Solution:
    def findMissingAndRepeatedValues(self, grid: list[list[int]]) -> list[int]:
        freqmap = {}

        for o in [i for i in grid]:
            for p in o:
                if p not in freqmap:
                    freqmap.update({p:1})
                else:
                    freqmap.update({p:2})
        
        ans = [k for k,v in freqmap.items() if v == 2]
        [ans.append(i) for i in range(1,(len(grid)**2)+1) if i not in freqmap.keys()]

        return ans
"""

        