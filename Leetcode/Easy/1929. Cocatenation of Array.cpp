// 1929. Cocatenation of Array
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vi nums_cocat(nums.size()*2);
        for (int i = 0; i < nums_cocat.size(); i++) {
            nums_cocat[i] = nums[i % nums.size()];
        }
        return nums_cocat;
    }
};
