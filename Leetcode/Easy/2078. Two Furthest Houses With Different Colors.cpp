// 2078. Two Furthest Houses With Different Colors
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxDistance(const vector<int>& colors) {
        ulong res = colors.size()-1;
        for (;colors[res] == colors[0];res--);

        ulong it = 0;
        for (; colors[it] == colors.back();it++);
        res = max(res, colors.size()-1-it);

        return res;
    }
};
