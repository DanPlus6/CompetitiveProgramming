// 9. Palindrome Number
#include <bits/stdc++.h>
using namespace std;
char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        ll reverse = 0;
        ll tmp = x;
        while (tmp) {
            reverse = reverse*10 + tmp%10;
            tmp /= 10;
        }

        return reverse == x;
    }
};
