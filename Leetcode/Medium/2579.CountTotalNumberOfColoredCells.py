#new code (works but more efficient)
class Solution:
    def coloredCells(self, n: int) -> int:
        return 1 + 2*n**2 - 2*n
        
#other person's code (work, more eff., inspired the above ^)
"""
class Solution:
    def coloredCells(self, n: int) -> int:
        return 1 + 4 * n * (n-1) // 2
"""
        
#old code (works but inefficient)
"""
class Solution:
    def coloredCells(self, n: int) -> int:
        colored = 1
        increment = 4
        
        while n - 1:
            colored += increment
            increment += 4
            n -= 1
        return colored     
"""
