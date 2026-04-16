// DMOPC '18 Contest 2 P4 - Damage Output
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define ILOOP(n) for (int i = 0; i < n; i++)
#define pb push_back
#define FOUNDANS(res) cout << res << endl; return 0

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; long long M; cin >> N >> M;
    long long sum = 0;
    vl dps(N);
    ILOOP(N) {
        int tmp; cin >> tmp;
        dps[i] = tmp;
        if (tmp >= M) {FOUNDANS(1);}
        sum += tmp;
    }

    if (sum < M) {FOUNDANS(-1);}
    
    int res = N;
    ll csum = dps[0];
    int l = 0, r = 1;
    while (r < N && l < r) {
        if (csum < M) {
            csum += dps[r];
            r++;
        }
        else {
            res = min(r-l,res);
            csum -= dps[l];
            l++;
        }
    }

    cout << res << endl;

    return 0;
}
