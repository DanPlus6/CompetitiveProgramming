# Author: DanPlus6 // David Fu
# Problem Name: 3014. Minimum Number of Pushes to Type Word I
# Problem URL:  https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/description/
# Problem Code: minimum-number-of-pushes-to-type-word-i

class Solution:
    def minimumPushes(self, word: str) -> int:
        res = min(len(word),8)
        res += min(max(len(word)-8,0),8)*2
        res += min(max(len(word)-16,0),8)*3
        res += min(max(len(word)-24,0),2)*4
        return res



