// The Torture Chamber
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
// typedef vector<bool> vb;
#define endl '\n'
#define pb push_back


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    ll N,M; cin >> N >> M;
    int MMSQRT = ceil((double)sqrt(M));

    vl base_primes;
    bitset <20000001> sieve; 
    sieve.set();
    for (int i = 2; i <= MMSQRT; i++) {
        if (sieve[i]) {
            base_primes.pb(i);
            for (int j = i; j < MMSQRT; j+=i) {
                sieve[j] = false;
            }
        }
    }

    sieve.set();
    for (ll p: base_primes) {
        for (ll pp = (M/p)*p; pp >= N; pp -= p) {
            if (p == pp) break;
            if (sieve[M-pp]) sieve[M-pp] = false;
        }
    }

    int res = 0;
    for (int i = 1; i <= M-N; i++) if (sieve[i]) res++;
    cout << res << endl;


    // vi basePrimes;
    // {
    //     vb base_sieve(1e5+1,true);
    //     base_sieve[0] = base_sieve[1] = false;

    //     for (int i = 2; i*i <= MMSQRT; i++) {
    //         if (base_sieve[i]) {
    //             for (int j = i*i; j <= MMSQRT; j+=i) {
    //                 base_sieve[j] = false;
    //             }
    //         }
    //     }

    //     for (int i = 2; i <= MMSQRT; i++) {if (base_sieve[i]) basePrimes.pb(i);}
    // }

    // long long N,M; cin >> N >> M;
    // int size = M-N+1;
    // vb seg_check(size,true);

    // if (N == 1 && M >= 1) seg_check[1-N] = false;

    // for (int p: basePrimes) {
    //     ll pp = (ll)p * p;
    //     if (pp > M) break;

    //     ll start = max(pp, ((N+p-1)/p) * (ll)p);
    //     for (ll i = start; i <= M; i += p) seg_check[i-N] = false;
    // }

    // ll res = 0;
    // for (int i = 0; i < size; i++) if (seg_check[i]) res++;

    // cout << res << endl;

    return 0;
}
