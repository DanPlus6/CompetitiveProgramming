# Author: DanPlus6 // David Fu
# Problem Name: 3950. Exactly One Consecutive Set Bits Pair
# Problem Code: exactly-one-consecutive-set-bits-pair
# Problem URL:  https://leetcode.com/problems/exactly-one-consecutive-set-bits-pair/description

class Solution:
    def consecutiveSetBits(self, n: int) -> bool:
        if n <= 0: return False

        pairs = n & (n >> 1)

        return pairs > 0 and (pairs & (pairs - 1)) == 0
        

