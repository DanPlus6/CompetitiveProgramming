# 492. Construct the Rectangle
from math import floor

class Solution:
    def constructRectangle(self, area: int) -> list[int]:
        res = []
        dif = float('inf')
        l = 0
        for w in range(1,floor(area**0.5)+1):
            if (l := area/w).is_integer():
                if (cdif := l-w) < dif:
                    res = [int(l),int(w)]
                    dif = cdif
        
        return res
