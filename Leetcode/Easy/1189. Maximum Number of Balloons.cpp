// 1189. Maximum Number of Balloons
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> freq;
        for (char c: text) ++freq[c];

        int res = freq['b'];
        res = min(res, freq['a']);
        res = min(res, freq['l']/2);
        res = min(res, freq['o']/2);
        res = min(res, freq['n']);

        return res;
    }
};
