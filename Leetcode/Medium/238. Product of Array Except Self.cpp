// 238. Product of Array Except Self
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

class Solution {
public:
    vi productExceptSelf(vi &nums) {
        int N = nums.size();
        vi ppa(N); ppa[0] = nums[0];
        for (int i=1;i<N;++i) ppa[i] = nums[i]*ppa[i-1];
        vi spa(N); spa[N-1] = nums[N-1];
        for (int i=N-2;i>=0;--i) spa[i] = nums[i]*spa[i+1];

        vi res(N); 
        res[0] = spa[1]; res[N-1] = ppa[N-2];
        for (int i = 1; i < N-1; ++i) {
            res[i] = ppa[i-1]*spa[i+1];
        }
        
        return res;
    }
};
