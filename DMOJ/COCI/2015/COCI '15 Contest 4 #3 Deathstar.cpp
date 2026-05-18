// COCI '15 Contest 4 #3 Deathstar
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define endl '\n'
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define SECLOOP(M) for (int j = 0; j < M; j++)


/* Orz bruce */
int main() {
    int N; scanf("%d",&N);
    vvi M(N, vi(N)); PRIMLOOP(N) SECLOOP(N) scanf("%d",&M[i][j]);

    int res;
    for (int i = 0; i < N; i++) {
        res = M[i][0];
        for (int j = 1; j < N; j++) {
            res |= M[i][j];
        }
        printf("%d%c",res,(i == N-1 ? '\n' : ' '));
    }

    return 0;
}
