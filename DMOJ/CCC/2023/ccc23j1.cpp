// CCC '23 J1 - Deliv-e-droid
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int P,C; cin >> P >> C;
    int res = 50*P - 10*C;
    if (P > C) res += 500;
    cout << res << endl;

    return 0;
}
