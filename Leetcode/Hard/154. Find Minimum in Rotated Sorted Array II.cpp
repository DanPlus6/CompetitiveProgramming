// 154. Find Minimum in Rotated Sorted Array II
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) res = min(res, nums[i]);
        return res;
    }
};
