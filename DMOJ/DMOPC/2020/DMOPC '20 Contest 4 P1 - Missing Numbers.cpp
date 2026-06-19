// DMOPC '20 Contest 4 P1 - Missing Numbers
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define LOOP(n) for (int _ = 0; _ < n; _++)

int T;
ll N, S;
int main() {
    scanf("%d", &T);

    ll M, i, j;
    LOOP(T) {
        scanf("%lld %lld", &N, &S);
        M = (N*N + N) / 2 - S;
        
        i = max(1ll, M-N);
        j = (M - 1) / 2;
        
        printf("%lld\n",
            max(0ll, j-i+1)
        );
    }

    return 0;
}
