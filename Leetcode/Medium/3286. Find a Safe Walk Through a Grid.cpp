// 3286. Find a Safe Walk Through a Grid
#include <bits/stdc++.h>
using namespace std;

typedef tuple<int ,int, int> ti;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ti> vti;

class Solution {
public:
    bool findSafeWalk(vvi &grid, int health) {
        health -= grid[0][0];
        if (health <= 0) return false;

        int N = grid.size(), M = grid[0].size();
        vvi mHp(N, vi(M, -1)); mHp[0][0] = health;
        priority_queue<ti> q; q.push({health,0,0});

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int nh,nx,ny;
        while (!q.empty()) {
            auto [h,x,y] = q.top(); q.pop();

            if (x == N-1 && y == M-1) return true;
            if (h < mHp[x][y]) continue;

            for (int d=0;d<4;++d) {
                nx = x+dx[d];
                ny = y+dy[d];

                if (nx < 0 || nx >= N) continue;
                if (ny < 0 || ny >= M) continue;
                
                nh = h-grid[nx][ny];

                if (nh > 0 && nh > mHp[nx][ny]) {
                    mHp[nx][ny] = nh;
                    q.push({nh,nx,ny});
                }
            }
        }

        return false;
    }
};

