class Solution:
    def sumZero(self, n: int) -> list[int]:
        l = []
        if n == 1:
            return [0]
        if n & 1 != 0:
            l.append(0)
        
        for i in range(1,n//2+1):
            l.insert(0,i*-1)
            l.append(i)

        return l,len(l)

print(Solution().sumZero(21))
