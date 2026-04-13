// Wesley's Anger Contest Reject 2 - 🥕suba
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ILOOP(n) for (int i = 0; i < n; i++)


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    ILOOP(N) {
        int A,B; cin >> A >> B;
        cout << A + B - 1 << endl;
    }

    return 0;
}
