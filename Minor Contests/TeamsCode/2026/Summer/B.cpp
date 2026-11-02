/**
 * Author: DanPlus6 // David Fu
 * Problem Name: The K Is Lava!
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
typedef vector<int> vi;

signed main() {
    int T; scanf("%lld",&T);
    for (int N,K,Q; T--;) {
        scanf("%lld %lld %lld",&N,&K,&Q);

        vi a(N + 1), freq((int)2e5+1,0);
        ll sum = 0;
        for (int i = 1; i <= N; ++i) {
            scanf("%lld",&a[i]);
            ++freq[a[i]];
            sum += a[i];
        }

        int pos = N-freq[0], other = 0;
        if (!(K&1) && (K/2 <= 200000)) {
            int half = K/2;
            for (int i = 1; i <= 200000; i++) {
                if (i != half) other += freq[i];
            }
        }

        auto res = [&]() {
            if (K <= 200000 && freq[K] > 0) return false;
            if (sum == K) return false;
            if (!(K&1) && K/2 <= 200000 && pos >= 2 && !other) return false;
            return true;
        };

        for (int i,j;Q--;) {
            scanf("%lld %lld",&i,&j);

            int old = a[i];
            if (old > 0) pos--;
            sum -= old;
            --freq[old];

            if (!(K&1) && (K/2 <= 200000)) {
                if (old > 0 && old != K/2) --other;
            }

            a[i] = j; freq[j]++;
            sum += j;

            if (j > 0) pos++;
            if (!(K&1) && (K/2 <= 200000)) {
                if (j > 0 && j != K/2) ++other;
            }

            printf((res() ? "YES\n" : "NO\n"));
        }
    }

    return 0;
}
