// D. Alternating Path
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef vector<int> vi;
typedef queue<int> qi;
typedef vector<vi> vvi;
#define endl '\n'
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define PRIMLOOP(N) for (int i = 0; i < N; i++)


/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    LOOP(T) {
        int n, m; cin >> n >> m;
        
        vvi adj(n + 1);
        PRIMLOOP(m) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vi color(n + 1, -1);
        int res = 0;        
        for (int i = 1; i <= n; i++) {
            if (color[i] != -1) continue;
            
            qi q; q.push(i);
            color[i] = 0;
            int cnt[2] = {0, 0};
            bool bi = true;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                cnt[color[u]]++;
                
                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if (color[v] == color[u]) bi = false;
                }
            }
            
            if (bi) res += max(cnt[0], cnt[1]);
        }
        
        cout << res << endl;
    }

    return 0;
}
