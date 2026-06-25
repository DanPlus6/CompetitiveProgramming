// 3737. Count Subarrays With Majority Element I
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        ll res = 0;
        vi subarr;
        for (int ct = 0, i = 0; i < nums.size(); ++i) {
            ct = 0;
            for (int len, j = i; j < nums.size(); ++j) {
                if (nums[j] == target) ++ct;

                if ((ct*2) > (j-i+1)) ++res;
            }
        }
        
        return res;
    }
};
