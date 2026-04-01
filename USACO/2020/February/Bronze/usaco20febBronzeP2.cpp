// USACO 2020 February Bronze P2 - Mad Scientist
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<char> A(N);
    vector<char> B(N);
    vector<int> dif(N,0);
    for (int i = 0; i < N; i++) {cin >> A[i];}
    for (int i = 0; i < N; i++) {
        char tmp; cin >> tmp;
        B[i] = tmp;
        if (tmp != A[i]) {dif[i] = 1;}
    }

    int res = 0;
    int left = 0;
    bool active = false;
    for (int i = 0; i < N; i++) {
        if (dif[i]) {
            left = i;
            active = true;
        } else if (active) {
            res += i-left;
            active = false;
        }
    }
    if (active) {res += N-left;}
    cout << res << endl;

    return 0;
}
