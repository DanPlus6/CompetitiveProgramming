class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        sums = []
        for i in range(len(nums)):
            if i-1 != -1:
                sums.append((sums[i-1]+nums[i]))
            else:
                sums.append(nums[i])
        return sums