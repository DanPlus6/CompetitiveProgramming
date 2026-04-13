// Add Up Apples
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'
#define pb push_back


int N, res = 0;
void solve(vi cur, int rem, int minn) {
    if (rem == 0 && cur.size() >= 2) {
        cout << N << '=';
        for (int i = 0; i < cur.size(); i++) {
            if (i > 0) cout << '+' << cur[i];
            else cout << cur[i];
        }
        cout << endl;
        res++;
        return;
    }

    for (int i = minn; i <= rem; i++) {
        cur.pb(i);
        solve(cur, rem-i, i);
        cur.pop_back();
    }
}

/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    solve({}, N, 1);
    cout << "total=" << res << endl;
    return 0;
}
