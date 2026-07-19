/**
 * Author: DanPlus6 // David Fu
 * Problem Name: Q2. Minimum Energy to Maintain Brightness.cpp
 * Problem Code: minimum-energy-to-maintain-brightness
 * Problem URL:  https://leetcode.com/problems/minimum-energy-to-maintain-brightness/description
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define ALL(x) x.begin(), x.end()

class Solution {
public:
    ll minEnergy(int N, int B, vvi& iv) {
        ll minNeeded = ((ll)B + 2) / 3;

        sort(ALL(iv));
        ll time = 0, s = -1, e = -1;
        for (int i = 0; i < iv.size(); i++) {
            if (iv[i][0] > e) {
                if (e != -1) time += (e - s + 1);
                s = iv[i][0];
                e = iv[i][1];
            }
            else e = max(e, (ll)iv[i][1]);
        }

        if (e != -1) time += (e - s + 1);

        return minNeeded * time;
    }
};
