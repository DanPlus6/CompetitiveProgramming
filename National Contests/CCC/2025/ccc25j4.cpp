// CCC '25 J4 - Sunny Days
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;

    vector<char> S(N);
    int l = 0, rain = 0; bool allsunny = true;
    int res = 0;
    for (int r = 0; r < N; r++) {
        cin >> S[r];
        if (S[r] == 'P') {rain++; allsunny = false;}

        while (rain > 1) {              // well well well, this looks familiar doesn't it danplus6? sure reminds you of UTS Open '18 P3 - Restaurants, Lights On, and ICPC PACNW 2016 C - Cameras
            if (S[l] == 'P') rain--;    // leave the rain behind
            l++;                        // slide left end fwd
        }                               // 23:32 UTC-5

        res = max(res,(r-l+1));
    }

    if (allsunny) {cout << N-1 << endl; return 0;}
    cout << res << endl;

    return 0;
}
