/**
 * Author: DanPlus6 // David Fu
 * Problem Name: 3867. Sum of GCD of Formed Pairs
 * Problem Code: sum-of-gcd-of-formed-pairs
 * Problem URL:  https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/description
 */
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;
typedef vector<int> vi;
#define ALL(x) x.begin(), x.end()

class Solution {
public:
    ll gcdSum(vi &nums) {
        int n = nums.size();
        for (int mx=0,i=0;i<n;++i) {
            mx = max(nums[i], mx);
            nums[i] = gcd(nums[i],mx);
        }
        sort(ALL(nums));

        ll res = 0;
        for (int l=0,r=n-1; l<r; ++l,--r) {
            res += gcd(nums[l], nums[r]);
        }

        return res;
    }
};
