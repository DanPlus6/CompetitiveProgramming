// CCC '11 S3 - Alice Through the Looking Glass
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
#define LOOP(n) for (int _ = 0; _ < n; _++)

bool check(int m, int x, int y) {
    int blk = pow(5,m-1);
    int bx = x / blk, by = y / blk;
    if ((1 <= bx && bx <= 3 && by == 0) || (bx == 2 && by == 1))
        return true;
    else if (m > 1 && ((bx == 1 && by == 1) || (bx == 2 && by == 2) || (bx == 3 && by == 1)))
        return check(m-1, x%blk, y%blk);
    else
        return false;
}

signed main() {
    int T; scanf("%lld",&T);
    int m,x,y;
    LOOP(T) {
        scanf("%lld %lld %lld",&m,&x,&y);

        printf("%s\n",(check(m,x,y) ? "crystal" : "empty"));
    }

    return 0;
}
