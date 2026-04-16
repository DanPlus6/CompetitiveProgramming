// C1. Equal Multisets (Easy Version)
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef vector<int> vi;
typedef set<int> si;
#define endl '\n'
#define LOOP(N) for (int _ = 0; _ < N; _++)


/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    LOOP(T) {
        int N, K; cin >> N >> K;

        vi a(N+1), b(N+1);
        for (int i = 1; i <= N; i++) cin >> a[i];
        for (int i = 1; i <= N; i++) cin >> b[i];

        bool res = true;
        if (K == N) {
            si seen;
            for (int i = 1; i <= N && res; i++) {
                if (b[i] != -1) {
                    if (seen.count(b[i])) res = false;
                    else seen.emplace(b[i]);
                }
            }
        } else {
            for (int i = 1; i <= N-K && res; i++)
                if (b[i] != -1 && b[i] != a[i]) res = false;
            for (int i = K+1; i <= N && res; i++)
                if (b[i] != -1 && b[i] != a[i]) res = false;


            if (res && N-K+1 <= K) {
                set<int> allowed;
                for (int i = N-K+1; i <= K; i++) allowed.emplace(a[i]);

                set<int> used;
                for (int i = N-K+1; i <= K && res; i++) {
                    if (b[i] != -1) {
                        if (!allowed.count(b[i]) || used.count(b[i])) res = false;
                        else used.emplace(b[i]);
                    }
                }
            }
        }

        cout << (res ? "YES\n" : "NO\n");
    }
    return 0;
}
