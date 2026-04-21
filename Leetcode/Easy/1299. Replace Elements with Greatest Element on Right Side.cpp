// 1299. Replace Elements with Greatest Element on Right Side
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;


class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        const int n = arr.size();
        if (n == 1) return {-1};

        vi res(n,0);
        res.back() = -1;
        int maxx = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            res[i] = maxx;
            maxx = max(maxx, arr[i]);
        }

        return res;
    }
};
