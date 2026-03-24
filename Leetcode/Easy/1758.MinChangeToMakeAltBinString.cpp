// 1758. Minimum Changes To Make Alternating Binary String
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i & 1) {
                if (s[i] != '1') res++;
            } else {
                if (s[i] != '0') res++;
            }
        }
        int res1 = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i & 1) {
                if (s[i] != '0') res1++;
            } else {
                if (s[i] != '1') res1++;
            }
        }
        return min(res,res1);
    }
};
