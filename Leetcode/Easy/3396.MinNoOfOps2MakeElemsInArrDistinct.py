# other person's more efficient solution
class Solution:
    def minimumOperations(self, nums: list[int]) -> int:
        seen = set()
        n = len(nums)

        # Find longest distinct suffix
        k = 0
        for i in range(n - 1, -1, -1):
            if nums[i] in seen:
                break
            seen.add(nums[i])
            k += 1

        prefix_len = n - k
        return (prefix_len + 2) // 3 # the add 2 is important, as floor division rounds down but array can be empty if need be to be considered distinct

# my solution (how do you fumble this badly)
"""
class Solution:
    def minimumOperations(self, nums: list[int]) -> int:
        if sorted(nums) == sorted(list(set(nums))):
            return 0
        
        ops = 0
        while True:
            if sorted(nums) != sorted(list(set(nums))):
                if len(nums) >= 3:
                    for i in range(3):
                        nums.pop(0)
                else:
                    return ops + 1
                ops += 1
                continue
            break

        return ops

"""

