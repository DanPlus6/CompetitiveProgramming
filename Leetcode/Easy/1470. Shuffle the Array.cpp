// 1470. Shuffle the Array
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vi res(n*2);

        for (int i = 0, l = 0, r = n; i < n*2; i++) {
            if (i&1) {
                res[i] = nums[r];
                ++r;
            } else {
                res[i] = nums[l];
                ++l;
            }
        }

        return res;
    }
};
