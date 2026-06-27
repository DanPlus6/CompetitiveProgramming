// 3739. Count Subarrays with Majority Element II
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

class Solution {
public:
    ll countMajoritySubarrays(vector<int>& nums, int T) {
        int N = nums.size();

        vi psf(N*2+1, 0); psf[N] = 1;
        int cnt = N;
        ll res = 0, ps = 0;
        for (int i = 0; i < N; ++i) {
            if (nums[i] == T) {
                ps += psf[cnt];
                ++cnt;
                ++psf[cnt];
            } else {
                --cnt;
                ps -= psf[cnt];
                ++psf[cnt];
            }

            res += ps;
        }
        
        return res;
    }
};
