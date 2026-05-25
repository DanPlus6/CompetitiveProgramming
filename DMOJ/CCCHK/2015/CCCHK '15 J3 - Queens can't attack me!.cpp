// CCCHK '15 J3 - Queens can't attack me!
#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> vb;
#define valid(x) (x >= 0 && x < N)

int dirr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dirc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int N,M, res;
int main() {
    scanf("%d %d",&N,&M);
    vector<vb> grid(N,vb(N,true));

    res = N*N;
    for (int _=0;_<M;_++) {
        int x,y; scanf("%d %d",&x, &y);
        if (grid[--x][--y]) { --res; grid[x][y] = false; }

        int r, c;
        for (int d = 0; d < 8; d++) {
            r = x + dirr[d];
            c = y + dirc[d];

            while (valid(r) && valid(c)) {
                if (grid[r][c]) { --res; grid[r][c] = false; }
                r += dirr[d];
                c += dirc[d];
            }
        }
    }

    printf("%d\n",res);

    return 0;
}
