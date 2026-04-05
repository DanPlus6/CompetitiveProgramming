// USACO 2026 Third Contest, Bronze Problem 2. Strange Function
#include <bits/stdc++.h>
using namespace std;
char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;
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
typedef vector<ll> vl;
typedef vector<pi> vii;
typedef vector<ti> vti;
typedef vector<pl> vll;
typedef vector<tl> vtl;
typedef vector<pii> viii;
typedef vector<bool> vb;
typedef priority_queue<int, vi> ipq;
typedef priority_queue<int, vi, greater<int>> ripq;
#define endl '\n'
#define FILL(a, b) memset(a, b, sizeof(a))
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define SECLOOP(M) for (int j = 0; j < M; j++)
#define RLOOP(n) for (int i = n; i >= 0; i--)
#define ILOOP(arr) for (int &i: arr)
#define CLOOP(s) for (char c: s)
#define pb push_back
#define FOUNDANS(res) {cout << res << endl; return 0;}

constexpr int MM = 1e5+5;
constexpr int INF = 0x3F3F3F3F;
constexpr ll INFL = 0x3F3F3F3F3F3F3F3FLL;
constexpr int MOD = 1e9 + 7;


int main() {
    #define int ll
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        string X; cin >> X;

        bool needChange = true;
        CLOOP(X) {
            if (c != '0' && c != '1') {needChange = false; break;}
        }

        if (!needChange) {
            for (char &c: X) {
                if ((c-'0') & 1) c = '1';
                else c = '0';
            }
        }

        int v = 0, vhelp = 0;
        PRIMLOOP(X.length()) {
            v = (v*2 + (X[i]-'0')) % MOD;
            if (i < X.length()-1) vhelp = (vhelp*2 + (X[i]-'0')) % MOD;
        }

        int res = (v + vhelp) % MOD;
        if (!needChange) cout << (res+1) % MOD << endl;
        else cout << res << endl;
    }

    return 0;
}
