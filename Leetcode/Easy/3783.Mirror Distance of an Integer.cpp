// 3783.Mirror Distance of an Integer
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")


class Solution {
public:
    int mirrorDistance(int n) {
        int N = n;
        int rev = 0;
        while (n) {
            rev = rev*10 + (n%10);
            n /= 10;
        }

        return abs(N - rev);
    }
};
