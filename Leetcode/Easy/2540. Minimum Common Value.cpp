// 2540. Minimum Common Value
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.back() < nums2[0] || nums2.back() < nums1[0]) return -1;

        int it1 = 0, it2 = 0;
        while (it1 < nums1.size() && it2 < nums2.size()) {
            if (nums1[it1] == nums2[it2]) return nums1[it1];
            if (nums1[it1] > nums2[it2]) ++it2;
            else if (nums2[it2] > nums1[it1]) ++it1;
        }

        return -1;
    }
};
