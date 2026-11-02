# Author: DanPlus6 // David Fu
# Problem Name: 3731. Find Missing Elements
# Problem URL:  https://leetcode.com/problems/find-missing-elements/
# Problem Code: find-missing-elements

class Solution:
    def findMissingElements(self, nums: list[int]) -> list[int]:
        return [i for i in range(min(nums)+1,max(nums)) if i not in set(nums)]
