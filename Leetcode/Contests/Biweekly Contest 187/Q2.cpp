/**
 * Author: DanPlus6 // David Fu
 * Problem Name: Q2. Maximum Value of An Alternating Sequence
 * Problem Code: maximum-value-of-an-alternating-sequence
 * Problem URL:  https://leetcode.com/problems/maximum-value-of-an-alternating-sequence/description
 */
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;

class Solution {
public:
    ll maximumValue(int n, int s, int m) {
        if (n == 1) return s;
        else {
            ll k = n/2ll;
            return s + k*(m-1) + 1;
        }
    }
};
