# attempt at O(n+m);O(1)
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        t = list(t)
        
        for i in s:
            try:
                t.remove(i)
            except ValueError:
                return False
        
        return t == []
