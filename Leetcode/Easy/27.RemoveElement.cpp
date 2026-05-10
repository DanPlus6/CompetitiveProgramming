// 27. Remove Element
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        int left = 0, right = nums.size()-1;
        for (int left = 0, right = nums.size()-1; left < right && left < nums.size(); left++) {
            if (nums[left] == val) {
                swap(nums[left], nums[right]);
                --right;
                ++res;
            }
        }

        for (int i = 0; i < nums.size()-1-right; i++) nums.pop_back();
        return res;
    }
};
