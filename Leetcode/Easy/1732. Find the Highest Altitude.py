# 1732. Find the Highest Altitude

class Solution:
    def largestAltitude(self, gain: list[int]) -> int:
        hi = 0
        alt = 0
        for i in range(len(gain)):
            alt += gain[i]
            hi = max(alt, hi)

        return hi
