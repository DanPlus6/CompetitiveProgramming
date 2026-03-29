// UCC Coding Competition '20 P4 - Bubble Tea
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;
typedef vector<ll> vl;
#define endl '\n'
#define PRIMLOOP(N) for (int i = 0; i < N; i++)

constexpr ll INFL = 0x3F3F3F3F3F3F3F3FLL;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    vl prices(N);
    PRIMLOOP(N) cin >> prices[i];

    vl dp(N + 1, INFL);
    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        dp[i] = min(dp[i], dp[i-1] + prices[i-1]);

        if (i >= 2) {
            ll a = prices[i-2], b = prices[i-1];
            dp[i] = min(dp[i], dp[i-2] + a + b - min(a, b) / 4);
        }

        if (i >= 3) {
            ll a = prices[i-3], b = prices[i-2], c = prices[i-1];
            dp[i] = min(dp[i], dp[i-3] + a + b + c - min({a, b, c}) / 2);
        }
    }

    cout << dp[N] << endl;

    return 0;
}
