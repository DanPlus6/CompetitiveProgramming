# Author: DanPlus6 // David Fu
# Problem Name: 1081. Smallest Subsequence of Distinct Characters
# Problem Code: smallest-subsequence-of-distinct-characters
# Problem URL:  https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description
from collections import Counter

class Solution:
    def smallestSubsequence(self, s: str) -> str:
        freq = Counter(s)
        seen = set()
        stk = []

        for c in s:
            freq[c] -= 1
            if c in seen: continue

            while stk and stk[-1] > c and freq[stk[-1]]:
                seen.remove(stk.pop())

            stk.append(c)
            seen.add(c)
        
        return ''.join(stk)
