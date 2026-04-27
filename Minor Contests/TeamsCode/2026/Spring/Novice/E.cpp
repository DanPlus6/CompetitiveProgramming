// Evil Problemsetters 2
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vii;
typedef set<int> si;
typedef queue<int> qi;
#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define vc vector

constexpr int MM = 1e5+5;
constexpr int INF = 0x3F3F3F3F;
constexpr ll INFL = 0x3F3F3F3F3F3F3F3FLL;
constexpr int MOD = 1e9 + 7;


/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N,E,L; cin >> N >> E >> L;
    vii edges(E); PRIMLOOP(E) cin >> edges[i].first >> edges[i].second;

    vi col(N+1); for (int i = 1; i <= N; i++) cin >> col[i];

    vc<si> cadj(L+1);
    for (pi e: edges) {
        int cu = col[e.first], cv = col[e.second];
        if (cu != cv) {
            cadj[cu].insert(cv);
            cadj[cv].insert(cu);
        }
    }

    vvi dist(L + 1, vector<int>(L + 1, INF));

    for (int src = 1; src <= L; src++) {
        dist[src][src] = 0;
        qi q;
        q.push(src);
        while (!q.empty()) {
            int c = q.front(); q.pop();
            for (int nc : cadj[c]) {
                if (dist[src][nc] == INF) {
                    dist[src][nc] = dist[src][c] + 1;
                    q.push(nc);
                }
            }
        }
    }

    int Q; cin >> Q;

    int v, l;
    LOOP(Q) {
        cin >> v >> l;

        int cv = col[v];
        int res = INT_MAX;

        for (int i = 0; i < l; i++) {
            int exitColor;
            cin >> exitColor;
            int d = dist[cv][exitColor];
            if (d != INF)
                res = min(res, d);
        }

        cout << (res == INT_MAX ? -1 : res) << "\n";
    }


    return 0;
}
