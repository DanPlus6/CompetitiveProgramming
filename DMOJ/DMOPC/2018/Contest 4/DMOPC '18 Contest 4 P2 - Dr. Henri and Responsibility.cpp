// DMOPC '18 Contest 4 P2 - Dr. Henri and Responsibility
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#define PRIMLOOP(N) for (int i = 0; i < N; i++)


static bitset<1000005> dp;
int main() {
    int N; scanf("%d", &N);

    int total = 0;
    dp[0] = 1;
    PRIMLOOP(N) {
        int val; scanf("%d", &val);
        total += val;
        dp |= (dp << val);
    }

    int res = total;
    for (int i = 0; i <= total; i++) {
        if (dp[i]) {
            int diff = total - 2 * i;
            if (diff < 0) {
                diff = -diff;
            }
            res = min(res, diff);
        }
    }

    printf("%d\n", res);

    return 0;
}
