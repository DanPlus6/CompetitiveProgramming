# 13. Roman to Integer
class Solution:
    def romanToInt(self, s: str) -> int:
        romans = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }

        res = 0
        last = 0
        for i in s:
            res += romans[i]
            if last and last < romans[i]:
                res -= last*2
            last = romans[i]
        
        return res
