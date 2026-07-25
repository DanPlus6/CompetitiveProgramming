# Author: DanPlus6 // David Fu
# Problem Name: 696. Count Binary Substrings
# Problem Code: count-binary-substrings
# Problem URL:  https://leetcode.com/problems/count-binary-substrings/description
class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        res = prev_sz = 0
        cur_sz = 1
        for i in range(1,len(s)):
            if s[i] == s[i-1]: cur_sz += 1
            else:
                prev_sz = cur_sz
                cur_sz = 1

            if cur_sz <= prev_sz: res += 1

        return res
