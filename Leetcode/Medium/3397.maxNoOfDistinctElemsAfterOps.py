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
