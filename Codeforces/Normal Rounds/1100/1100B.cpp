// B. Absolute Cinema
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
typedef vector<ll> vl;
#define LOOP(n) for (int _ = 0; _ < n; _++)

signed main() {
    ll T; scanf("%lld",&T);
    LOOP(T) {
        ll n; scanf("%lld",&n);
        vl a(n); for (int i=0;i<n;i++) scanf("%lld",&a[i]);
        vl b(n); for (int i=0;i<n;i++) scanf("%lld",&b[i]);

        ll total = 0; {
            for (int i=0;i<n;i++) total += a[i];
            for (int i=0;i<n;i++) total += b[i];
        }

        ll minsum = 0, maxx = 0; {
            int cur;
            for (int i = 0; i < n; i++) {
                cur = min(a[i], b[i]);
                minsum += cur;
                maxx = max(cur, maxx);
            }
        }

        printf("%lld\n", total-minsum+maxx);
    }

    return 0;
}
