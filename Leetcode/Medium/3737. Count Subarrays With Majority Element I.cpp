// 3737. Count Subarrays With Majority Element I
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        vi psa(nums.size(), 0); {
            psa[0] = (nums[0]==target)?1:0;
            for (int i = 1; i < nums.size(); ++i)
                psa[i] = psa[i-1] + ((nums[i]==target) ? 1 : 0);
        }

        ll res = 0;
        for (int ct = 0, i = 0; i < nums.size(); ++i) {
            ct = 0;
            for (int len, j = i; j < nums.size(); ++j) {
                ct = psa[j] - ((i>0) ? psa[i-1] : 0);
                if ((ct*2) > (j-i+1)) ++res;
            }
        }
        
        return res;
    }
};
