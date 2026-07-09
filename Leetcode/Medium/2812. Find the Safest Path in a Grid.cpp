// 2812. Find the Safest Path in a Grid
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int ,int, int> ti;
typedef pair<pi, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pl;
typedef tuple<ll,ll,ll> tl;
typedef pair<ll,pl> pll;
typedef vector<int> vi;
typedef unordered_set<int> si;
typedef set<ll> sl;
typedef queue<int> qi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<pi> vii;
typedef vector<ti> vti;
typedef vector<pl> vll;
typedef vector<tl> vtl;
typedef vector<bool> vb;
#define FILL(a, b) memset(a, b, sizeof(a))
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define pb push_back

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

class Solution {
public:
    int maximumSafenessFactor(vvi &grid) {
        if (grid[0][0] || grid.back().back()) return 0;

        int N = grid.size();
        vvi dist(N, vi(N, INT_MAX)); {
            queue<ti> q;
            for (int i=0;i<N;++i) 
                for (int j=0;j<N;++j) {
                    if (grid[i][j]) q.push({i,j,0});
            }

            while (!q.empty()) {
                auto [x,y,d] = q.front(); q.pop();

                for (int nx,ny, i=0;i<4;++i) {
                    nx = x+dc[i];
                    ny = y+dr[i];

                    if (min(nx,ny) >= 0 && max(nx,ny) < N)
                        if (dist[nx][ny] == INT_MAX) {
                            dist[nx][ny] = d+1;
                            q.push({nx,ny,d+1});
                        }
                }
            }
        }

        vector<vb> vis(N, vb(N,false));
        priority_queue<ti> q; q.push({dist[0][0],0,0});
        int res = -1;
        while (!q.empty()) {
            auto [d,x,y] = q.top(); q.pop();

            if (vis[x][y]) continue;
            vis[x][y] = true;
            
            if (x == N-1 && y == N-1) { res = max(d,res); continue; }
            for (int nx,ny, i=0;i<4;++i) {
                nx = x+dc[i];
                ny = y+dr[i];

                if (min(nx,ny) >= 0 && max(nx,ny) < N)
                    q.push({min(d,dist[nx][ny]),nx,ny});
            }
        }

        return res;
    }
};
