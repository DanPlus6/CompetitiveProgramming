// CCC '23 S2 - Symmetric Mountains
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;


/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    vi H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    
    vl even(N+1,0), odd(N+1,0);
    cout << "0 ";
    for(int len=2; len <= N; len++){
        ll res = LONG_LONG_MAX;
        if (len & 1) {
            for (int l = 0, r = len-1; r < N; l++, r++) {
                odd[l] = odd[l+1] + abs(H[r]-H[l]);
                res = min(res,odd[l]);
            }
        } else {
            for (int l = 0, r = len-1; r < N; l++, r++) {
                even[l] = even[l+1] + abs(H[r]-H[l]);
                res = min(res,even[l]);
            }
        }
        cout << res << (len != N ? " " : "\n");
    }

    return 0;
}
