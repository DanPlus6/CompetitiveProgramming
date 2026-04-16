// CCC '24 J5 - Harvest Waterloo
#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    vector<string> grid(R);
    for (int i = 0; i < R; i++){
        cin >> grid[i];
    }

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int SR,SC; cin >> SR >> SC;

    vector<vector<bool>> vis(R, vector<bool>(C, false));
    int res = 0;
            
    queue<pair<int,int>> q;

    q.push({SR, SC});
    vis[SR][SC] = true;
    
    // my goat ryan guo/guan (never got his name right)
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        if (grid[r][c] == 'L') {res += 10;} else if (grid[r][c] == 'M') {res += 5;} else if (grid[r][c] == 'S') {res++;}

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (vis[nr][nc]) continue;
            if (grid[nr][nc] == '*') continue;

            vis[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    cout << res << "\n";
    return 0;
}
