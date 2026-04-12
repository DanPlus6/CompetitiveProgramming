# efficient solution using hashmap
# hashmap benefit: 
# - only traverse list one time
# - traverse less "distance" when finding if difference exists
class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        hashmap = {}
        for i in range(len(nums)):
            difference = target - nums[i]
            if difference in hashmap:
                return [i, hashmap[difference]]
            hashmap[nums[i]] = i
        return []
                

# inefficient (my solution) (semi-bruteforce)
"""
class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        for k,v in enumerate(nums):
            dif = target-v
            if dif in nums and nums.index(dif) != k:
                return [k,nums.index(target-v)]
"""
                

print(Solution.twoSum(None,[3,2,4],6))

