# Author: DanPlus6 // David Fu
# Problem Name: 1464. Maximum Product of Two Elements in an Array
# Problem URL:  https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
# Problem Code: maximum-product-of-two-elements-in-an-array

class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        return ((nums:=sorted(nums))[-1]-1)*(nums[-2]-1)
