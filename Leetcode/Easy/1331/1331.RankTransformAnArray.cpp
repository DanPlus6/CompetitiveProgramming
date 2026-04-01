// 1331. Rank Transform of An Array
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef vector<int> vi;
typedef set<int> si;
#define ALL(x) x.begin(), x.end()

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};
        
        vi unq(arr);
        sort(ALL(unq));
        auto duplicates = unique(ALL(unq));
        int uniqueElems = distance(unq.begin(),duplicates);
        if (uniqueElems == 1) return vi(size(arr),1);

        unordered_map<int,int> ranks;
        for (int i=0; i<uniqueElems; i++) ranks[unq[i]] = i+1;

        for (int i=0; i<size(arr); i++) arr[i] = ranks[arr[i]];
        return arr;
    }
};
