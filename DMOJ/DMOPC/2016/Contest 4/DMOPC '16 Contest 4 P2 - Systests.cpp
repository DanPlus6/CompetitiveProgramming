// DMOPC '16 Contest 4 P2 - Systests
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;
typedef vector<int> vi;
#define ALL(x) x.begin(), x.end()

int main() {
    int N; scanf("%d",&N);
    vi Fi(N), Ei(N), Pi(N);
    int res = 0;
    for (int i=0;i<N;++i) {
        scanf("%d %d %d", &Fi[i],&Ei[i],&Pi[i]);
        res += Pi[i];
    }
    
    int F; scanf("%d",&F);
    if (F == 0) { printf("%d\n",res); return 0; }

    vi fail(F);
    for (int i=0;i<F;++i)
        scanf("%d",&fail[i]);
    sort(ALL(fail));

    for (int i=0;i<N;++i) {
        if (upper_bound(ALL(fail),Ei[i]) - lower_bound(ALL(fail),Fi[i]))
            res -= Pi[i];
    }

    printf("%d\n",res);

    return 0;
}
