// ECOO '19 R1 P1 - Free Shirts
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define LOOP(n) for (int _ = 0; _ < n; _++)

int main() {
    int N,M,D;
    int washes, clean, dirty;
    LOOP(10) {
        scanf("%d %d %d",&N,&M,&D);
        vi E(D+1, 0); for (int ai, i=1;i<=M;++i) { scanf("%d",&ai); ++E[ai]; }

        washes = 0;
        clean = N;
        dirty = 0;
        for (int d = 1; d <= D; ++d) {
            if (!clean) {
                clean = dirty;
                dirty = 0;
                ++washes;
            }
            
            clean += E[d];

            --clean;
            ++dirty;
        }

        printf("%d\n",washes);
    }

    return 0;
}
