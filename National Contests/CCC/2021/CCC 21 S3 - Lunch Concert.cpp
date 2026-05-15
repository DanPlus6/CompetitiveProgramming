// CCC '21 S3 - Lunch Concert
#include <bits/stdc++.h>
using namespace std;
char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;
#define int ll
typedef pair<int, int> pi;
typedef tuple<int ,int, int> ti;
typedef pair<pi, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pl;
typedef tuple<ll,ll,ll> tl;
typedef pair<ll,pl> pll;
typedef pair<string, int> psi;
typedef vector<int> vi;
typedef set<int> si;
typedef set<ll> sl;
typedef queue<int> qi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<pi> vii;
typedef vector<ti> vti;
typedef vector<pl> vll;
typedef vector<tl> vtl;
typedef vector<pii> viii;
typedef vector<bool> vb;
typedef priority_queue<int, vi> ipq;
typedef priority_queue<int, vi, greater<>> ripq;
#define endl '\n'
#define FILL(a, b) memset(a, b, sizeof(a))
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define SECLOOP(M) for (int j = 0; j < M; j++)
#define RLOOP(n) for (int i = n; i >= 0; i--)
#define ILOOP(arr) for (int &i: arr)
#define CLOOP(s) for (char c: s)


/* Orz bruce */
signed main() {
    int N; scanf("%d",&N);

    vi P(N), W(N), D(N);
    PRIMLOOP(N) {
        scanf("%d %d %d",&P[i], &W[i], &D[i]);
    }

    int optimPos = 0;
    ll left = 0, right = 0;
    int dist;
    for (int i = 0; i < N; i++) {
        dist = abs()
    }
    
    for (int i = 0; i < N; i++) {

    }

    printf("%d\n",optimPos);

    return 0;
}
