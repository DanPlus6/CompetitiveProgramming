# 1291. Sequential Digits
class Solution:
    def sequentialDigits(self, low: int, high: int) -> list[int]:
        digs = "123456789"
        res = []
        for l in range(1,10):
            for i in range(9):
                if (i+l) > len(digs): continue
                tmp = int(digs[i:i+l])
                if (low <= tmp <= high): res.append(tmp)

        return res
