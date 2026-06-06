// COCI '14 Contest 5 #3 Traktor
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

constexpr int MM = 1e5+5;

int main() {
    int N,K; scanf("%d %d",&N,&K);
    vi row(MM,0), col(MM,0), lft(2*MM,0), rit(2*MM,0);

    for (int t = 1, r,c; t <= N; t++) {
        scanf("%d %d",&r,&c);
        if (++row[r] == K || ++col[c] == K || ++lft[r+c] == K || ++rit[r-c+MM] == K) {
            printf("%d\n",t);
            return 0;
        }
    }

    printf("-1\n");

    return 0;
}
