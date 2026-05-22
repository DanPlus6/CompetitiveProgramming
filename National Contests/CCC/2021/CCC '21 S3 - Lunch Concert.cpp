// CCC '21 S3 - Lunch Concert
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

int N;
vl P, W, D;
ll f(int x) {
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        if (x < P[i]-D[i]) {
            sum += W[i] * (P[i]-D[i]-x);
        } else if (x > P[i]+D[i]) {
            sum += W[i] * (x-P[i]-D[i]);
        }
    }
    return sum;
}

signed main() {
    scanf("%d",&N);

    ll lo = LLONG_MAX, hi = 0;
    P.resize(N);
    W.resize(N);
    D.resize(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld %lld %lld",&P[i], &W[i], &D[i]);
        lo = min(P[i] - D[i], lo);
        hi = max(P[i] + D[i], hi);
    }

    ll mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (f(mid) <= f(mid+1)) hi = mid;
        else lo = mid + 1;
    }

    printf("%lld\n",f(lo));

    return 0;
}
