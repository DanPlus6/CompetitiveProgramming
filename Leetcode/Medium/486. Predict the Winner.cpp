/**
 * Author: DanPlus6 // David Fu
 * Problem Name: 486. Predict the Winner
 * Problem URL:  https://leetcode.com/problems/predict-the-winner/description/
 * Problem Code: predict-the-winner
 */
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

typedef vector<int> vi;
#define FILL(a, b) memset(a, b, sizeof(a))

constexpr int MM = 20+5;

int dp[MM][MM];

class Solution {
private:
    int solve(vi &A, int l, int r) {
        if (dp[l][r] != -1) return dp[l][r];
        if (l == r) return dp[l][r] = A[l];

        return dp[l][r] = max(
            A[l] - solve(A,l+1,r),
            A[r] - solve(A,l,r-1)
        );
    }
public:
    bool predictTheWinner(vi& A) {
        if (!(A.size()&1)) return true;

        FILL(dp,-1);
        return solve(A,0,A.size()-1) >= 0;
    }
};
