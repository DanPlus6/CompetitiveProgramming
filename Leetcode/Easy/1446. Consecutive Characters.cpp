// 1446. Consecutive Characters
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int res = 1, cur = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i-1]) {
                res = max(cur, res);
                cur = 1;
            } else {
                ++cur;
            }
        }
        
        return max(res, cur);
    }
};
