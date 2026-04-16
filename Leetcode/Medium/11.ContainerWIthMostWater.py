# my solution but O(1) memory by using max, and the guy didn't have carbon monoxide poisoning
class Solution:
    def maxArea(self, height: list[int]) -> int:
        l,r = 0, len(height)-1
        res = 0 # O(1) space
        while l<r: # smart
            area  = (r-l)*min(height[l],height[r])
            res = max(res,area) # smart
            if height[l]<height[r]:
                l +=1
            else:
                r-=1
        return res



# inefficient O(n) solution
"""
class Solution:
    def maxArea(self, height: list[int]) -> int:
        maxes = []
        n = len(height)
        l,r = 0,n-1
        while True:
            try:
                left,right = height[l],height[r]
                m = (min(left,right)*(r-l))
                if m >= 0:
                    maxes.append(m)
                else:
                    break
                if left > right:
                    r -= 1
                elif left < right:
                    l += 1
                elif left == right:
                    r -= 1
            except IndexError:
                break

        return max(maxes)
"""
