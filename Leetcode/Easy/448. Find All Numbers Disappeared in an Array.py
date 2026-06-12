# 448. Find All Numbers Disappeared in an Array

class Solution:
    def findDisappearedNumbers(self, nums: list[int]) -> list[int]:
        present = set(nums)

        return [
            num
            for num in range(1, len(nums)+1)
            if num not in present
        ]
