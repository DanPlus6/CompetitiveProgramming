// 415. Add Strings
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#define endl '\n'
#define ALL(x) x.begin(), x.end()


class Solution {
public:
    string addStrings(string num1, string num2) {
        int it1 = num1.length()-1, it2 = num2.length()-1;

        string res = "";
        int tmpSum, carry = 0;
        while (it1 >= 0 || it2 >= 0 || carry) {
            int tmpSum = ((it1 >= 0)? num1[it1--] - '0' : 0) + ((it2 >= 0)? num2[it2--] - '0' : 0) + carry;

            res += (tmpSum % 10 + '0');
            carry = tmpSum / 10;
        }

        reverse(ALL(res));
        return res;
    }
};
