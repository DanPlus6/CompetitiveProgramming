// CCCHK '15 S1 - Finding number of pairs
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define PRIMLOOP(N) for (int i = 0; i < N; i++)

constexpr int MOD = 1e9 + 7;


/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N,M; cin >> N >> M;
    vi A(N); PRIMLOOP(N) cin >> A[i];
    sort(ALL(A));
    
    int res = 0;
    int i = 0, j = N-1;
    while (i < j) {
        if (A[i] + A[j] <= M) {
            res += j-i;
            i++;
        }
        else j--;
    }

    cout << res%MOD << endl;

    return 0;
}
