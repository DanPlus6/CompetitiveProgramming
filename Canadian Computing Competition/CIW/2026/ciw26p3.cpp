// CIW '26 P3 - Gumball Machine
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#define int long long
#define endl '\n'
#define FOUNDANS(res) {cout << res << endl; return 0;}

/* Orz bruce */
signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;

    if (!N) FOUNDANS(0);

    int res = INT_MAX;
    bool solvable = false;
    int b;
    for (int a = 1; a * a <= N; a++) {
        if (N % a == 0) {
            solvable = true;
            b = N/a;
            res = min(res,a+b);
        }
    }

    if (!solvable) {
        cout << "-1\n";
    } else {
        cout << res << endl;
    }

    return 0;
}
