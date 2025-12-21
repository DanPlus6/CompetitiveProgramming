#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> B(N-1);
    for (int i = 0; i < N-1; i++) {cin >> B[i];}

    long long res = B[0] + B.back();
    for (int i = 1; i < N-1; i++) {
        res += min(B[i-1],B[i]);
    }

    cout << res << endl;

    return 0;
}