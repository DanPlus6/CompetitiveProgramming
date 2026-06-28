// 1846. Maximum Element After Decreasing and Rearranging
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define ALL(x) x.begin(), x.end()

class Solution {
public:
    static int maximumElementAfterDecrementingAndRearranging(vi &arr) {
        int N = arr.size();
        sort(ALL(arr)); arr[0] = 1;

        int res = 1;
        for (int i = 1; i < N; ++i) {
            if (arr[i] >= res + 1)
                ++res;
        }

        return res;
    }
};
