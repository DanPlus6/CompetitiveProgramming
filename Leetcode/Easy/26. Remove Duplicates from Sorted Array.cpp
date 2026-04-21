// 26. Remove Duplicates from Sorted Array
#include <bits/stdc++.h>
using namespace std;

typedef set<int> si;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = nums.size();
        si seen;
        for (auto it = nums.begin(); it != nums.end(); ) {
            if (seen.contains(*it)) {
                it = nums.erase(it);
                --k;
            } else {
                seen.insert(*it);
                ++it;
            }
        }
        return k;
    }
};
