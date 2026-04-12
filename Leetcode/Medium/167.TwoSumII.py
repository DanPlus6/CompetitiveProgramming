# O(n) solution (cheated, looked at hints) (smart logic, advantage of input sorted)
class Solution:
    def twoSum(self, numbers: list[int], target: int) -> list[int]:
        if len(numbers) == 2:
            return [1,2]
        
        l,r = 0,len(numbers)-1
        while True:
            left,right = numbers[l],numbers[r]
            if left+right == target:
                return [l+1,r+1]
            elif left+right > target:
                r -= 1
            else:
                l += 1
