# my version (buggy ahh)
"""
class Solution:
    def clearStars(self, s: str) -> str:
        if '*' in s:
            s = list(s)
            lexi = list('abcdefghijklmnopqrstuvwxyz')
            killList = []
            for i in range(len(s)-1,-1,-1):
                if s[i] == '*':
                    killList.append(i)
                    tmpV = []
                    tmpI = []
                    for j in range(i-1,-1,-1):
                        if s[j] != '*':
                            tmpV.append(lexi.index(s[j]))
                            tmpI.append(j)
                    if tmpV:
                        killList.append(tmpI[tmpV.index(min(tmpV))])
            for i in set(killList):
                s.pop(i)
                    
        return ''.join(s)

print(Solution.clearStars(None,"dk**"))
"""

# new version after looking at other submissions:

