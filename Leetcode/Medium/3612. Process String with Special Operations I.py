# 3612. Process String with Special Operations I

class Solution:
    def processStr(self, s: str) -> str:
        res = []
        for c in s:
            if c == '*': 
                try: res.pop()
                except IndexError: continue
            elif c == '#': 
                for i in range(len(res)):
                    res.append(res[i])
            elif c == '%': res = res[::-1]
            else: res.append(c)
        
        return ''.join(res)
