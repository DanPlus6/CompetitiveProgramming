// A. Antimedian Deletion
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define PRIMLOOP(N) for (int i = 0; i < N; i++)


/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    LOOP(T) {
        int N; cin >> N;
        vi P(N); PRIMLOOP(N) cin >> P[i];
        int res = (N < 3) ? N : 2;
        PRIMLOOP(N) {
            cout << res << ((i < N-1) ? " " : "");
        }
        cout << endl;
    }

    return 0;
}
