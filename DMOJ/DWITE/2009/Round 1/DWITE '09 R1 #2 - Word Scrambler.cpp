// DWITE '09 R1 #2 - Word Scrambler
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)


/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string S;
    LOOP(5) {
        cin >> S;
        sort(ALL(S));
        do {
            cout << S << endl;
        } while (next_permutation(ALL(S)));
    }

    return 0;
}
