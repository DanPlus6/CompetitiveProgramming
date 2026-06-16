# 3612. Process String with Special Operations I

class Solution:
    def processStr(self, s: str) -> str:
        res = ""
        for c in s:
            if c == '*' and len(res) >= 1: res = res[:-1]
            elif c == '#': res += res
            elif c == '%': res = res[::-1]
            elif c.isalpha(): res += c
        
        return res
