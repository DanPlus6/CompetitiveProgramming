// 66. Plus One
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int N = digits.size()-1;
        if (++digits[N] != 10) {return digits;}
        for (int i = N; i >= 0; i--) {
            if (++digits[i] < 10) {return digits;}
            digits[i] = 0;
        }

        digits.insert(digits.begin(),1);
        
        return digits;
    }
};
