// C. Spring
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;
#define endl '\n'
#define LOOP(n) for (int _ = 0; _ < n; _++)

constexpr int MM = 1e5+5;
constexpr int INF = 0x3F3F3F3F;
constexpr ll INFL = 0x3F3F3F3F3F3F3F3FLL;
constexpr int MOD = 1e9 + 7;

#define int long long

ll gcd(const int m, const int n) {
    if (n <= 0) return m;
    return gcd(n, m%n);
}

ll M;
ll lcm(const int m, const int n) {
    if (!m || !n) return 0;

    __int128_t res = (__int128_t)m / gcd(m,n) * n;
    if (res > M) return res+1;
    else return (ll)res;

    // return abs(m*n) / gcd(m,n);
    // return (m / gcd(m,n)) * n;
}

/* Orz bruce */
signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    LOOP(T) {
        int a,b,c;
        cin >> a >> b >> c >> M;

        ll lab = lcm(a, b);
        ll lac = lcm(a, c);
        ll lbc = lcm(b, c);
        ll labc = lcm(lab, c);

        ll nABC = M / labc;

        ll nAB_only = (M / lab) - nABC;
        ll nAC_only = (M / lac) - nABC;
        ll nBC_only = (M / lbc) - nABC;

        ll nA_only = (M / a) - (M / lab) - (M / lac) + nABC;
        ll nB_only = (M / b) - (M / lab) - (M / lbc) + nABC;
        ll nC_only = (M / c) - (M / lac) - (M / lbc) + nABC;

        ll alice = (nA_only * 6) + (nAB_only * 3) + (nAC_only * 3) + (nABC * 2);
        ll bob = (nB_only * 6) + (nAB_only * 3) + (nBC_only * 3) + (nABC * 2);
        ll carol = (nC_only * 6) + (nAC_only * 3) + (nBC_only * 3) + (nABC * 2);

        cout << alice << " " << bob << " " << carol << "\n";

    }

    return 0;
}
