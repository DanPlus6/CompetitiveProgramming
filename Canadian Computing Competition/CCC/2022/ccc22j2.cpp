// CCC '22 J2 - Fergusonball Ratings
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#define LOOP(n) for (int _ = 0; _ < n; _++)


/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    int res = 0; bool gold = true; {
        int p,s;
        LOOP(N) {
            cin >> p >> s;
            if (p*5-s*3 > 40) res++;
            else gold = false;
        }
    }

    cout << res;
    if (gold) cout << "+";

    return 0;
}
