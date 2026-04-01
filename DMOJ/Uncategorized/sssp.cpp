// Single Source Shortest Path
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define ILOOP(n) for (int i = 0; i < n; i++)
#define FOUNDANS(res) {cout << res << endl; continue;}
#define pb push_back


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N,M; cin >> N >> M;
    vector<vii> adj(N+1);
    int u,v,w;
    ILOOP(M) {
        cin >> u >> v >> w;
        adj[u].pb({w,v});
        adj[v].pb({w,u});
    }

    // orz bruce & my goat do_ur_homwork
    priority_queue<pi, vii, greater<pi>> q; q.push({0,1});
    vector<bool> vis(N+1,false); vis[1] = 0;
    vi weight_node(N+1,INT_MAX); weight_node[1] = 0;

    while (!q.empty()) {
        int u = q.top().second; /*, w = q.top().first;*/ q.pop();
        if (vis[u]) continue;

        vis[u] = true;
        for (pi next: adj[u]) {
            int v = next.second, nw = next.first;
            if (nw + weight_node[u] < weight_node[v]) {
                weight_node[v] = nw + weight_node[u];
                q.push({weight_node[v],v});
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << (vis[i]? weight_node[i] : -1) << endl;
    }



    // cout << 0 << endl;
    // vector<int> node_weight(N+1,INT_MAX);
    // node_weight[1] = 0;
    // for (int i = 2; i <= N; i++) {
    //     if (adj[i].empty()) FOUNDANS(-1)
    //     priority_queue<pi, vii, greater<pi>> q;
    //     set<int> vis = {1};
    //     q.push({1,0});

    //     int res = node_weight[i];
    //     while (!q.empty()) {
    //         pi cur = q.top(); q.pop();
    //         int cnode = cur.first, cweight = cur.second;

    //         if (vis.count(cnode)) continue;
    //         for (pi adjnode: adj[cnode]) {
    //             int toNode = adjnode.first, weight = adjnode.second;
    //             if (toNode != i) {
    //                 node_weight[toNode] = min(node_weight[toNode], cweight + weight);
    //                 q.push({toNode,cweight+weight});
    //                 vis.emplace(toNode);
    //             } else {
    //                 node_weight[i] = min(node_weight[i], cweight + weight);
    //                 res = min(res, cweight + weight);
    //             }
    //         }
    //     }
        
    //     if (res == INT_MAX) cout << -1 << endl;
    //     else cout << res << endl;
    // }

    return 0;
}
