/**
 * Author: DanPlus6 // David Fu
 * Problem Name: 3658. GCD of Odd and Even Sums
 * Problem Code: gcd-of-odd-and-even-sums
 * Problem URL:  https://leetcode.com/problems/gcd-of-odd-and-even-sums/description
 */
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = n*n, sumEven = n*(n-1);
        return __gcd(sumOdd,sumEven);
    }
};
