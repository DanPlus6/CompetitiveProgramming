// 485. Max Consecutive Ones
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cur = (nums[0] ? 1 : 0);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i]) ++cur;
            else {
                res = max(res, cur);
                cur = 0;
            }
        }
        res = max(res, cur);

        return res;
    }
};
