// 1344. Angel Between Hands of a Clock
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        long double hourLoc = hour%12*5.0 + (minutes/60.0*5);
        
        long double case1 = abs(hourLoc - minutes) * 6;
        long double case2 = abs(360 - case1);

        cout << case1 << endl << case2 << endl;

        return (double)min(case1, case2);
    }
};
