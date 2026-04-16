// D. AND-array
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define LOOP(N) for (int _ = 0; _ < N; _++)

constexpr ll MM = 1e5+5;
constexpr ll MOD = 1e9 + 7;

ll fact[MM], inv_fact[MM];
ll power(ll a, ll b, ll mod) {
    ll res = 1; a %= mod;
    while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;}
    return res;
}

void precomp() {
    fact[0] = 1;
    for (int i = 1; i < MM; i++) {
        fact[i] = fact[i-1]*i % MOD;
    }
    inv_fact[MM-1] = power(fact[MM-1], MOD-2, MOD);
    for (int i = MM-2; i >= 0; i--) {
        inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
    }
}

ll C(int N, int k) {
    if (k < 0 || k > N || N < 0) return 0;
    return fact[N] * inv_fact[k] % MOD * inv_fact[N-k] % MOD;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    precomp();

    int T; cin >> T;
    LOOP(T) {
        int N; cin >> N;
        vl b(N+1); for (int i = 1; i <= N; i++) cin >> b[i];

        vector<pair<ll, int>> det;
        int mp[29] = {};
        for (int i = N; i >= 1; i--) {
            ll rem = b[i];
            for (auto& [mask, m] : det) {rem = (rem - mask * C(m, i) % MOD + MOD) % MOD;}
            if (rem > 0) {
                det.push_back({rem, i});
                for (int p = 0; p < 29; p++) {if ((rem >> p) & 1) mp[p] = i;}
            }
        }

        vl a(N+1, 0);
        for (int p = 0; p < 29; p++) {for (int j = 1; j <= mp[p]; j++) {a[j] |= (1LL << p);}}

        for (int i = 1; i <= N; i++) {
            cout << a[i];
            if (i == N) cout << endl;
            else cout << " ";
        }
    }
    return 0;
}

