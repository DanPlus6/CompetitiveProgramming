// Yet Another Contest 2 P1 - Betting
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int T; scanf("%d",&T);
    for (ll A,B,C,D, _=0;_<T;++_) {
        scanf("%lld %lld %lld %lld",&A,&B,&C,&D);

        if (((B-A) * (D-C)) > (A*C)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
