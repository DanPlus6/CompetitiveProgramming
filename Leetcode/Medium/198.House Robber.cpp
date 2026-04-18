// 198.House Robber
#include <bits/stdc++.h>
using namespace std;

#define ILOOP(arr) for (const int &i: arr)

class Solution {
public:
    static int rob(const vector<int>& nums) {
        int prev1 = 0;
        int prev2 = 0;
        ILOOP(nums) {
            int tmp = prev1;
            prev1 = max(prev2 + i, prev1);
            prev2 = tmp;
        }
        return prev1;
    }
};

