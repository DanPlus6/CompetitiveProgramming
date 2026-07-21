# Author: DanPlus6 // David Fu
# Problem Name: 3925. Cocatenate Array With Reverse
# Problem Code: concatenate-array-with-reverse
# Problem URL:  https://leetcode.com/problems/concatenate-array-with-reverse/
class Solution:
    def concatWithReverse(self, nums: list[int]) -> list[int]: return nums + nums[::-1]
