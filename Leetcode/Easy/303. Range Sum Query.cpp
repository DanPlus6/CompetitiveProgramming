// 303. Range Sum Query
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class NumArray {
public:
    vi psa;

    NumArray(vector<int>& nums) {
        psa.resize(nums.size());
        psa[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            psa[i] = nums[i] + psa[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return psa[right];
        return psa[right] - psa[left-1];
    }
};
