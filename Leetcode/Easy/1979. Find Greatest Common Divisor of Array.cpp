/**
 * Author: DanPlus6 // David Fu
 * Problem Name: 1979. Find Greatest Common Divisor of Array
 * Problem Code: find-greatest-common-divisor-of-array
 * Problem URL:  https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/
 */
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef vector<int> vi;

class Solution {
public:
    int findGCD(vi &nums) {
        int mn = nums[0], mx = nums[0];
        for (int &i: nums) {
            mn = min(i, mn);
            mx = max(i, mx);
        }

        return __gcd(mn,mx);
    }
};
