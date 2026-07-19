/**
 * Author: DanPlus6 // David Fu
 * Problem Name: 3952. Maximum Total Value of Covered Indices
 * Problem Code: maximum-total-value-of-covered-indices
 * Problem URL:  https://leetcode.com/problems/maximum-total-value-of-covered-indices/description
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define pb push_back

constexpr ll NEG_INF = LLONG_MIN / 2;

class Solution {
public:
ll maxTotal(vi& nums, string s) {
        vi tk;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '1') tk.pb(i);
        if (tk.empty()) return 0;

        ll stay = nums[tk[0]];
        ll move = (tk[0] > 0) ? (ll)nums[tk[0] - 1] : NEG_INF;

        for (int j = 1; j < tk.size(); j++) {
            int cur = tk[j], prv = tk[j - 1];

            ll best = ((move != NEG_INF) ? max(stay, move) : stay);

            ll cstay = best + nums[cur], cmove;
            if (cur == prv + 1) {
                ll opt1 = stay, 
                    opt2 = (move != NEG_INF) ? move + nums[prv] : NEG_INF;
                cmove = (opt2 != NEG_INF) ? max(opt1, opt2) : opt1;
            } else {
                cmove = best + nums[cur - 1];
            }

            stay = cstay;
            move = cmove;
        }

        return (move != NEG_INF) ? max(stay, move) : stay;
    }
};
