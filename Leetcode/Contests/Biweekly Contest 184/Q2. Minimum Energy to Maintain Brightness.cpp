// Q2. Minimum Energy to Maintain Brightness.cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int ,int, int> ti;
typedef pair<pi, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pl;
typedef tuple<ll,ll,ll> tl;
typedef pair<ll,pl> pll;
typedef vector<int> vi;
typedef unordered_set<int> si;
typedef set<ll> sl;
typedef queue<int> qi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<pi> vii;
typedef vector<ti> vti;
typedef vector<pl> vll;
typedef vector<tl> vtl;
typedef vector<bool> vb;
#define FILL(a, b) memset(a, b, sizeof(a))
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define pb push_back

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

        // vi bulbs(N,0);
        // for (vi chunk : intervals) { ++bulbs[chunk[0]-1]; --bulbs[chunk[1]-1]; }

        // ll needed = 0, dist = 0;
        // for (ll run = 0, tmpdist = 0, i=0;i<N;i++) {
        //     ++tmpdist;
        //     run += bulbs[i];

        //     if (!run) { 
        //         dist += tmpdist;
        //         needed += ceil(tmpdist/3); 
        //         tmpdist = 0;
        //     }
        // }

        // return needed * dist;
    }
};
