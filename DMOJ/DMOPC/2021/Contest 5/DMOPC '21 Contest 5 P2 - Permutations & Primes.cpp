// DMOPC '21 Contest 5 P2 - Permutations & Primes
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    if (N == 1) cout << 1 << endl;
    else if (N == 2) cout << -1 << endl;
    else {
        cout << "1 3 2";
        for (int i = 4; i <= N; i++) cout << " " << i;
        cout << endl;
    }

    return 0;
}
