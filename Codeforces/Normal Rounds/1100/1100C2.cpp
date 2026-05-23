// C2. We Be Flipping (Hard Version)
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
#define vc vector

constexpr int MM = 1e5+5;
constexpr int INF = 0x3F3F3F3F;
constexpr ll INFL = 0x3F3F3F3F3F3F3F3FLL;
constexpr int MOD = 1e9 + 7;


int main() {
    int T; scanf("%d",&T);
    int n;
    LOOP(T) {
        int n; scanf("%d",&n);
        
        vl a(n + 1);
        ll total_sum = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            total_sum += a[i];
        }

        vl pref_abs(n + 2, 0);
        for (int i = 1; i <= n; ++i) {
            pref_abs[i] = pref_abs[i - 1] + abs(a[i]);
        }

        vl suff_reg(n + 2, 0);
        for (int i = n; i >= 1; --i) {
            suff_reg[i] = suff_reg[i + 1] + a[i];
        }

        ll max_sum = total_sum;
        int best_m = -1;
        for (int m = 1; m <= n; ++m) {
            if (a[m] > 0) {
                long long current_sum = pref_abs[m - 1] - a[m] + suff_reg[m + 1];
                if (current_sum > max_sum) {
                    max_sum = current_sum;
                    best_m = m;
                }
            }
        }

        
        if (best_m == -1) { printf("0\n"); continue; }

        vi F(n + 2, 0);
        F[best_m] = 1;
        for (int i = 1; i < best_m; ++i) {
            F[i] = (a[i] > 0) ? 0 : 1;
        }

        vi f(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            f[i] = F[i] ^ F[i + 1];
        }

        deque<int> dq;
        for (int i = n; i >= 1; --i) {
            if (f[i] == 1) {
                if (dq.empty()) {
                    dq.push_front(i);
                } else {
                    if (a[i] > 0) {
                        dq.push_front(i);
                    } else {
                        int first = dq.front();
                        dq.pop_front();
                        dq.push_front(i);
                        dq.push_front(first);
                    }
                }
            }
        }

        printf("%d\n",(int)dq.size());
        for (int i = 0; i < dq.size(); i++) {
            printf("%d%c",dq[i], (i+1 < (int)dq.size() ? ' ' : '\n'));
        }
    }

    return 0;
}
