// C. Village Guilds
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
typedef vector<int> vi;
#define endl '\n'

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    for (int N, res; T--;) {
        cin >> N;
        vi P(N+1,0);
        for (int i=2;i<=N;++i) cin >> P[i];

        vi d(N+1,0); d[1] = 1;
        vi md(N+1,0); md[1] = 1;
        vi mx1(N+1,0), mx2(N+1,0);
        for (int i = 2; i <= N; ++i) {
            d[i] = d[P[i]] + 1;
            md[i] = d[i];
        }

        for (int u, i = N; i >= 2; --i) {
            u = P[i];
            if (md[i] > mx1[u]) {
                mx2[u] = mx1[u]; mx1[u] = md[i]; 
            } else if (md[i] > mx2[u]) {
                mx2[u] = md[i];
            }

            md[u] = max(md[u], md[i]);
        }

        res = N;
        for (int i = 1; i <= N; ++i) {
            if (mx2[i] > d[i]) res += (mx2[i] - d[i]);
        }

        cout << res << endl;
    }

    return 0;
}
