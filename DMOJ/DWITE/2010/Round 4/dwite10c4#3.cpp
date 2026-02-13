// DWITE '10 R4 #3 - Binary Weight
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ILOOP(n) for (int i = 0; i < n; i++)
#define endl '\n'
#define FOUNDANS(res) {cout << res << endl; break;}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ILOOP(5) {
        ll N; cin >> N;
        ll lowest = N & -N;
        ll right = N + lowest;
        cout << ((((right ^ N) >> 2) / lowest) | right) << endl;
    }
    
    return 0;
}
