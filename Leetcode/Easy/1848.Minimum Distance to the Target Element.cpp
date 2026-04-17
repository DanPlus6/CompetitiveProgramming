// 1848.Minimum Distance to the Target Element
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#define PRIMLOOP(N) for (int i = 0; i < N; i++)
constexpr int INF = 0x3F3F3F3F;


class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = INF;
        PRIMLOOP(nums.size()) {
            if (nums[i] == target) res = min(res, abs(i-start));
            if (res == 0) return 0;
        }
        return res;
    }
};
