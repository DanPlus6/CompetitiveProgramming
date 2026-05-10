// Arithmetic or Geometric - oly20practice119
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define LOOP(n) for (int _ = 0; _ < n; _++)

constexpr ll MOD = 1e9 + 7;

ll mpow(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

/* Orz bruce */
int main() {
    int T; scanf("%d", &T);
    ll a,b,c,k;
    LOOP(T) {
        scanf("%lld %lld %lld %lld", &a, &b, &c, &k);
        --k;

        if (ll dif = ((b%MOD) - (a%MOD) + MOD) % MOD; dif == ((c%MOD) - (b%MOD) + MOD) % MOD) {
            ll nMultD = (k % MOD) * dif % MOD;
            printf("%lld\n", (nMultD + (a%MOD) % MOD));
        } else {
            ll r = c/b;
            ll rPow = mpow(r,k,MOD);
            printf("%lld\n",(a%MOD) * rPow % MOD);
        }
    }

    return 0;
}
