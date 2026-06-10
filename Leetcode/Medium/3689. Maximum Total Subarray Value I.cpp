// 3689. Maximum Total Subarray Value I
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

class Solution {
public:
    ll maxTotalValue(vi &nums, int k) {
        int minn = nums[0], maxx = nums[0];
        for (int i=0;i<nums.size();++i) {
            minn = min(nums[i], minn);
            maxx = max(nums[i], maxx);
        }

        return 1ll * (maxx - minn) * k;
    }
};
