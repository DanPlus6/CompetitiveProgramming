// B. Mickey Mouse Constructive
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;
#define endl '\n'
#define LOOP(n) for (int _ = 0; _ < n; _++)

constexpr int MOD = 676767677;


int countDivisors(int N) {
    if (!N) return 1;

    int cnt = 0;
    for (int i = 1; (ll)(i * i) <= N; i++) {
        if (N % i == 0) {
            cnt++;
            if (N/i != i) cnt++;
        }
    }

    return cnt;
}


/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    LOOP (T) {
        int x, y; cin >> x >> y;

        int S = abs(x - y), res = ((x == y) ? 1 : countDivisors(S));

        cout << res % MOD << endl;

        if (x >= y) {
            for (int i = 0; i < x; i++) cout << "1 ";
            for (int i = 0; i < y; i++) cout << "-1 ";
        } else {
            for (int i = 0; i < y; i++) cout << "-1 ";
            for (int i = 0; i < x; i++) cout << "1 ";
        }
        cout << endl;
    }

    return 0;
}

