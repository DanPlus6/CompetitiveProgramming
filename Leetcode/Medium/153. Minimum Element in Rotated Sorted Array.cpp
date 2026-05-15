// 153. Minimum Element in Rotated Sorted Array
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int minn = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            minn = min(minn, nums[i]);
        }
        return minn;
    }
};
