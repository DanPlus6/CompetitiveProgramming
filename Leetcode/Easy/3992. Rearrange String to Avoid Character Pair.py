# Author: DanPlus6 // David Fu
# Problem Name: 3992. Rearrange String to Avoid Character Pair
# Problem Code: rearrange-string-to-avoid-character-pair
# Problem URL:  https://leetcode.com/problems/rearrange-string-to-avoid-character-pair/description

from collections import Counter
class Solution:
    def rearrangeString(self, s: str, x: str, y: str) -> str:
        s = Counter(s)
        res = ""
        for _ in range(s[y]): res += y
        for _ in range(s[x]): res += x
        for k,v in s.items():
            if k != x and k != y:
                for _ in range(v): res += k

        return res
