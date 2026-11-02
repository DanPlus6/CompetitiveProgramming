// DMOPC '22 Contest 5 P2 - Absolutely Even
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;
#define int ll

signed main() {
    int N; scanf("%lld",&N);
    
    ll K = N*(N+1ll)/4ll;
    
    for (int a,i=0;i<N;++i) {
        a = N-i;
        if (a < K) {
            printf("%lld", -N);
            K -= a;
        } else if (K) {
            printf("%lld", -K);
            K = 0;
        } else {
            printf("1");
        }
        printf("%c", (i==N-1 ? '\n' : ' '));
    }

    return 0;
}
