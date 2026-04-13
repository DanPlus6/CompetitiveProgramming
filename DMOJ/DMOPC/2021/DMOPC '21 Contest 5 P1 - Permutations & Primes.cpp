// DMOPC '21 Contest 5 P1 - Permutations & Primes
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'
#define pb push_back
#define FOUNDANS(res) {cout << res << endl; return 0;}


/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    if (N == 1) FOUNDANS(1)
    else if (N < 5) FOUNDANS(-1)
    
    vi arr;
    for (int i = 1; i <= N; i += 2) {
        if (i == 7) continue;
        arr.pb(i);
    }

    if (N >= 7) {
        arr.pb(7);
        arr.pb(2);
    }

    for (int i = 4; i <= N; i += 2) arr.pb(i);

    if (N > 1 && N < 7) arr.pb(2);

    for (int i = 1; i <= N; i++) cout << arr[i-1] << " \n"[i == N];

    return 0;
}
