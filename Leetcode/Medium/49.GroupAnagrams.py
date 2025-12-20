# someone else's faster solution
from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        result = defaultdict(list) # much more convenient that standard dicts (dont reinvent the wheel)

        for word in strs:        
            key = tuple(sorted(word)) # very smart
            result[key].append(word) # dont require pre-init or creation of keys
        return list(result.values())

# my attempt at O(n*m) O(m)
"""
class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        if len(strs) == 1:
            return [strs]
        
        def counter(strr: str) -> str:
            count = {}
            for i in strr:
                if i not in count:
                    count[i] = 1
                else:
                    count[i] += 1

            alphaCount = list('abcdefghijklmnopqrstuvwxyz')
            for k,v in count.items():
                alphaCount[ord(k)-97] = str(v)
            return (alphaCount[0],alphaCount[1],alphaCount[2],alphaCount[3],alphaCount[4],alphaCount[5],alphaCount[6],alphaCount[7],alphaCount[8],alphaCount[9],alphaCount[10],alphaCount[11],alphaCount[12],alphaCount[13],alphaCount[14],alphaCount[15],alphaCount[16],alphaCount[17],alphaCount[18],alphaCount[19],alphaCount[20],alphaCount[21],alphaCount[22],alphaCount[23],alphaCount[24],alphaCount[25])
        

        groups = {}
        for i in range(len(strs)):
            string = strs[i]
            cur = counter(string)
            print(string,cur)

            if cur not in groups:
                groups[cur] = [string]
            else:
                groups[cur].append(string)
        
        return [i for i in groups.values()]

"""