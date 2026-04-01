// CCC '11 J2 - Who Has Seen The Wind
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int H,M; cin >> H >> M;
    for (int t = 1; t <= M; t++) {
        int A = -6*pow(t,4) + H*pow(t,3) + 2*t*t + t;
        if (A <= 0) {
            cout << "The balloon first touches ground at hour:\n" << t << endl;
            return 0;
        }
    }

    cout << "The balloon does not touch ground in the given time.\n";

    return 0;
}
