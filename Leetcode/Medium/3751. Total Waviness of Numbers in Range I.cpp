// 3751. Total Waviness of Numbers in Range I
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define pb push_back

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        ll res = 0;
        for (int i = num1; i <= num2; i++) {
            if (i < 100) continue;
            
            string digits = to_string(i);
            for (int i = 1; i < digits.size()-1; i++) {
                if (digits[i] > digits[i-1] && digits[i] > digits[i+1]) ++res;
                if (digits[i] < digits[i-1] && digits[i] < digits[i+1]) ++res;
            }
        }

        return res;
    }
};
