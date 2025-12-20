class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        from math import log2

        # (condition to determine if impossible)

        ops = 0
        while num1 != 0:
            exp = int(log2((num1-num2)))
            num1 -= 2**exp - num2
            ops+=1
            print(num1)
        
        return ops

print("Took",Solution().makeTheIntegerZero(3,-2),"operations")
