// Plant Growth
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef vector<string> vs;
#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define PRIMLOOP(N) for (int i = 0; i < N; i++)


/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    vs grid(N); PRIMLOOP(N) cin >> grid[i];

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    {vs oldGrid = grid;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (oldGrid[r][c] == '&') {
                    for (int d = 0; d < 4; d++) {
                        int newr = r + dr[d], newc = c + dc[d];
                        if ((newr >= 0 && newr < N) && (newc >= 0 && newc < N)) grid[newr][newc] = '&';
                    }
                }
            }
        }
    }

    {vs oldGrid = grid;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                bool dies = false;
                for (int d = 0; d < 4; d++) {
                    int newr = r + dr[d], newc = c + dc[d];
                    if (!(newr >= 0 && newr < N && newc >= 0 && newc < N) || oldGrid[newr][newc] == '.') { 
                        dies = true;
                        break;
                    }                    
                }
                if (dies) grid[r][c] = '.';
            }
        }
    }

    for (auto ln: grid) {cout << ln << endl;}

    return 0;
}
