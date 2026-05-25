// DMOPC '18 Contest 4 P3 - Dr. Henri and Ionization
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

constexpr int INF = 0x3F3F3F3F;
constexpr ll INFL = 0x3F3F3F3F3F3F3F3FLL;


int main() {
    int N; scanf("%d",&N);

    vl a(N), b(N);
    for (int i=0;i<N;i++) scanf("%lld",&a[i]);
    for (int i=0;i<N;i++) scanf("%lld",&b[i]);

    vl dp(2, INFL); dp[0] = 0;
    for (int i = 0; i < N; i++) {
        vl ndp(2, INFL);

        if (dp[0] < INFL) ndp[0] = min(ndp[0], dp[0] + a[i]);
        if (dp[1] < INFL) ndp[1] = min(ndp[1], dp[1] + a[i]);

        if (dp[0] < INFL) ndp[1] = min(ndp[1], dp[0] + b[i]);
        if (dp[1] < INFL) ndp[0] = min(ndp[0], dp[1] + b[i]);

        dp = ndp;
    }
    
    printf("%lld\n",dp[0]);

    return 0;
}
