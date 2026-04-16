// Common Divisor
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;
typedef vector<ll> vl;
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define FOUNDANS(res) {cout << res << endl; return 0;}


/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll A,B; int K; cin >> A >> B >> K;

    ll firstGcd = gcd(A,B);
    if (K == 1) FOUNDANS(firstGcd)

    vl factors; {
        ll sec;
        for (ll i = 1; i*i <= firstGcd; i++) {
            if (firstGcd % i == 0) {
                factors.pb(i);
                sec = firstGcd/i; 
                if (i != sec) factors.pb(sec);
            }
        }
    }

    sort(ALL(factors),greater<ll>());

    if (K > factors.size()) cout << -1;
    else cout << factors[K-1];

    return 0;
}
