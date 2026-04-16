// 2839. Check if Strings Can be Made Equal With Operations I
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool canBeEqual(string s1, string s2) {
        return (
            s1 == s2 || // no swap
            (s1[0] == s2[2] && s1[1] == s2[1] && s1[2] == s2[0] && s1[3] == s2[3]) || // just 0,2 swap
            (s1[0] == s2[0] && s1[1] == s2[3] && s1[2] == s2[2] && s1[3] == s2[1]) || // just 1,3 swap
            (s1[0] == s2[2] && s1[1] == s2[3] && s1[2] == s2[0] && s1[3] == s2[1]) // both swap
        );
    }
};
