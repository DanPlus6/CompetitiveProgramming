# 3838. Weighted Word Mapping

class Solution:
    def mapWordWeights(self, words: list[str], weights: list[int]) -> str:
        BASE = ord('a')
        ZED = ord('z')
        
        res = ""
        for word in words:
            tmp = 0
            for c in word:
                tmp += weights[ord(c) - BASE]
            tmp %= 26
            res += chr(ZED - tmp)
        
        return res

