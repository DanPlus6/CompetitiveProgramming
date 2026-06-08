// USACO 2026 Third Contest, Bronze Problem 3. Swap to Win
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
#define ILOOP(n) for (int i = 0; i < n; i++)
#define PRIMLOOP(N) for (int n = 0; n < N; n++)
#define SECLOOP(M) for (int m = 0; m < M; m++)
#define RLOOP(n) for (int i = n; i >= 0; i--)
#define CLOOP(s) for (char c: s)
#define pb push_back
#define FOUNDANS(res) {cout << res << endl; return 0;}

constexpr int MM = 1e5+5;
constexpr int INF = 0x3F3F3F3F;
constexpr ll INFL = 0x3F3F3F3F3F3F3F3FLL;
constexpr int MOD = 1e9 + 7;

struct Move {
    int type;
    int a, b, c;
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int _; cin >> _;
    while (_--) {
        int N, M;
        cin >> N >> M;
        string t;
        cin >> t;
        vector<string> s(N);
        vector<vector<pair<int, int>>> l(26);

        for (int i = 0; i < N; ++i) {
            cin >> s[i];
            for (int j = 0; j < M; ++j) {
                l[s[i][j] - 'a'].push_back({i, j});
            }
        }

        vector<Move> ans;
        for (int i = 0; i < M; ++i) {
            if (s[0][i] == t[i]) continue;
            int tar = t[i] - 'a';
            int u = -1, v = -1;
            while (true){
                if (l[tar].empty()) break;

                pair<int, int> p = l[tar].back();
                l[tar].pop_back();

                if (s[p.first][p.second] != (char)('a' + tar)) continue;
                if (p.first == 0 && p.second < i) continue;
                if (p.first == 0 && p.second == i)continue;

                u = p.first;
                v= p.second;
                break;
            }

            if (u == 0) {
                char e = s[0][i];
                ans.push_back({1, 1, i + 1, v + 1});
                swap(s[0][i], s[0][v]);
                l[e -'a'].push_back({0, v});
            } else {
                if (v == i) {
                    char existing = s[0][i];
                    ans.push_back({2, 1, u + 1, i + 1});
                    swap(s[0][i], s[u][i]);
                    l[existing - 'a'].push_back({u, i});
                } else if (v > i) {
                    char c = s[0][v];
                    ans.push_back({2, 1, u + 1, v + 1});
                    swap(s[0][v], s[u][v]);
                    l[c - 'a'].push_back({u, v});

                    char c2 = s[0][i];
                    ans.push_back({1, 1, i + 1, v + 1});
                    swap(s[0][i], s[0][v]);
                    l[c2 - 'a'].push_back({0, v});
                } else {
                    char c = s[u][i];
                    ans.push_back({1, u + 1, v + 1, i + 1});
                    swap(s[u][v], s[u][i]);
                    l[c - 'a'].push_back({u, v});

                    char c2 = s[0][i];
                    ans.push_back({2, 1, u + 1, i + 1});
                    swap(s[0][i], s[u][i]);
                    l[c2 - 'a'].push_back({u, i});
                }
            }
        }

        cout << ans.size() << "\n";
        for (const auto& m : ans) {
            if (m.type == 1) {
                cout<< "1 " << m.a << " " << m.b << " " <<m.c << "\n";
            } else {
                cout << "2 " << m.a <<" " << m.b << " " << m.c << "\n";
            }
        }
    }

    return 0;
}
