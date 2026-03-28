// C2. Equal Multisets (Hard Version)
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef vector<int> vi;
typedef vector<bool> vb;
#define endl '\n'
#define LOOP(n) for (int _ = 0; _ < n; _++)

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    LOOP(T) {
        int N, K; cin >> N >> K;
        vi a(N); for (int i = 0; i < N; i++) cin >> a[i];
        vi b(N); for (int i = 0; i < N; i++) cin >> b[i];

        vi fv(K, -1);
        vb fa(K, false);

        bool res = true;

        for (int r = 0; r < K; r++) {
            bool ca = true;
            for (int i = r + K; i < N; i += K) {
                if (a[i] != a[i - K]) {
                    ca = false;
                    break;
                }
            }

            if (!ca) {
                fa[r] = true;
                for (int i = r; i < N; i += K) {
                    if (b[i] != -1 && b[i] != a[i]) {
                        cout << "NO\n";
                        res = false;
                        break;
                    }
                }
                if (!res) break;
            } else {
                int cb = -1;
                for (int i = r; i < N; i += K) {
                    if (b[i] != -1) {
                        if (cb != -1 && b[i] != cb) {
                            cout << "NO\n";
                            res = false;
                            break;
                        }
                        cb = b[i];
                    }
                }
                if (!res) break;
                fv[r] = cb;
            }
        }

        if (!res) continue;

        map<int, int> ct;
        for (int i = 0; i < K; i++) {
            ct[a[i]]++;
        }

        for (int i = 0; i < K; i++) {
            int v = -1;
            if (fa[i]) {
                v = a[i];
            } else if (fv[i] != -1) {
                v = fv[i];
            }

            if (v != -1) {
                if (ct[v] <= 0) {
                    cout << "NO\n";
                    res = false;
                    break;
                }
                ct[v]--;
            }
        }

        if (!res) continue;

        cout << "YES\n";
    }

    return 0;
}
