// 14. Longest Common Prefix
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    static string longestCommonPrefix(const vector<string>& strs) {
        string res = "";

        if (strs.size() == 1) return strs[0];

        for (int it = 0;;it++) {
            char c = '\0';
            for (const string &s: strs) {
                if (!s[it]) return res;
                if (!c) c = s[it];
                else if (s[it] != c) return res;
            }
            res += c;
        }

        return res;
    }
};
