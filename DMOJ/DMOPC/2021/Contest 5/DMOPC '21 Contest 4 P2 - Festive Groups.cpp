// DMOPC '21 Contest 4 P2 - Festive Groups
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define endl '\n'
#define LOOP(n) for (int _ = 0; _ < n; _++)

constexpr int MM = 5e6+5;

/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    vi sieve(MM,0); {
        int j;
        LOOP(N) {
            sieve[(cin >> j,j)]++;
        }
    }

    int res = 0;
    for (int i = 1; i < MM; i++) {
        if (sieve[i] > 0) {
            res++;
            for (int j = i; j < MM; j += i) sieve[j] = 0;
        }
    }

    cout << res << endl;

    return 0;
}
