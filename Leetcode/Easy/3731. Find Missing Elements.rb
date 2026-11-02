# Author: DanPlus6 // David Fu
# Problem Name: 3731. Find Missing Elements
# Problem URL:  https://leetcode.com/problems/find-missing-elements/
# Problem Code: find-missing-elements

# @param {Integer[]} nums
# @return {Integer[]}
def find_missing_elements(nums)
    (nums.min..nums.max).to_a - nums
end
