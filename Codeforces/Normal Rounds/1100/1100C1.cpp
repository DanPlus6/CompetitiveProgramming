// C1. We Be Flipping (Easy Version)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define pb push_back

int main() {
    int T; scanf("%d",&T);
    int n;

    int flip;
    LOOP(T) {
        scanf("%d",&n);
        vi a(n); for (int i=0;i<n;i++) scanf("%d",&a[i]);

        vi ops;
        flip = 0;
        int cur;
        for (int i = n-1; i >= 0; i--) {
            cur = (flip == 0 ? a[i] : -a[i]);
            if (cur > 0) {
                ops.pb(i+1);
                flip ^= 1;
            }
        }

        printf("%d\n",(int)ops.size());
        if (ops.empty()) printf("\n");
        else {
            for (int i = 0; i < (int)ops.size(); i++) {
                printf("%d%c",ops[i], (i+1 < (int)ops.size() ? ' ' : '\n'));
            }
        }
    }

    return 0;
}
