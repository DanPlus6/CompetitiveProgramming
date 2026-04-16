# my inefficient solution 🤮 (the space complexity will make you puke if not for the len(arr) <= 500 constraint)
"""
class Solution:
    def findLucky(self, arr: List[int]) -> int:
        counter = {}
        for i in arr:
            if i in counter:
                counter[i] += 1
            else:
                counter[i] = 1
        
        valid = []
        for i in counter:
            if i == counter[i]:
                valid.append(i)

        if valid:
            return max(valid)
        else:
            return -1
"""

# more efficient solution of O(501) (takes advantage of the len(arr) <= 500 constraint) (not practical solution in most situations)
"""
class Solution:
    def findLucky(self, arr):
        freq = [0 for i in range(501)]
        for i in arr:
            freq[i] += 1
        for i in range(500,0,-1): # more efficient than max() by reverse iterating through the 500 array
            if freq[i] == i:
                return i
        return -1
        
"""

# efficient O(N) solution (beats 100% runtime, 50% mem usage)
# pretty self explanatory
from counter import Counter

class Solution:
    def findLucky(self, arr: list[int]) -> int:
        lucky = -1
        cnt = Counter(arr)
        for num, count in cnt.items():
            if int(num) == count:
                lucky = max(lucky, int(num))
        return lucky


