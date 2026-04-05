// USACO 2025 February Bronze P1 - Reflection
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
#define endl '\n'
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define SECLOOP(M) for (int j = 0; j < M; j++)


/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N,U; cin >> N >> U;
    vector<string> grid(N);
    PRIMLOOP(N) cin >> grid[i];

    vvi rep(N/2,vi(N/2));
    int res = 0;
    auto apply = [&](int x, int y, int state) {
        if (grid[x][y] == '.') return;
        
        x = min(x,N-1-x);
        y = min(y, N-1-y);

        res -= min(rep[x][y], 4-rep[x][y]);
        rep[x][y] += state;
        res += min(rep[x][y], 4-rep[x][y]);
    };

    PRIMLOOP(N) SECLOOP(N) apply(i,j,1);

    cout << res << endl;
    int x,y;
    LOOP(U) {
        cin >> x >> y; x--; y--;

        apply(x,y,-1);
        grid[x][y] = (grid[x][y] == '#' ? '.' : '#');
        apply(x,y,1);

        cout << res << endl;
    }

    return 0;
}
