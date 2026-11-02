# Author: DanPlus6 // David Fu
# Problem Name: 628. Maximum Product of Three Numbers
# Problem Code: maximum-product-of-three-numbers
# Problem URL: https://leetcode.com/problems/maximum-product-of-three-numbers/description

class Solution:
    def maximumProduct(self, nums: list[int]) -> int:
        return max((nums:=sorted(nums))[-1]*nums[-2]*nums[-3], nums[0]*nums[1]*nums[-1])
