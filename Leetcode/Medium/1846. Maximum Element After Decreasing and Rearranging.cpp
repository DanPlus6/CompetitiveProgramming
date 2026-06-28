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
        vi cnt(N+1,0);

        for (int &num: arr) ++cnt[min(num, N)];

        int res = 1;
        for (int num = 2; num <= N; ++num) 
            res = min(res+cnt[num], num);

        return res;
    }
};
