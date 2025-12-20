#other person's solution:
class Solution:
    def maxDistinctElements(self, nums: list[int], k: int) -> int:
        rng = []
        sett = set()
        cnt = float('-inf')
        
        for x in nums:
            rng.append((x - k, x + k))
        
        rng.sort()  
        
        for s, e in rng:
            val=max(cnt,s)
            if val<=e and (not sett or val not in sett):
                sett.add(val)
                cnt = val + 1
        
        return len(sett)

#newer code(also broken):
"""
class Solution:
    def maxDistinctElements(self, nums: list[int], k: int) -> int:
        possibles = {}
        for i in nums:
            for x in range(i-k,i+k+1):
                if i not in possibles:
                    possibles.update({i:[x]})
                elif i in possibles:
                    tmp = possibles[i]; tmp.append(x)
                    possibles.update({i:tmp})
        
        semifinal = []
        for k,v in possibles.items():
            if k not in semifinal:
                semifinal.append(k)
                continue
            else:
                for i in v:
                    if i not in semifinal:
                        semifinal.append(i)
                        break
                continue

        return(len(semifinal))

print(Solution.maxDistinctElements(None,[1,2,2,3,3,4],2))   
"""

#old code (for reference):
"""
from collections import Counter
class Solution:
    def maxDistinctElements(self, nums: list[int], k: int) -> int:
        countRaw = Counter(nums)
        purge = {}
        noahsArc = {}
        for i in nums:
            if countRaw[i] > 1 and i not in purge:
                purge.update({i:[nums.index(i)]})
                noahsArc.update({i:1})
            elif countRaw[i] > 1 and i in purge:
                if noahsArc[i] != countRaw[i] - 1:
                    tempL = purge[i]; tempL.append(nums.index(i))
                    purge.update({i:tempL})
                    noahsArc.update({i:noahsArc[i]+1})
        
        sorted = nums; sorted.sort()
        vacantNew = {}
        for i in sorted:
            for x in range(i-k,i+k):
                if x not in nums:
                    if x not in vacantNew:
                        vacantNew.update({i:[x]})
                    elif x in vacantNew:
                        tempL = vacantNew[i]; tempL.append(x)
                        vacantNew.update({i:tempL})
        
        for i in range(len(nums)):
            if nums[i] in purge:
                nums[i] = vacantNew[nums[i]][0]
                tempL = vacantNew[i]; tempL.pop(0)
                vacantNew.update({i:tempL})
        
        return len(set(nums))
                
        
print(Solution.maxDistinctElements(None,[1,2,2,3,3,4],2))    
"""        
        

#current plan:
    #find all duplicate integers✅
    #add integers within range -k,+k to duplicates, so that we can turn duplicates into new unique integers
    #if there are no duplicates, it is already the max number of unique integers