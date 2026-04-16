// A. Passing the Ball
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef set<int> si;
#define endl '\n'
#define LOOP(n) for (int _ = 0; _ < n; _++)

/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T; 
    LOOP(T) {
        si received;

        int N; string S;
        cin >> N >> S;

        int i = 0; received.emplace(0);
        for (int j = 0; j < N; j++) {
            if (S[i] == 'R') {
                i++;
            } else {
                i--;
            }
            received.emplace(i);
        }

        cout << received.size() << endl;
    }

    return 0;
}
