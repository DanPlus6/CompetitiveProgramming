// CCC '20 S2 - Escape Room
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
#define endl '\n'
#define pb push_back
#define FOUNDANS(res) {cout << res << endl; return 0;}


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int M,N; cin >> M >> N;
    vector<vi> grid(M+1,vi(N+1));
    unordered_map<int,vii> cells_by_num;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
            cells_by_num[grid[i][j]].pb({i,j});
        }
    }

    vector<vector<bool>> vis(M+1, vector<bool>(N+1, false));
    queue<pi> q;
    
    q.push({M,N});
    vis[M][N] = true;

    while (!q.empty()) {
        int crow = q.front().first, ccol = q.front().second;
        q.pop();
        vis[crow][ccol] = true;

        vii& valids = cells_by_num[crow*ccol];
        for (int i = 0; i < valids.size(); i++) {
            int nrow = valids[i].first, ncol = valids[i].second;
            if (nrow == 1 && ncol == 1) FOUNDANS("yes")

            if (!vis[nrow][ncol]) q.push({nrow, ncol});
        }
    }

    cout << "no\n";


    return 0;
}
