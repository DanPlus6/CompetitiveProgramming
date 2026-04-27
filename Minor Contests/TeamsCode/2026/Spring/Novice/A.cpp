// Digits
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define FOUNDANS(res) {cout << res << endl; return 0;}
#define CLOOP(s) for (char c: s)

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string N; cin >> N;

    int digSum = 0;
    CLOOP(N) digSum += c - '0';

    if (digSum % 9 != 0) FOUNDANS(-1);

    string perm = N;
    sort(ALL(perm));

    do {
        if (perm[0] != '0') {
            FOUNDANS(perm)
        }
    } while (next_permutation(ALL(perm)));

    FOUNDANS(-1)
}
