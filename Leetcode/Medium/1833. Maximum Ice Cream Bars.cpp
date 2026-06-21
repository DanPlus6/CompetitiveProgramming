// 1833. Maximum Ice Cream Bars
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define ALL(x) x.begin(), x.end()

class Solution {
public:
    int maxIceCream(vi &costs, int coins) {
        sort(ALL(costs));

        int res = 0;
        for (int i = 0; i < costs.size(); i++) {
            coins -= costs[i];
            if (coins >= 0) ++res;
            else break;
        }

        return res;
    }
};
