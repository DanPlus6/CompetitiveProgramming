// B. Crimson Triples
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    for (ll N, res; T--;) {
        cin >> N;
        res = 0;
        for (ll cnt, b=1;b<=N;++b) {
            cnt = N/b;
            res += cnt*cnt;
        }
        cout << res << endl;
    }

    return 0;
}
