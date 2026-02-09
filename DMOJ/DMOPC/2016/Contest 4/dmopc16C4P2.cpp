// DMOPC '16 Contest 4 P2 - Systests
#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pi;
typedef vector<int> vi;
#define endl '\n'
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int B; cin >> B;
    int res = 0;
    vi fv(B), ev(B), pv(B);
    for (int b = 0; b < B; b++) {
        cin >> fv[b] >> ev[b] >> pv[b];
        res += pv[b];
    }

    int F; cin >> F;
    vi fails(F);
    for (int t = 0; t < F; t++) cin >> fails[t];
    sort(ALL(fails));

    if (F == 0) {cout << res << endl; return 0;}

    // orz bruce
    // omg bro i forgot bout bin search 😭
    for (int b = 0; b < B; b++) {
        if (distance(lower_bound(ALL(fails),fv[b]),upper_bound(ALL(fails),ev[b]))) res -= pv[b];
    }

    cout << res << endl;

    // map<pi,int> batches;
    // for (int b=0;b<B;b++) {
    //     int f, e, p; cin >> f >> e >> p;
    //     batches[{f,e}] = p;
    //     res += p;
    // }

    // int F; cin >> F;
    // vi fails(F);
    // for (int t = 0; t < F; t++) cin >> fails[t];
    // sort(ALL(fails));

    // if (F == 0) FOUNDANS(res);

    // int i = 0;
    // for (pair<pi,int> batch: batches) {
    //     int l = batch.first.first, r = batch.first.second, p = batch.second;

    //     bool failed = false;
    //     for (; i < F; i++) {
    //         if (fails[i] >= l && fails[i] <= r) {
    //             if (!failed) {failed = true;}
    //         }
    //         else if (fails[i] > r) break;
    //     }
    //     if (failed) res -= p;
    // }

    

    return 0;
}
