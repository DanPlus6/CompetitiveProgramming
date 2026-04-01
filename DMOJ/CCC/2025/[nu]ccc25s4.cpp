// CCC '25 S4 - Floor is Lava
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef tuple<ll,ll,ll> tl;
typedef vector<ll> vl;
typedef vector<pl> vll;
typedef vector<tl> vtl;
typedef vector<bool> vb;
#define endl '\n'
#define pb push_back
#define FOUNDANS(res) {cout << res << endl; return 0;}


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N,M; cin >> N >> M;
    vector<vll> graph(N+1);
    vl edges(M+1);
    int u,v;
    for (int m = 0; m < M; m++) {
        cin >> u >> v;
        graph[u].pb({v,m});
        graph[v].pb({u,m});
        cin >> edges[m];
    }

    priority_queue<tl, vtl, greater<>> q; q.push({0,1,M});
    vb vis(M+1,false);
    vl best(M+1,LLONG_MAX);

    while (!q.empty()) {
        auto [w, u, i] = q.top(); q.pop();
        if (vis[i]) continue;
        if (u == N) {FOUNDANS(w)}

        vis[i] = true;
        for (auto [v, j]: graph[u]) {      
            if (vis[j]) continue;      
            ll nw = w + abs(edges[i] - edges[j]);
            if (nw < best[j]) {
                best[j] = nw;
                q.push({nw, v, j});
            }
        }
    }

    return 0;
}
