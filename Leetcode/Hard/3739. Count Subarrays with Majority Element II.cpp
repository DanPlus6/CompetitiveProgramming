// 3739. Count Subarrays with Majority Element II
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

class Solution {
public:
    ll countMajoritySubarrays(vector<int>& nums, int T) {
        int N = nums.size();

        vi pfreq(N*2+1, 0); pfreq[N] = 1;
        int ps = N; ll cres = 0;
        ll res = 0;
        for (int i = 0; i < N; ++i) {
            if (nums[i] == T) {
                cres += pfreq[ps];
                ++ps;
                ++pfreq[ps];
            } else {
                --ps;
                cres -= pfreq[ps];
                ++pfreq[ps];
            }

            res += cres;
        }
        
        return res;
    }
};
