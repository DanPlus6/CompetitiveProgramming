#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n + 1, vector<int>(m + 1));
    unordered_map<int, vector<pair<int,int>>> mp;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            mp[i * j].push_back({i, j});
        }
    }

    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
    queue<pair<int,int>> q;

    q.push({1, 1});
    visited[1][1] = true;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (r == n && c == m) {
            cout << "yes\n";
            return 0;
        }

        int v = grid[r][c];
        for (auto [nr, nc] : mp[v]) {
            if (!visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
        mp[v].clear();
    }

    cout << "no\n";
}
