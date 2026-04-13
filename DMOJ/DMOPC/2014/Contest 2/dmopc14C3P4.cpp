// DMOPC '14 Contest 3 P4 - Not Enough Testers!
#include <bits/stdc++.h>
using namespace std;


typedef vector<int> vi;
#define endl '\n'
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define pb push_back

constexpr int MM = 1e5+5;

int main() {
    vi factors(MM); {
        vi spf; for (int i = 0; i <= MM; i++) spf.pb(i);
        for (int i = 2; i*i <= MM; i++) {
            if (spf[i] == i) {
                for (int j = i*i; j <= MM; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }

        for (int i = 1; i < MM; i++) {
            int num = i;
            int res = 1;
            while (num > 1) {
                int p = spf[num], exp = 0;
                while (num % p == 0) {
                    num /= p;
                    exp++;
                }
                res *= (exp + 1);
            }
            factors[i] = res;
        }
    }

    int T; cin >> T;
    int K,A,B;
    LOOP(T) {
        scanf("%d %d %d",&K,&A,&B);
        int res = 0;
        for (int i = A; i <= B; i++) res += (factors[i] == K ? 1 : 0);
        printf("%d\n",res);
    }

    return 0;
}
