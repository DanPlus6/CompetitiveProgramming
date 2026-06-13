# 3838. Weighted Word Mapping

class Solution:
    def mapWordWeights(self, words: list[str], weights: list[int]) -> str:
        BASE = ord('a')
        ALPHA = list('abcdfghijklmnopqrstuvwxyz')[::-1]
        
        res = ""
        for word in words:
            tmp = 0
            for c in word:
                print(ord(c) - BASE)
                tmp += weights[ord(c) - BASE]
            res += ALPHA[tmp%26]
        
        return res
