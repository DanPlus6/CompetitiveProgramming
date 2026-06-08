// USACO 2022 January Silver P1 - Searching for Soulmates
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define LOOP(n) for (int _ = 0; _ < n; _++)

ll minOps(ll X, ll Y) {
    if (X==Y) return 0ll;

    ll res = 1e18, steps = 0;
    while (Y >= 1) {
        if (X > Y) {
            if (X & 1) { ++X; ++steps; }
            X /= 2;
            ++steps;
        } else if (X < Y) {
            res = min(res, steps + Y - X);
            if (Y & 1) { --Y; ++steps; }
            Y /= 2;
            ++steps;
        } else {
            res = min(res, steps);
            return res;
        }
    }

    return -1ll;
}

int main() {
    int N; scanf("%d",&N);
    ll X,Y;
    LOOP(N) {
        scanf("%lld %lld",&X,&Y);

        printf("%lld\n", minOps(X,Y));
    }

    return 0;
}
