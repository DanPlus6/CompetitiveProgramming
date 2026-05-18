// DMOPC '21 Contest 1 P1 - Partial Game
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define PRIMLOOP(N) for (int i = 0; i < N; i++)

/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    vi A(N); PRIMLOOP(N) cin >> A[i];

    ll duke = 0, alice = 0;
    PRIMLOOP(N) {
        if (A[i] & 1) alice += (A[i] + 1ll)/2ll;
        else duke += (A[i] + 1ll)/2ll;
    }

    cout << (duke > alice ? "Duke\n" : "Alice\n");

    return 0;
}
