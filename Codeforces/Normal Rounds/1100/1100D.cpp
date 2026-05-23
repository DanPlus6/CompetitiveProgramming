// D. Me When Median Problem
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define LOOP(n) for (int _ = 0; _ < n; _++)

bool check(int X, int n, const vi& a, const vi& b) {
    int k = 0, C = 0;
    bool has_zero = false;
    
    for (int i = 0; i < n; ++i) {
        int c = (a[i] >= X ? 1 : 0) + (b[i] >= X ? 1 : 0);
        if (c == 2) {
            k++;
            if (has_zero) {
                C++;
                has_zero = false;
            }
        } else if (c == 0) {
            has_zero = true;
        }
    }
    
    if (has_zero) {
        C++;
    }
    
    return k > C;
}

int main() {  
    int T; scanf("%d",&T);
    int n;
    LOOP(T) {    
        scanf("%d",&n);
        vi a(n); for (int i = 0; i < n; i++) scanf("%d",&a[i]);
        vi b(n); for (int i = 0; i < n; i++) scanf("%d",&b[i]);

        int lo = 1, hi = 2 * n;
        int res = 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid, n, a, b)) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        printf("%d\n",res);
    }
    
    return 0;
}
