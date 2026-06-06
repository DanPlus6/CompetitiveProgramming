// 2574. Left and Right Sum Differences
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vi res(nums.size()); {
            vi lft(nums.size()), rit(nums.size());

            lft[0] = 0;
            for (int i = 1; i < nums.size(); i++) {
                lft[i] = lft[i-1] + nums[i-1];
            }

            rit[0] = 0;
            for (int i = nums.size()-2; i >= 0; i--) {
                rit[i] = rit[i+1] + nums[i+1];
            }

            for (int i = 0; i < nums.size(); i++) {
                res[i] = abs(lft[i] - rit[i]);
            }
        }

        return res;
    }
};
