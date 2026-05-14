// 2784. Check if Array is Good
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        map<int,int> ct;
        int maxx = 0;
        for (int i: nums) {
            maxx = max(maxx,i);
            ++ct[i];
        }

        for (int i = 1; i < maxx; i++) {
            if (ct[i] != 1) return false;
        }
        if (ct[maxx] != 2) return false;

        return true;
    }
};
