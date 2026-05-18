// 69. Sqrt(x)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        int left = 1, right = x, mid = -1;
        while (left <= right) {
            mid = left + (right-left) / 2;

            ll sq = static_cast<ll>(mid) * mid;

            if (sq > x) right = mid-1;
            else if (sq == x) return mid;
            else left = mid+1;
        }

        return static_cast<int>(round(right));
    }
};
