#new code (working but more efficient)
class Solution:
    def pivotArray(self, nums: list[int], pivot: int) -> list[int]:
        subt = []
        equal = []
        greater = []

        for i in nums:
            if i < pivot:
                subt.append(i)
            elif i == pivot:
                equal.append(i)
            elif i > pivot:
                greater.append(i)
        
        subt.extend(equal)
        subt.extend(greater)
        return subt
        

#old code (working but less efficient)
"""
class Solution:
    def pivotArray(self, nums: list[int], pivot: int) -> list[int]:
        subt = [i for i in nums if i < pivot]
        [subt.append(i) for i in nums if i == pivot]
        [subt.append(i) for i in nums if i > pivot]
        return subt
"""
