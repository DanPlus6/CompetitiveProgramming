// CCC '11 J5 - Unfriend
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vi friends = {1,1,1,1,1,1,1};
    for (int i = 1; i < N; i++) {
        int f; cin >> f;
        friends[f] *= (friends[i] + 1);
    }

    cout << friends[N] << endl;

    return 0;
}
