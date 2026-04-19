// Sum of Primes 2
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
#define LOOP(n) for (int _ = 0; _ < n; _++)

constexpr int MM = 1e5+5;


/* Orz bruce */
signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    vi psa(MM+1); {
        bitset<MM+1> sieve; sieve.set();
        sieve.reset(0); sieve.reset(1);
        for (int i = 2; i*i <= MM; i++) {
            if (sieve[i]) {
                for (int j = i*i; j <= MM; j += i) sieve.reset(j);
            }
        }

        psa[0] = 0;
        psa[1] = 0;
        for (int i = 2; i <= MM; i++) psa[i] = psa[i-1] + (sieve[i] ? (ll)i : 0ll);
    }

    ll Q; scanf("%lld",&Q);
    ll A,B;
    LOOP(Q) {
        scanf("%lld %lld",&A,&B);
        printf("%lld\n", psa[B]-psa[A-1]);
    }

    return 0;
}
