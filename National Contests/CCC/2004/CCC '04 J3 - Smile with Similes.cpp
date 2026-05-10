// CCC '04 J3 - Smile with Similes
#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
#define endl '\n'
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define SECLOOP(M) for (int j = 0; j < M; j++)

/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N,M; cin >> N >> M;
    vs adj(N); PRIMLOOP(N) cin >> adj[i];
    vs noun(M); PRIMLOOP(M) cin >> noun[i];

    PRIMLOOP(N) {
        SECLOOP(M) cout << adj[i] << " as " << noun[j] << endl;
    }

    return 0;
}
