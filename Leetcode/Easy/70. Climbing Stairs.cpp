// 70. Climbing Stairs
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int &n) {
        if (n == 1) return 1;

        int prev = 1, cur = 1, tmp;
        for (int i = 2; i <= n; i++) {
            tmp = cur;
            cur = prev+cur;
            prev = tmp;
        }

        return cur;
    }
};
