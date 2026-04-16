# O(n) cmon we've got this
class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        if len(nums) == 1:
            return 1
        elif len(nums) == 0:
            return 0
        
        nums=sorted(set(nums))
        seq,ct = [],1
        for i in range(1,len(nums)):
            if nums[i] == nums[i-1]+1:
                ct += 1
                if i == len(nums)-1:
                    seq.append(ct)
            else:
                seq.append(ct)
                ct = 1
        return max(seq) if seq else 1

