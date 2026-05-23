// A. Slimes on a Line
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define endl '\n'
#define LOOP(n) for (int _ = 0; _ < n; _++)


int main() {
    int T; scanf("%d",&T);
    int n;
    int maxx,minn;
    LOOP(T) {
        scanf("%d",&n);
        vi arr(n); for (int i = 0; i < n; i++) scanf("%d",&arr[i]);
        maxx = 0;
        minn = INT_MAX;
        for (int i = 0; i < n; i++) {
            maxx = max(maxx, arr[i]);
            minn = min(minn, arr[i]);
        }

        printf("%d\n",(maxx-minn+1) / 2);
    }

    return 0;
}
