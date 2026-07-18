# Author: DanPlus6 // David Fu
# Problem Name: Q2. Maximum Value of An Alternating Sequence
# Problem Code: maximum-value-of-an-alternating-sequence
# Problem URL:  https://leetcode.com/problems/maximum-value-of-an-alternating-sequence/description
class Solution:
    def entityParser(self, text: str) -> str:
        tags = {"&quot;":'"', "&apos;":"'", "&gt;":">", "&lt;":"<", "&frasl;":"/"}
        for k,v in tags.items():
            text = text.replace(k,v)
        return text.replace("&amp;","&")
