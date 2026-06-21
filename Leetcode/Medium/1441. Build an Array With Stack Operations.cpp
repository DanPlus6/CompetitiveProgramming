// 1441. Build an Array With Stack Operations
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define pb push_back

class Solution {
public:
    vs buildArray(vi &target, int n) {
        vs res;
        for (int last = 0, i = 0; i < target.size(); i++) {
            if (target[i]-last == 1) res.pb("Push");
            else {
                LOOP(target[i]-last-1) {
                    res.pb("Push");
                    res.pb("Pop");
                }
                res.pb("Push");
            }

            last = target[i];
        }

        return res;
    }
};
