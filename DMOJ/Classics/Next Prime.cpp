// Next Prime
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    for (int x = N; x <= INT_MAX; x++) {
        if (isPrime(x)) {
            cout << x << endl;
            return 0;
        }
    }

    return 0;
}
