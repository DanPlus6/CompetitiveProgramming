// SGS Programming Challenge P1 - XOR in Computer Class
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FILL(a, b) memset(a, b, sizeof(a))

constexpr int MM = 2e5+5;

int ct[32];
int N, A[MM], res = 0;
int main() {
    int N; scanf("%d",&N);
    for (int i=1;i<=N;i++) scanf("%d",&A[i]);
    
    for (int k = 29; k >= 0; --k) {
        ll unset = 0, set = 0;
        for (int i = 1; i <= N; ++i) {
            if (A[i] >> k & 1)
                set += 1ll * i * (N - i + 1);
            else
                unset += 1ll * i * (N - i + 1);
        }

        if (set > unset) res |= (1 << k);
    }

    printf("%d\n",res);

    return 0;
}
