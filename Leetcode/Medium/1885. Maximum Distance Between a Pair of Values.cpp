// 1885. Maximum Distance Between a Pair of Values
#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define PRIMLOOP(N) for (int i = 0; i < N; i++)


class Solution {
public:
    static int maxDistance(const vector<int>& nums1, const vector<int>& nums2) {
        long res = 0;
        PRIMLOOP(nums1.size()) {
            auto it = upper_bound(nums2.begin()+i, nums2.end(),nums1[i], greater<>());
            if (it != nums2.begin() + i) res = max(res, (it - nums2.begin()) - i - 1);
        }

        return res;
    }
};
