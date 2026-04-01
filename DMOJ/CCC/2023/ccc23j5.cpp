// CCC '23 J5 - CCC Word Hunt
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    char W[200]; cin >> W;
    int R,C; cin >> R >> C;
    int N; N = strlen(W)-1;
    //  0:N, 1:NE, 2:E, 3:SE, 4:S, 5:SW, 6:W, 7:NW
    int dr[8] = {-1,-1,0,1,1,1,0,-1};
    int dc[8] = {0,1,1,1,0,-1,-1,-1};

    vector<vector<char>> grid(R);
    vector<pair<int,int>> start;
    for (int i = 0; i < R; i++) { for (int j = 0; j < C; j++) { 
            char tmp; cin >> tmp;
            grid[i].push_back(tmp);
            if (tmp == W[0]) {start.push_back({i,j});}
    }};


    int res = 0;
    // janky bfs thingy idk
    for (pair<int,int> curHeader: start) {
        queue<vector<int>> q;
        
        if (N == 1) {
            for (int dirK = 0; dirK < 8; dirK++) {
                int nr = curHeader.first + dr[dirK];
                int nc = curHeader.second + dc[dirK];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                //  0:up, 1:up-right, 2:right, 3:down-right, 4:down, 5:down-left, 6:left, 7:up-left
                                                        //r,     c, index,    dir, turned
                if (grid[nr][nc] == W[1]) {res++;}
            };
            continue;
        }

        for (int dirK = 0; dirK < 8; dirK++) {
            int nr = curHeader.first + dr[dirK];
            int nc = curHeader.second + dc[dirK];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            //  0:up, 1:up-right, 2:right, 3:down-right, 4:down, 5:down-left, 6:left, 7:up-left
                                                    //r,     c, index,    dir, turned
            if (grid[nr][nc] == W[1]) {q.push({nr,nc,1,dirK,0});}
        }; if (q.empty()) {continue;}

        while (!q.empty()) {
            int cr = q.front()[0], cc = q.front()[1], ind = q.front()[2], dir = q.front()[3], turned = q.front()[4];
            q.pop();

            int nind = ind+1;
            if (turned) {
                int nr = cr + dr[dir];
                int nc = cc + dc[dir];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                if (nind == N && grid[nr][nc] == W[nind]) {res++;} // end
                else if (grid[nr][nc] == W[ind+1]) {q.push({nr,nc,nind,dir,1});} // not end of word
            } else {
                // cur dir
                int nr = cr + dr[dir];
                int nc = cc + dc[dir];
                if (!(nr < 0 || nr >= R || nc < 0 || nc >= C)) {
                    if (nind == N && grid[nr][nc] == W[nind]) {res++;}
                    else if (grid[nr][nc] == W[ind+1]) {q.push({nr,nc,nind,dir,0});}
                }
                // 90 degrees cws
                int ndir = (dir+2)%8;
                nr = cr + dr[ndir];
                nc = cc + dc[ndir]; 
                if (!(nr < 0 || nr >= R || nc < 0 || nc >= C)) {
                    if (nind == N && grid[nr][nc] == W[nind]) {res++;}
                    else if (grid[nr][nc] == W[ind+1]) {q.push({nr,nc,nind,ndir,1});}
                }
                // 90 degrees ctcws
                ndir = (dir+6)%8;
                nr = cr + dr[ndir];
                nc = cc + dc[ndir];
                if (!(nr < 0 || nr >= R || nc < 0 || nc >= C)) {
                    if (nind == N && grid[nr][nc] == W[nind]) {res++;}
                    else if (grid[nr][nc] == W[ind+1]) {q.push({nr,nc,nind,ndir,1});}
                }
            }
        }
    }

    cout << res << "\n";

    return 0;
}
