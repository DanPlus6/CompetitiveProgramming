// The Bouldering Problem
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#define double long double
typedef pair<double, double> pf;
typedef vector<int> vi;
typedef vector<pf> vff;
typedef vector<bool> vb;
#define endl '\n'
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define SECLOOP(M, start) for (int j = start; j < M; j++)
#define pb push_back

constexpr int INF = 0x3F3F3F3F;


double getdist(pf &A, pf &B) {
    double dx = A.first-B.first;
    double dy = A.second-B.second;
    return (double)sqrt(dx*dx + dy*dy);
}

/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    double ws,js; cin >> ws >> js;
    int N; cin >> N;

    vff holds(N); PRIMLOOP(N) cin >> holds[i].first >> holds[i].second;


    vi dist(N,INF);
    vb vis(N,false);
    deque<int> q;

    dist[0] = 0; q.push_front(0);
    while (!q.empty()) {
        int u = q.front(); q.pop_front();

        if (vis[u]) continue;
        vis[u] = true;

        PRIMLOOP(N) {
            if (i == u) continue;

            int cost;
            double tmpdist = getdist(holds[u],holds[i]);
            if (tmpdist <= ws) cost = 0;
            else if (tmpdist <= js) cost = 1;
            else continue;

            int ncost = dist[u] + cost;
            if (ncost < dist[i]) {
                dist[i] = ncost;
                if (!cost) q.push_front(i);
                else q.pb(i);
            }
        }
    }

    if (dist[N-1] == INF) cout << "-1\n";
    else cout << dist[N-1] << endl;

    return 0;
}
