// CCC '04 J2 - Terms of Office
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/* Orz bruce */
int main() {
    ll X,Y; scanf("%lld\n%lld",&X,&Y);
    printf("All positions change in year %lld\n",X);

    for (ll i = 1; i <= Y-X; i++) {
        if (i%2 == 0 && i%3 == 0 && i%4 == 0 && i%5 == 0) {
            printf("All positions change in year %lld\n",X+i);
        }
    }

    return 0;
}
