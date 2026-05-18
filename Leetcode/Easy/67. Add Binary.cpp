// 67. Add Binary
#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

class Solution {
public:
    string addBinary(string a, string b) {
        int it1 = a.length()-1, it2 = b.length()-1;

        string res = "";
        int tmpsum, carry = 0;
        while (it1 >= 0 || it2 >= 0 || carry) {
            tmpsum = ((it1 >= 0)? a[it1--] - '0' : 0) + ((it2 >= 0)? b[it2--] - '0' : 0) + carry;

            res += to_string(tmpsum % 2);
            carry = tmpsum / 2;
        }

        reverse(ALL(res));
        return res;
    }
};
