# 1365. How Many Numbers Are Smaller Than the Current Number

class Solution:
    def smallerNumbersThanCurrent(self, nums: list[int]) -> list[int]:
        arr = sorted([(v,i) for i,v in enumerate(nums)])
        
        first = {}
        res = [0] * len(nums)
        for i, (v, j) in enumerate(arr):
            if v not in first:
                first[v] = i
            res[j] = first[v]

        return res
