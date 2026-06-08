// USACO 2026 Third Contest, Bronze Problem 1. Make All Distinct
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;
typedef vector<ll> vl;
#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define SECLOOP(M) for (int j = 0; j < M; j++)
#define ILOOP(arr) for (int &i: arr)
#define pb push_back

constexpr ll INFL = 0x3F3F3F3F3F3F3F3FLL;

int main() {
    #define int ll
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int N,K; cin >> N >> K;
        vl arr(N);
        PRIMLOOP(N) {cin >> arr[i];}

        int res = 0;
        if (K < 0) {
            K *= -1;
            PRIMLOOP(N) {arr[i] *= -1;}
        }

        vector<vl> mods(K);
        PRIMLOOP(N) {
            int mod = ((arr[i] % K) + K) % K;
            mods[mod].pb(arr[i]);
        }

        PRIMLOOP(K) {
            if (mods[i].empty()) continue;

            sort(ALL(mods[i]));

            int next = -INFL;
            ILOOP(mods[i]) {
                int tmp = max(i,next);
                res += (tmp - i) / K;
                next = tmp+K;
            }
        }

        cout << res << endl;
    }

    return 0;
}
