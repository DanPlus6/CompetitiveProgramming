/**
 * Author: DanPlus6 // David Fu
 * Problem Name: 696. Count Binary Substrings
 * Problem Code: count-binary-substrings
 * Problem URL:  https://leetcode.com/problems/count-binary-substrings/description
 */
#include <string>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0;
        for (int prev_sz = 0, cur_sz = 1, i = 1; i < s.length(); ++i) {
            if (s[i] == s[i-1]) ++cur_sz;
            else {
                prev_sz = cur_sz;
                cur_sz = 1;
            }

            if (cur_sz <= prev_sz) ++res;
        }

        return res;
    }
};
