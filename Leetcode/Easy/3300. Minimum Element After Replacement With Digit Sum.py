# 3300. Minimum Element After Replacement With Digit Sum

class Solution:
    def minElement(self, nums: list[int]) -> int:
        minn = nums[0]
        for i in range(len(nums)):
            res = 0
            while nums[i] > 0:
                res += nums[i] % 10
                nums[i] //= 10
            nums[i] = res
            minn = min(minn, nums[i])
        
        return minn
