/**
 * Author: DanPlus6 // David Fu
 * Problem Name: Hardcore Grinding
 * Problem Code: grind
 * Problem URL:  https://dmoj.ca/problem/grind
 */
#include <bits/stdc++.h>
using namespace std;

constexpr int MM = 1e7+1;

int T[MM];
int main() {
    int N; scanf("%d",&N);
    int latest = 0;
    for (int s,f; N--;) {
        scanf("%d %d",&s,&f);
        ++T[s], --T[f];
        latest = max(f, latest);
    }

    int res = 0;
    for (int p=0,i=1;i<latest;++i) {
        p += T[i];
        res = max(p,res);
    }

    printf("%d\n",res);

    return 0;
}
