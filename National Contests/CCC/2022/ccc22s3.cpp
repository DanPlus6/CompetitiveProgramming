// CCC '22 S3 - Good Samples
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
typedef vector<ll> vl;
#define endl '\n'
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define ILOOP(arr) for (int &i: arr)
#define pb push_back


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll N,M,K; cin >> N >> M >> K;
    vl res;
    PRIMLOOP(N) {
        int rem = N - i - 1;
        int cur = min(K-rem, M);
        if (cur <= 0) break;

        int val;
        if (cur > i) {
            val = min(i+1, M);
            cur = val;
        } else
            val = res[i-cur];
        
        res.pb(val);
        K -= cur;
    }

    if (!K && res.size() == N) {
        ILOOP(res) cout << i << ' ';
        cout << endl;
    } else cout << -1 << endl;

    return 0;
}
