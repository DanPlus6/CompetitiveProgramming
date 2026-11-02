# Author: DanPlus6 // David Fu
# Problem Name: 3536. Maximum Product of Two Digits
# Problem Code: maximum-product-of-two-digits
# Problem URL:  https://leetcode.com/problems/maximum-product-of-two-digits/

class Solution:
    def maxProduct(self, n: int) -> int:
        return (digs:=(sorted(map(int,str(n)))))[-1]*digs[-2]
