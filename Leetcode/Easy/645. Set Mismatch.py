# 645. Set Mismatch

class Solution:
    def findErrorNums(self, nums: list[int]) -> list[int]:
        freq = [0] * (len(nums)+1)
        dupe = -1

        for i in nums:
            freq[i] += 1
            if freq[i] == 2: dupe = i

        for i in range(1, len(nums)+1):
            if not freq[i]:
                return [dupe, i]
            

