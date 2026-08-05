/**
 * Author: DanPlus6 // David Fu
 * Problem Name: WC '18 Contest 2 S2 - Plutonium
 * Problem URL:  https://dmoj.ca/problem/wc18c2s2
 * Problem Code: wc18c2s2
 */
#include <bits/stdc++.h>
using namespace std;

constexpr int MM = 2e5+5;

int N, lo=0, hi=0, O[MM], P[MM];
int main() {
    scanf("%d",&N);
    for (int i=0;i<N;++i) scanf("%d",&O[i]);

    P[N] = 0;
    for (int i=N-1;i>=0;--i) {
        if (O[i] && P[i+1]>1 && O[i]!=P[i+1]-1) {
            printf("-1\n"); return 0;
        }
        
        P[i] = (O[i] ? O[i] : max(0,P[i+1]-1));
        if (i && P[i] == 1) ++lo, ++hi;
        if (i && P[i] == 0) ++hi;
    }

    if (P[0] > 1) printf("-1\n");
    else printf("%d %d\n",lo,hi);


    return 0;
}
