// 1306. Jump Game III
#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> vb;
typedef queue<int> qi;


class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vb vis(arr.size(),false);
        qi q;
 
        q.push(start);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (vis[cur]) continue;

            vis[cur] = true;
            if (arr[cur] == 0) return true;

            int f = cur + arr[cur], b = cur - arr[cur];

            if (f < arr.size() && !vis[f]) q.push(cur + arr[cur]);
            if (b >= 0 && !vis[b]) q.push(cur - arr[cur]);
        }

        return false;
    }
};
