// 3488.Closest Equal Elements Queries
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define ALL(x) x.begin(), x.end()
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define ILOOP(arr) for (int &i: arr)
#define pb push_back


class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        map<int,vi> indices;
        PRIMLOOP(nums.size()) {
            indices[nums[i]].pb(i);
        }

        vi res;
        ILOOP(queries) {
            vi &v = indices[nums[i]];

            if (v.size() == 1) {
                res.pb(-1);
                continue;
            }

            ulong ans = ULONG_MAX;
            int pos = lower_bound(ALL(v), i) - v.begin();

            int left = v[(pos - 1 + v.size()) % v.size()]; printf("%d",left);
            int d1 = abs(i-left);
            ans = min(ans, min((ulong)d1, nums.size()-d1));

            int right = v[(pos + 1) % v.size()];
            int d2 = abs(i-right);
            ans = min(ans, min((ulong)d2, nums.size()-d2));

            res.pb(ans);
        }

        return res;
    }
};
