// 20. Valid Parentheses
#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vc;
#define ALL(x) x.begin(), x.end()
#define found(arr,x) find(ALL(arr), x) != arr.end()
#define CLOOP(s) for (char c: s)
#define pb push_back

class Solution {
public:
    bool isValid(const string &s) {
        if (s.length() & 1) return false;
        vc stk;
        unordered_map<char,char> mapper = {{'(',')'}, {'{','}'}, {'[',']'}};
        const array<char,3> left = {'(', '{', '['};
        CLOOP(s) {
            if (found(left,c)) stk.pb(c);
            else {
                if (mapper[stk.back()] != c) return false;
                stk.pop_back();
            }
        }
        return true;
    }
};

