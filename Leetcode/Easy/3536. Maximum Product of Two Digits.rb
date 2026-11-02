# Author: DanPlus6 // David Fu
# Problem Name: 3536. Maximum Product of Two Digits
# Problem Code: maximum-product-of-two-digits
# Problem URL:  https://leetcode.com/problems/maximum-product-of-two-digits/

# @param {Integer} n
# @return {Integer}
def max_product(n)
    (digs = n.to_s.chars.map(&:to_i).sort)[-1] * digs[-2]    
end
