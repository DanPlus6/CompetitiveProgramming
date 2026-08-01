# Author: DanPlus6 // David Fu
# Problem Name: 11. Container With Most Water
# Problem URL:  https://leetcode.com/problems/container-with-most-water/description/
# Problem Code: container-with-most-water

class Solution:
    def maxArea(self, height: list[int]) -> int:
        l,r = 0, len(height)-1
        res = 0
        while l<r:
            area  = (r-l)*min(height[l],height[r])
            res = max(res,area)
            if height[l]<height[r]:
                l +=1
            else:
                r-=1
        return res

