// 2812. Find the Safest Path in a Grid
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int ,int, int> ti;
typedef vector<int> vi;
typedef vector<vi> vvi;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

class Solution {
public:
    int maximumSafenessFactor(vvi &A) {
        if (A[0][0] || A.back().back()) return 0;

        int N = A.size();
        queue<pi> q;
        for (int r=0;r<N;++r) {
            for (int c=0;c<N;++c) {
                if (A[r][c]) {
                    q.push({r,c});
                }
            }
        }
        
        while (!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            int dist = A[r][c];

            for (int nr,nc, d=0;d<4;++d) {
                nr = r+dr[d];
                nc = c+dc[d];

                if (min(nr,nc) >= 0 && max(nr,nc) < N && !A[nr][nc]) {
                    A[nr][nc] = dist+1;
                    q.push({nr,nc});
                }
            }
        }

        
        priority_queue<ti> pq; pq.push({A[0][0],0,0});
        while (!pq.empty()) {
            auto [dist,r,c] = pq.top(); pq.pop();

            if (r == N-1 && c == N-1) return dist-1;

            if (A[r][c] <= 0) continue;
            A[r][c] *= -1;
            for (int nr,nc, d=0;d<4;++d) {
                nr = r+dr[d];
                nc = c+dc[d];

                if (min(nr,nc) >= 0 && max(nr,nc) < N) {
                    pq.push({min(dist,A[nr][nc]),nr,nc});
                }
            }
        }

        return A[N-1][N-1] - 1;
    }
};
