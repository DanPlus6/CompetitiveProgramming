// Gerrymandering Detector
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#define double long double
#define int long long
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef queue<int> qi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
#define endl '\n'
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define pb push_back


signed main() {
    int k, N; cin >> k >> N;

    string line; getline(cin, line);

    vi dist(N), purp(N), grey(N);
    vvi adj(N);
    PRIMLOOP(N) {
        getline(cin, line);
        if (line.empty()) {
            i--;
            continue;
        }
        
        stringstream ss(line);
        int u, d, p, g;
        ss >> u >> d >> p >> g;
        dist[u] = d;
        purp[u] = p;
        grey[u] = g;

        int v;
        while (ss >> v) {
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }

    int max_d = 0;
    for (int i = 0; i < N; ++i) {
        max_d = max(max_d, dist[i]);
    }

    for (int d = 1; d <= max_d; ++d) {
        vi nodes;
        for (int i = 0; i < N; ++i) {
            if (dist[i] == d) nodes.pb(i);
        }
        if (nodes.empty()) continue; 

        int start = nodes[0];
        vb vis(N, false);
        qi q;

        q.push(start);
        vis[start] = true;
        int count = 0;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            count++;

            for (int nxt : adj[curr]) {
                if (dist[nxt] == d && !vis[nxt]) {
                    vis[nxt] = true;
                    q.push(nxt);
                }
            }
        }

        if (count != (int)nodes.size()) {
            cout << "Invalid: " << d << " is not contiguous\n";
            return 0;
        }
    }

    if (max_d != k) {
        cout << "Invalid: wrong number of districts\n";
        return 0;
    }

    if (k > 0) {
        vi pop(k + 1, 0);
        PRIMLOOP(N) {
            pop[dist[i]] += purp[i] + grey[i];
        }

        int min_p = -1, max_p = -1, min_d = -1, max_d_idx = -1;
        
        for (int d = 1; d <= k; ++d) {
            if (min_p == -1 || pop[d] < min_p) {
                min_p = pop[d];
                min_d = d;
            }
            if (max_p == -1 || pop[d] > max_p) {
                max_p = pop[d];
                max_d_idx = d;
            }
        }

        if (max_p >= 2 * min_p) {
            cout << "Invalid: " << max_d_idx << " has at least twice as many people as " << min_d << "\n";
            return 0;
        }
    }

    set<pi> dist_edges;
    PRIMLOOP(N) {
        for (int j : adj[i]) {
            if (dist[i] != dist[j]) {
                int d1 = dist[i], d2 = dist[j];
                dist_edges.insert({min(d1, d2), max(d1, d2)});
            }
        }
    }

    vi p_votes(k + 1, 0), g_votes(k + 1, 0);
    PRIMLOOP(N) {
        p_votes[dist[i]] += purp[i];
        g_votes[dist[i]] += grey[i];
    }

    for (auto& edge : dist_edges) {
        int d1 = edge.first, d2 = edge.second;

        auto check_gerrymander = [&](int A, int B) {
            double totalA = p_votes[A] + g_votes[A], totalB = p_votes[B] + g_votes[B];
            if (totalA == 0 || totalB == 0) return false;

            double p_pctA = p_votes[A] / totalA, g_pctA = g_votes[A] / totalA, p_pctB = p_votes[B] / totalB, g_pctB = g_votes[B] / totalB;

            double eps = 1e-7;
            if (p_pctA > 0.50 + eps && p_pctA <= 0.60 + eps && g_pctB > 0.80 + eps) {
                cout << "Gerrymandered: party purple gerrymandered by cracking " << A << " and packing " << B << "\n";
                return true;
            }

            if (g_pctA > 0.50 + eps && g_pctA <= 0.60 + eps && p_pctB > 0.80 + eps) {
                cout << "Gerrymandered: party grey gerrymandered by cracking " << A << " and packing " << B << "\n";
                return true;
            }

            return false;
        };

        if (check_gerrymander(d1, d2)) return 0;
        if (check_gerrymander(d2, d1)) return 0;
    }

    cout << "This is a valid map\n";
    return 0;
}
