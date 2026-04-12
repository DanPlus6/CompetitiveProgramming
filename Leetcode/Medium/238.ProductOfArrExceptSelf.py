

# TLE 😭
"""
class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        def prod(nums = list[int]) -> int:
            p = nums[0]
            for i in range(1,len(nums)):
                p *= nums[i]
            return p

        prefix,suffix = [],[]
        returning = []
        for i in range(len(nums)):
            pre,suf = nums[:i],nums[i+1:]
            prefix.append(prod(nums[:i])) if pre != [] else prefix.append(1)
            suffix.append(prod(nums[i+1:])) if suf != [] else suffix.append(1)
            returning.append(prefix[i]*suffix[i])
        
        return returning
    
"""
