#new code
from collections import Counter
class Solution:
    def findLeastNumOfUniqueInts(self, arr: list[int], k: int) -> int:
        countRaw = Counter(arr)
        freqs = list(countRaw.values())
        freqs.sort() #probably not needed cuz .values() automatically sorts

        indAt = 0
        for i in range(k):
            if freqs[indAt] != 0:
                freqs[indAt] -= 1
                if freqs[indAt] == 0:
                    indAt += 1
        
        
        return len(list(filter((0).__ne__, freqs)))

        

if __name__ == "__main__":
    print(Solution.findLeastNumOfUniqueInts(None,[2,1,1,3,3,3],3))

#old code (for reference)
"""
class Solution:
    def findLeastNumOfUniqueInts(self, arr: list[int], k: int) -> int:
        count = {}
        for i in arr:
            if i not in count:
                count.update({i:1})
            elif i in count:
                count.update({i:count[i]+1})

        for i in range(k):
            for key,val in list(count.items()):
                if val == min(count.values()):                
                    arr.pop(arr.index(key))
                    
                    count.pop(key)

        return len(set(arr))

if __name__ == "__main__":
    print(Solution.findLeastNumOfUniqueInts(None,[2,1,1,3,3,3],3))

#notes:
#things to consider -- count.pop(key) on line 18 might not be a good idea, nested for loop's efficiency problem
"""