// USACO 2026 Second Contest Bronze P3 - Purchasing Milk
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define endl '\n'
#define LOOP(n) for (int _ = 0; _ < n; _++)

/* Orz bruce and Orz benj qi */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N,Q; cin >> N >> Q;

    vi prices(N); {
        cin >> prices[0];
        int p;
        for (int i = 1; i < N; i++) {
            cin >> p;
            prices[i] = min(p, 2*prices[i-1]);
        }
    }

    LOOP(Q) {
        int q; cin >> q;

        ll mcost = LONG_LONG_MAX, ccost = 0;
        for (int i = min(30,N-1); i >= 0; i--) {
            int buckets = 1 << i;
            ll purchases = q / buckets;
            
            q -= purchases * buckets;
            ccost += purchases*prices[i];

            if (!q) mcost = min(mcost, ccost);
            else mcost = min(mcost, ccost + prices[i]);
        }

        cout << mcost << endl;
    }

    return 0;
}
