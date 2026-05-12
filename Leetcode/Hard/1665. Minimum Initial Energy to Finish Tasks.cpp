// 1665. Minimum Initial Energy to Finish Tasks
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define ALL(x) x.begin(), x.end()

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(ALL(tasks), [](vi &x, vi &y){ return (x[1] - x[0]) < (y[1] - y[0]); });

        int res = 0;
        for (vi &x : tasks) {
            res = max(res + x[0], x[1]);
        }
        return res;
    }
};
