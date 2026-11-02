# Author: DanPlus6 // David Fu
# Problem Name: 316. Remove Duplicate Letters
# Problem Code: remove-duplicate-letters
# Problem URL:  https://leetcode.com/problems/remove-duplicate-letters/description
from collections import Counter 

class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
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
