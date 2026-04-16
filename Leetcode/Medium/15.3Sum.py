# cheated, looked at solution video
class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums.sort()

        ret = []
        for i,v in enumerate(nums):
            if i > 0 and v == nums[i-1]:
                continue

            l,r = i+1,len(nums)-1
            while l < r:
                three = v + nums[l] + nums[r]
                if three == 0:
                    ret.append([v,nums[l],nums[r]])
                    l += 1                                  # didn't figure
                    while nums[l] == nums[l-1] and l < r:   # this part out
                        l += 1                              # w/o the solution
                elif three > 0:
                    r -= 1
                elif three < 0:
                    l += 1
        return ret
        