// BSSPC '21 J5 - James and the Euclid Test
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<bool> vb;
#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define LOOP(n) for (int _ = 0; _ < n; _++)

constexpr int MM = 3e5+5;

/* Orz bruce */
signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    vi primes;
    vi psa(MM); psa[0] = psa[1] = 0;
    vb sieve(MM, true); sieve[0] = sieve[1] = false;
    for (int i = 2; i < MM; i++) {
        if (sieve[i]) {
            primes.pb(i);
            for (int j = i*i; j < MM; j += i) sieve[j] = false;
        }
    }
    for (int i = 2; i < MM; i++) psa[i] = psa[i-1] + (sieve[i] ? i : 0);

    int Q; cin >> Q;
    int x,k;
    LOOP(Q) {
        cin >> x >> k;
        int kthIdx = distance(primes.begin(), lower_bound(ALL(primes), x)) + k - 1;
        cout << primes[kthIdx] << " " << psa[primes[kthIdx]] - psa[x-1] << endl;
    }

    return 0;
}
