// 91. Decode Ways
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int N = s.size();
        if (s[0] == '0') return 0;
        if (N == 1) { if (s[0] != '0') {return 1;} return 0; }
        if (N == 0) return 0;
        
        int res = 1, nres;
        for (int i = N-1; i >= 0; i--) {
            int cur = (s[i] == '0') ? 0 : res;
            if (i < N-1 && (s[i] == '1' || s[i] == '2' && (s[i+1] != '7' && s[i+1] != '8' && s[i+1] != '9'))) cur += nres;
            nres = res;
            res = cur;
        }
        return res;
    }
};

// class Solution {
// public:
//     static int numDecodings(string s) {
//         int N = s.size();
//         if (s[0] == '0') return 0;
//         if (N == 1) { if (s[0] != '0') {return 1;} return 0; }
//         if (N == 0) return 0;
        
//         int res = 1, nres;
//         for (int i = N-1; i >= 0; i--) {
//             int cur = (s[i] == '0') ? 0 : res;
//             if (i < N-1 && (s[i] == '1' || s[i] == '2' && (s[i+1] != '7' && s[i+1] != '8' && s[i+1] != '9'))) cur += nres;
//             nres = res;
//             res = cur;
//         }
//         return res;
//     }
// };

// int main() {
//     cout << Solution::numDecodings("123");
//     return 0;
// }
