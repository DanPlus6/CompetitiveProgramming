// 961. N-Repeated Element in Size 2N Array
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        set<int> seen;
        for (int &i: nums) {if (seen.find(i) != seen.end()) {return i;} seen.emplace(i);}
        return 0;
    }
};
