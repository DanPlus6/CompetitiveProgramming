# Author: DanPlus6 // David Fu
# Problem Name: 3536. Maximum Product of Two Digits
# Problem Code: maximum-product-of-two-digits
# Problem URL:  https://leetcode.com/problems/maximum-product-of-two-digits/

# @param {Integer[]} nums
# @return {Integer}
def maximum_product(nums)
    [(nums=nums.sort)[-1]*nums[-2]*nums[-3], nums[0]*nums[1]*nums[-1]].max
end
