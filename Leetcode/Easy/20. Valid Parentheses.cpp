// 20. Valid Parentheses
#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vc;
#define ALL(x) x.begin(), x.end()
#define CLOOP(s) for (char c: s)
#define pb push_back

class Solution {
public:
    static bool isValid(const string &s) {
        if (s.length() & 1) return false;
        vc stk;
        unordered_map<char,char> mapper = {{'(',')'}, {'{','}'}, {'[',']'}};
        CLOOP(s) {
            if (c == '(' || c == '[' || c == '{') stk.pb(c);
            else {
                if (stk.empty()) return false;
                if (mapper[stk.back()] != c) return false;
                stk.pop_back();
            }
        }
        return stk.empty();
    }
};
