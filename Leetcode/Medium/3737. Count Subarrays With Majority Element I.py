# 3737. Count Subarrays With Majority Element I
from collections import Counter

class Solution:
    def countMajoritySubarrays(self, nums: list[int], target: int) -> int:
        res = 0
        for i in range(len(nums)):
            for j in range(i, len(nums)):
                subarr = nums[i:j+1]

                if 2*Counter(subarr)[target] > len(subarr):
                    res += 1
        return res
