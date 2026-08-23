/**
 * Author: DanPlus6 // David Fu
 * Problem Name: Tea Drinking
 */
#include <bits/stdc++.h>
using namespace std;

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
typedef unordered_set<int> si;
typedef set<ll> sl;
typedef queue<int> qi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<pi> vii;
typedef vector<ti> vti;
typedef vector<pl> vll;
typedef vector<tl> vtl;
typedef vector<bool> vb;
#define endl '\n'
#define FILL(a, b) memset(a, b, sizeof(a))
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define pb push_back
#define fi first
#define se second

constexpr int MM = 1e5+5;
constexpr int INF = 0x3F3F3F3F;
constexpr ll INFL = 0x3F3F3F3F3F3F3F3FLL;
constexpr int MOD = 1e9 + 7;

int main() {
    int T; scanf("%d",&T);
    for (int t,w,s; T--;) {
        scanf("%d %d %d",&t,&w,&s);
        int N = t+w;
        vl B(N + 1); 
        for (int i = 1; i <= N; ++i) scanf("%lld", &B[i]);

        vl pref(N + 1, 0);
        for (int i = 1; i <= N; ++i) {
            pref[i] = pref[i - 1] + B[i];
        }

        int X_min = max(1, t - s + 1);
        int X_max = t + w - s + 1;
        ll res = INFL;

        for (int k = X_min; k <= N; ++k) {
            int X = min(k, X_max);
            int Y = max(k, t);
            ll L = Y - X + 1;
            ll cost = pref[Y] - pref[X - 1] + (s - L) * B[k];
            res = min(res, cost);
        }
        
        printf("%lld\n", res);
    }

    return 0;
}
