// 2553. Separate the Digits in an Array
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define ILOOP(arr) for (int &i: arr)
#define pb push_back


class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vi res;
        ILOOP(nums) {
            if (i < 10) { res.pb(i); continue; }
            getDigits(i, res);
        }
        
        return res;
    }
private:
    void getDigits(int n, vi &res) {
        if (n == 0) { res.pb(0); return; }

        int div = 1;
        while (n / div >= 10) div *= 10;

        while (div > 0) {
            res.pb((n / div) % 10);
            div /= 10;
        }
    }
};
