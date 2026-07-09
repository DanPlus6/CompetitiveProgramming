// 3532. Path Existence Queries in a Graph I
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
#define pb push_back

class Solution {
public:
    vb pathExistenceQueries(int n, vi &nums, int maxDiff, vvi &queries) {
        vi comp(n,0);
        int compN = 0;
        for (int i=1;i<n;++i) {
            if ((nums[i] - nums[i-1]) > maxDiff) ++compN;
            comp[i] = compN;
        }

        vb sol;
        for (vi &q: queries)
            sol.pb(comp[q[0]] == comp[q[1]]);

        return sol;
    }
};
