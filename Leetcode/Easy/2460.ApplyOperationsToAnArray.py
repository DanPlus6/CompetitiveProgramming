class Solution:
    def applyOperations(self, nums: list[int]) -> list[int]:
        n = len(nums)
        for i in range(n):
            if i != len(nums)-1:
                if nums[i] == nums[i+1]:
                    nums[i] *= 2
                    nums[i+1] = 0
        
        def nZ(v):
            if v != 0:
                return True
            else:
                return False
        
        def iZ(v):
            if v != 0:
                return False
            else:
                return True

        subfinal = [i for i in filter(nZ, nums)]
        for i in filter(iZ, nums):
            subfinal.append(i)

        return subfinal
        
