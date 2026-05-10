// Chores
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    vector<pair<ll,ll>> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());

    ll res = 0;
    ll cur = 0;

    #define a arr[i].first
    #define b arr[i].second
    for (int i = 0; i < N; i++) {
        ll toAdd = ((b%MOD) * cur) % MOD;
        toAdd = (toAdd + (a % MOD) * ((b*(b+1ll)/2ll) % MOD)) % MOD;

        res = (res + toAdd) % MOD;
        cur = (cur + (a % MOD) * (b % MOD)) % MOD;
    }

    cout << res%MOD << '\n';

    return 0;
}
