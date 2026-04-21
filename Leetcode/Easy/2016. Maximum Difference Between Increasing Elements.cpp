// 2016. Maximum Difference Between Increasing Elements
#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 0x3F3F3F3F;


class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minn = INF, min_i = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res = max(res,nums[i] - minn);
            if (nums[i] < minn) {
                minn = min(minn,nums[i]);
                min_i = i;
            }
        }

        return (res != 0 ? res : -1);
    }
};
