// Halloween '14 P2 - Cat Girls
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define pb push_back


/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll N,W; cin >> N >> W;
    
    vl pwid = {0}, pval = {0}, dp = {0};
    char op; int p,c;
    LOOP(N) {
        cin >> op;
        if (op == 'A') {
            cin >> p >> c;
            pwid.pb(pwid.back() + p);
            pval.pb(pval.back() + c);
            
            int j = lower_bound(ALL(pwid), pwid.back() - W) - pwid.begin();
            dp.pb(max(dp.back(), pval.back()-pval[j]));
            cout << dp.back() << endl;
        } else {
            pwid.pop_back();
            pval.pop_back();
            dp.pop_back();
        }
    }

    return 0;
}
