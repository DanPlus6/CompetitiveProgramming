// DMOPC '15 Contest 2 P4 - Personal Assistant
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef tuple<ll ,ll, ll> tl;
typedef vector<tl> vtl;
#define FILL(a, b) memset(a, b, sizeof(a))
#define ALL(x) x.begin(), x.end()

int N;
vtl anime; vl best;
ll H(int i) {
    int l = 0, r = N-1, mid, res = -1;
    while (l <= r) {
        mid = l + (r-l) / 2;

        if (get<1>(anime[mid]) <= get<0>(anime[i])) {
            res = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    return (res != -1)? res+1 : 0;
}

int main() {
    scanf("%d",&N);
    anime.resize(N); best.resize(N+5);
    for (int s,f,h, i=0;i<N;++i) {
        scanf("%d %d %d",&s,&f,&h);
        anime[i] = {s,f,h};
    }
    sort(ALL(anime), [](tl a,tl b){return get<1>(a) < get<1>(b);});

    best[0] = 0;
    for (int i = 1; i <= N; ++i) {
        best[i] = max(
            best[i-1],
            get<2>(anime[i-1]) + best[H(i-1)]
        );
    }
    printf("%lld\n",best[N]);

    return 0;
}
