// 3633. Earliest Finish Time for Land and Water Rides I
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int land = INT_MAX, water = land, res = land;

        for (int i = 0; i < landDuration.size(); i++) {
            land = min(land, landStartTime[i] + landDuration[i]);
        }

        for (int i = 0; i < waterDuration.size(); i++) {
            water = min(water, waterStartTime[i] + waterDuration[i]);
            res = min(res, max(land, waterStartTime[i]) + waterDuration[i]);
        }

        for (int i = 0; i < landDuration.size(); i++) {
            res = min(res, max(water, landStartTime[i]) + landDuration[i]);
        }

        return res;
    }
};
