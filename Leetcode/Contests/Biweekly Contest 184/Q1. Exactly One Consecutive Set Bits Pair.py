# Q1. Exactly One Consecutive Set Bits Pair
class Solution:
    def consecutiveSetBits(self, n: int) -> bool:
        if n <= 0: return False

        pairs = n & (n >> 1)

        return pairs > 0 and (pairs & (pairs - 1)) == 0
        

