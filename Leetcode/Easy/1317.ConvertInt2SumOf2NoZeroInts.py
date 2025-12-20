# revised with inspiration from other's efficient version
class Solution:
    def getNoZeroIntegers(self, n: int) -> list[int]:
        def hasZero(num):
            return '0' in str(num)
        
        a = n//2
        b = n//2 + n%2 # other half of number, accounts for odd numbers

        while hasZero(a) or hasZero(b):
            if a < n:
                a += 1
            else:
                a = 1
            if b > 0:
                b -= 1
            else:
                b = n-1
        
        return [a,b]



    
print(Solution().getNoZeroIntegers(1010))
