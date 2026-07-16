/**
 * Author: DanPlus6 // David Fu
 * Problem Name: 3867. Sum of GCD of Formed Pairs
 * Problem Code: sum-of-gcd-of-formed-pairs
 * Problem URL:  https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/description
 */
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;
typedef vector<int> vi;
#define ALL(x) x.begin(), x.end()

class Solution {
public:
    ll gcdSum(vi &nums) {
        int n = nums.size();
        vi pga(n,0); {
            vi pma(n,0); pma[0] = nums[0];
            for (int i=1;i<n;++i)
                pma[i] = max(pma[i-1], nums[i]);
            for (int i=0;i<n;++i)
                pga[i] = __gcd(nums[i],pma[i]);
        }
        sort(ALL(pga));

        ll res = 0;
        if (n&1) {
            for (int l=0,r=n-1;l<n/2 && r>n/2;++l,--r)
                res += __gcd(pga[l],pga[r]);
        } else {
            for (int l=0,r=n-1;l<=n/2 && r>=n/2;++l,--r)
                res += __gcd(pga[l],pga[r]);
        }

        return res;
    }
};
