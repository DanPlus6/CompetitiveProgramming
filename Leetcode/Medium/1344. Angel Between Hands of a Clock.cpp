// 1344. Angel Between Hands of a Clock
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourLoc = hour%12*5 + (minutes/60.0*5);

        return min(
            abs(hourLoc - minutes),
            abs(60-minutes + hourLoc)
        ) * 6;
    }
};
