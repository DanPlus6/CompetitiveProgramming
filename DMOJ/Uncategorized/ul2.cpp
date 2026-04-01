// Intertwined Strings
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int myint;

string S,T;
set<string> res;
void solve(myint i = 0, myint j = 0, string run = "") {
    if (i == S.length() && j == T.length()) {
        res.emplace(run);
        return;
    }

    if (i < S.length()) solve(i+1, j, run + S[i]);
    if (j < T.length()) solve(i, j+1, run + T[j]);

}

/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> S >> T;
    solve();

    for (auto &s: res) cout << s << endl;

    return 0;
}
