// Max GCD
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef vector<int> vi;
#define endl '\n'
#define pb push_back


/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    vi arr(N); cin >> arr[0];
    vi prefixGcd = {arr[0]}; {
        for (int i = 1; i < N; i++) {
            cin >> arr[i];
            prefixGcd.pb(gcd(arr[i], prefixGcd[i-1]));
        }
    }

    vi suffixGcd(N); suffixGcd[N-1] = arr[N-1]; {
        for (int i = N-2; i >= 0; i--) {
            suffixGcd[i] = gcd(arr[i],suffixGcd[i+1]);
        }
    }

    int res = max(suffixGcd[1],prefixGcd[N-2]);
    for (int i = 1; i < N-1; i++) {
        res = max(res, gcd(prefixGcd[i-1],suffixGcd[i+1]));
    }

    cout << res << endl;

    return 0;
}
