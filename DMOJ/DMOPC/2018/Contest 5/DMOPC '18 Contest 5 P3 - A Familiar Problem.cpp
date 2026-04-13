// DMOPC '18 Contest 5 P3 - A Familiar Problem
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
    vl cute(N);
    ILOOP(N) cin >> cute[i];
    
    int res = 0;
    ll csum = 0;
    for (int r = 0, l = 0; r < N; r++) {
        if (csum < M) csum += cute[r];
        if (csum < M) res = max(r-l+1,res);
        else {
            while (csum >= M && l <= r) {
                csum -= cute[l];
                l++;
            }
        }
    }

    cout << res << endl;

    return 0;
}
