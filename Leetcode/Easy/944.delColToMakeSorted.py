# mine
"""
class Solution:
    def minDeletionSize(self, strs: list[str]) -> int:
        N = len(strs)
        M = len(strs[0])
        if M == 1: return 1 if strs != sorted(strs) else 0
        res = 0
        for i in range(len(strs[0])):
            tmp = [row[i] for row in strs]
            if tmp != sorted(tmp): res += 1
        return res
"""
        
# bro 💀
class Solution:
    def minDeletionSize(self, strs: list[str]) -> int:
        return sum(col!=sorted(col) for col in map(list,zip(*strs)))
    