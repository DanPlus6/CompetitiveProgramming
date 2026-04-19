// VM7WC '16 #1 Bronze - A New Prime Factorization
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;

/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll Y; scanf("%lld",&Y);
    ll div = 2;
    while (Y != 1) {
        if (Y % div) { div++; continue; }
        else {
            printf("%lld\n",div);
            Y /= div;        
        }
    }

    return 0;
}
