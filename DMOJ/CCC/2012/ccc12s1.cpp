// CCC '12 S1 - Don't pass me the ball!
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FOUNDANS(res) {cout << res << endl; return 0;}


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    if (N == 4) FOUNDANS(1)
    else if (N < 4) FOUNDANS(0)
    else {
        cout << (N-1)*(N-2)*(N-3) / 6 << endl;
    }

    return 0;
}
