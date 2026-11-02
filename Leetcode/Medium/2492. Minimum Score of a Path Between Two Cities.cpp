// 2492. Minimum Score of a Path Between Two Cities
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vii;
typedef vector<bool> vb;
typedef queue<int> qi;
#define pb push_back

class Solution {
public:
    int minScore(int n, vvi &roads) {
        unordered_map<int,vii> adj;
        for (int u,v,w, i=0;i<roads.size();++i) {
            u = roads[i][0]; v = roads[i][1]; w = roads[i][2];
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }

        vb vis(n+1,false); vis[1] = true;
        qi q; q.push(1);
        int res = INT_MAX;
        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (auto [v,w]: adj[u]) {
                res = min(res, w);
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        return res;
    }
};
