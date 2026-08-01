/**
 * Author: DanPlus6 // David Fu
 * Problem Name: 3016. Minimum Number of Pushes to Type Word II
 * Problem URL:  https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/
 * Problem Code: minimum-number-of-pushes-to-type-word-ii
 */
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define ALL(x) x.begin(),x.end()

class Solution {
public:
    int minimumPushes(string &S) {
        vi freq(26,0);
        for (char &c:S) ++freq[c-'a'];
        sort(ALL(freq),greater<>());

        int res = 0, i = 0;
        auto press = [&](int &i, int n, int p) {
            for (;n-- && i != freq.size(); ++i) res += freq[i]*p;
        };
        
        press(i,8,1);
        press(i,8,2);
        press(i,8,3);
        press(i,2,4);

        return res;
    }
};

