// The Mirror
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for (int n = 0; n < N; n++) {      
        int l,r; cin >> l >> r;
        if (l>r) swap(l,r);
        vector<bool> sieve(r+1,true); sieve[0] = sieve[1] = false;

        for (int i = 2; i*i <= r; i++) {
            if (sieve[i]) {
                for (int j = i*i; j <= r; j+=i) {
                    sieve[j] = false;
                }
            }
        }

        int res = 0;
        for (int i = l; i < r; i++) {if (sieve[i]) res++;}
        cout << res << "\n";
    }

    return 0;
}
