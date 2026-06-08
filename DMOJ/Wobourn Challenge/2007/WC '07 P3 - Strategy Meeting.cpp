// WC '07 P3 - Strategy Meeting
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FILL(a, b) memset(a, b, sizeof(a))
#define LOOP(n) for (int _ = 0; _ < n; _++)

constexpr int MOD = 13371337;

int n, adj[15][15], dp[15][1<<15];
int solve(int u, int mask) {
    if (u == n-1) return 1;

    int &res = dp[u][mask]; 
    if (res != -1) return res;

    res = 0;
    for (int v = 0; v < n; ++v) {
        if (adj[u][v] && !(mask >> v & 1))
            res = (res + solve(v, mask | 1 << v)) % MOD;
    }

    return res;
}

int main() {
    int T; scanf("%d",&T);
    LOOP (T) {
        scanf("%d",&n);
        FILL(dp, -1);

        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                scanf("%d", &adj[i][j]);
        
        printf("%d\n", solve(0, 1));
    }

    return 0;
}
