// 1331. Rank Transform of An Array
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef vector<int> vi;
#define ALL(x) x.begin(), x.end()

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};
        
        vi unq(arr);
        sort(ALL(unq));
        unq.erase(unique(ALL(unq)), unq.end());
        if (size(unq) == 1) return vi(size(arr),1);

        unordered_map<int,int> ranks;
        for (int &i: arr) {
            i = lower_bound(ALL(unq), i) - unq.begin() + 1;
        }

        return arr;
    }
};
