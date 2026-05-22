// 3043. Find the Length of the Longest Common Prefix
#include <bits/stdc++.h>
using namespace std;

typedef unordered_set<int> si;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        si p1;

        for (int num: arr1) {
            while (!p1.count(num) && num > 0) {
                p1.insert(num);
                num /= 10;
            }
        }

        int res = 0;
        for (int num: arr2) {
            while (!p1.count(num) && num > 0) num /= 10;
            if (num) {
                res = max((int)log10(num) + 1, res);
            }
        }
        return res;
    }
};
