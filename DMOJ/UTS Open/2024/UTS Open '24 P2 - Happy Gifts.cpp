// UTS Open '24 P2 - Happy Gifts
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define ALL(x) x.begin(), x.end()
#define pb push_back


int main() {
    int N,K; scanf("%d %d",&N,&K);

    vl psap = {0ll}, psan = {0ll}; {
        vi pos, neg;
        for (int g, i=0;i<N;++i) {
            scanf("%d",&g);
            if (g < 0) neg.pb(-g);
            else if (g > 0) pos.pb(g);
        }

        sort(ALL(pos), greater<>());
        sort(ALL(neg), greater<>());

        for (int &i: pos) psap.pb(i + psap.back());
        for (int &i: neg) psan.pb(i + psan.back());
    }

    ll res = 0;
    for (int req, i = 0; i < psan.size(); ++i) {
        if (req = i*2; req > K) break;
        res = max(
            res, 
            psan[i] + psap[min(psap.size()-1, (size_t)K-req)]
        );
    }

    printf("%lld\n",res);

    return 0;
}
