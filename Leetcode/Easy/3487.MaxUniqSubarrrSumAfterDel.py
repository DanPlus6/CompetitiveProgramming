# Inefficient solution 😪
class Solution:
    def maxSum(self, nums: list[int]) -> int:
        posPresent = False
        for i in nums:
            if i > 0:
                posPresent = True
                nums = list(filter(lambda a: a > 0,nums))
                nums = list(set(nums))
                return sum(nums)
        return max(nums)

# Efficient and concise solution 🧠
class Solution:
    def maxSum(self, nums: list[int]) -> int:
        # the part below accounts for situation where nums is filled with only negative ints
        if all(n < 0 for n in nums): # converts all elements inside nums into an array where neg = True and pos = False
            return max(nums) # in such situation where all integers are negative, return the max value
        
        unique = set(nums)
        return sum(n for n in unique if n > 0) # a bit more concise way of what I did (also a whole lot more efficient in time complexity)
