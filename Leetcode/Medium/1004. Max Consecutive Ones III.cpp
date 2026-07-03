// 1004. Max Consecutive Ones III
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class Solution {
public:
    int longestOnes(vi &nums, int k) {
        int N = nums.size();
        int res = 0;
        for (int zeroes = 0, l = 0, r = 0; r < N; ++r) {
            if (!nums[r]) ++zeroes;

            while (zeroes > k) {
                if (!nums[l]) --zeroes;
                ++l;
            }

            res = max((r-l+1), res);
        }

        return res;
    }
};
