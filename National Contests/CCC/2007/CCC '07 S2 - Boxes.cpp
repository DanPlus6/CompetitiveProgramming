/**
 * Author: DanPlus6 // David Fu
 * Problem Name: CCC '07 S2 - Boxes
 * Problem URL:  https://dmoj.ca/problem/ccc07s2
 * Problem Code: ccc07s2
 */
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#define ALL(x) x.begin(),x.end()

struct ti {
    int d[3];
    int l() const { return d[0]; }
    int w() const { return d[1]; }
    int h() const { return d[2]; }

    int v() const {
        return d[0]*d[1]*d[2];
    }

    bool operator>=(const ti& x) const {
        return l()>=x.l() && w()>=x.w() && h()>=x.h();
    }

    bool operator<(const ti& x) const {
        return v() < x.v();
    }
};

int main() {
    int N; scanf("%d",&N);
    vector<ti> sz(N); ti x;
    for (int i=0;i<N;++i) {
        scanf("%d %d %d",&x.d[0],&x.d[1],&x.d[2]);
        sort(x.d,x.d+3);
        sz[i] = x;
    }
    sort(ALL(sz));

    int M; scanf("%d",&M); 
    while(M--) {
        scanf("%d %d %d",&x.d[0],&x.d[1],&x.d[2]);
        sort(x.d,x.d+3);
        bool can = false;
        for (const ti &y: sz) {
            if (y>=x) {
                printf("%d\n",y.v());
                can = true;
                break;
            }
        }
        if (!can) printf("Item does not fit.\n");
    }

    return 0;
}
