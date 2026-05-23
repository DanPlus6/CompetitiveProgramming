// 1752. Check if Array is Sorted and Rotated
#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define rt(x) rotate(x.begin(), x.begin()+1, x.end())

class Solution {
public:
    bool check(vector<int> nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (is_sorted(ALL(nums))) return true;
            rt(nums);
        }
        return false;
    }
};

