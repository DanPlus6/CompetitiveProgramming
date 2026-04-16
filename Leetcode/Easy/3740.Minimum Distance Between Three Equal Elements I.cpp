// 3740. Minimum Distance Between Three Equal Elements I
#include <bits/stdc++.h>
using namespace std;

typedef pair<optional<int>, optional<int>> pi;
#define PRIMLOOP(N) for (int i = 0; i < N; i++)

constexpr int INF = 0x3F3F3F3F;


class Solution {
public:
    static int minimumDistance(vector<int>& nums) {
        if (nums.size() < 3) return -1;

        map<int,pi> indices;
        int res = INF;
        PRIMLOOP(nums.size()) {
            if (!indices[nums[i]].first.has_value()) indices[nums[i]].first = i;
            else {
                if (!indices[nums[i]].second.has_value()) indices[nums[i]].second = i;
                else {
                    res = min(res, 2*(i - indices[nums[i]].first.value()));
                    indices[nums[i]].first = indices[nums[i]].second;
                    indices[nums[i]].second = i;
                }
            }
        }
        

        return (res != INF ? res : -1);
    }
};
