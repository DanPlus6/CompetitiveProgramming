// A Math Contest P5 - Good Arrays
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FILL(a, b) memset(a, b, sizeof(a))

constexpr int MM = 1e6+5;
constexpr int MOD = 1e9 + 7;

ll dp[MM];
ll solve(ll n) {
    if (dp[n]) return dp[n]%MOD;
    return dp[n] = (solve(n-1)+1 + solve(n-3)) % MOD;
}

int main() {
    FILL(dp, 0);
    int N; scanf("%d",&N);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 5;
    dp[5] = 8;
    dp[6] = 12;
    dp[7] = 18;

    printf("%lld\n", solve(N)%MOD);

    return 0;
}
