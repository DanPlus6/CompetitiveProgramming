/**
 * Author: DanPlus6 // David Fu
 * Problem Name: 3994. Minimum Adjacent Swaps to Partition Array
 * Problem Code: minimum-adjacent-swaps-to-partition-array
 * Problem URL:  https://leetcode.com/problems/minimum-adjacent-swaps-to-partition-array/description
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int minAdjacentSwaps(vi &nums, int a, int b) {
        ll res = 0;
        for (ll ct1=0,ct2=0,i=0;i<nums.size();++i) {
            if (nums[i] < a) {
                res = ((res%MOD) + (ct1%MOD) + (ct2%MOD)) % MOD;
            } else if (nums[i] <= b) {
                res = ((res%MOD) + (ct2%MOD)) % MOD;
                ++ct1;
            } else {
                ++ct2;
            }
        }

        return res;
    }
};
