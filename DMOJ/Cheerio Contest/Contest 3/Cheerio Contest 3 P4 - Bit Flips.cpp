// Cheerio Contest 3 P4 - Bit Flips
#include <bits/stdc++.h>
using namespace std;

#define FILL(a, b) memset(a, b, sizeof(a))


int N, psa[30][102], dp[30][102][102];

int solve(int K, int L, int R) {
    if (K < 0 || L >= R) return 0;
    if (dp[K][L][R] != -1) return dp[K][L][R];

    int &res = dp[K][L][R];
    res = INT_MAX;

    for (int p = L-1; p <= R; p++) {
        int ones = (p < L ? 0 : psa[K][p] - psa[K][L-1]), zeroes = (p == R ? 0 : (R-p)-(psa[K][R] - psa[K][p]));
        res = min(res, ones + zeroes + solve(K-1, L, p) + solve(K-1, p+1, R));
    }

    return res;
}

int main() {
    int N; scanf("%d",&N);
    FILL(dp, -1);

    for (int i = 1, x; i <= N; i++) {
        scanf("%d",&x);
        for (int j = 0; j < 30; j++) {
            psa[j][i] = psa[j][i-1] + (x%2);
            x /= 2;
        }
    }

    printf("%d\n",solve(29,1,N));

    return 0;
}
