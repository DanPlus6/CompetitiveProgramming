// WC '18 Contest 2 S1 - Laser Grid
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define ILOOP(arr) for (int &i: arr)


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int START_X,START_Y; cin >> START_X >> START_Y;
    int NOVERT,NOHORIZ,NOCHIPS; cin >> NOVERT >> NOHORIZ >> NOCHIPS;

    vi vlazer(NOVERT); PRIMLOOP(NOVERT) {cin >> vlazer[i];}
    vi hlazer(NOHORIZ); PRIMLOOP(NOHORIZ) {cin >> hlazer[i];}
    vii chips(NOCHIPS); PRIMLOOP(NOCHIPS) {cin >> chips[i].first >> chips[i].second;}

    int up = INT_MAX, down = 0, left = 0, right = INT_MAX;
    ILOOP(hlazer) {
        if (i > START_Y) up = min(up,i);
        else if (i < START_Y) down = max(down,i);
    }
    ILOOP(vlazer) {
        if (i > START_X) right = min(right,i);
        else if (i < START_X) left = max(left,i);
    }

    for (auto &[x,y]: chips) {
        if (x >= left && x <= right && y >= down && y <= up) cout << "Y\n";
        else cout << "N\n";
    }

    return 0;
}
