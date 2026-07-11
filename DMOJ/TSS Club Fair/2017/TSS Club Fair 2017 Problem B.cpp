// TSS Club Fair 2017 Problem B
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;
#define int ll
typedef vector<int> vi;
#define ALL(x) x.begin(), x.end()

signed main() {
    int N,Q; scanf("%lld %lld",&N,&Q);
    vi H(N);
    for (int x,y,i=0;i<N;++i) {
        scanf("%lld %lld",&x,&y);
        H[i] = x*x + y*y;
    }
    sort(ALL(H));

    for (int r,_=0;_<Q;++_) {
        scanf("%lld",&r);
        r *= r;

        auto it = upper_bound(ALL(H),r);
        if (it != H.end()) {
            printf("%lld\n", (int)(it-H.begin()));
        } else {
            printf("%lld\n",N);
        }
    }

    return 0;
}
