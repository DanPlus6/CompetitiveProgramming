// DWITE '07 R2 #3 - Floor Plan
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


    vector<pair<int,int>> start(6, {-1,-1});
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (grid[r][c] >= '1' && grid[r][c] <= '5') {
                start[ grid[r][c] - '0' ] = {r,c};
            }
        }
    }

    for (int id = 1; id <= 5; id++) {
        auto [sr, sc] = start[id];
        if (sr == -1) {
            cout << 0 << "\n";
            continue;
        }

        vector<vector<bool>> vis(R, vector<bool>(C, false));
        queue<pair<int,int>> q;
       
        q.push({sr, sc});
        vis[sr][sc] = true;
        int area = 0;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            area++;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                if (vis[nr][nc]) continue;
                if (grid[nr][nc] == '#') continue;

                vis[nr][nc] = true;
                q.push({nr, nc});
            }
        }

        cout << area << "\n";
    }

    return 0;
}
