// CCC '20 J3 - Art
#include <bits/stdc++.h>
using namespace std;

typedef long long l;
#define endl '\n'
#define LOOP(n) for (int i = 0; i < n; i++)


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int lx=100,ly=100,mx=0,my=0;
    LOOP(N) {
        int x,y; cin >> x; cin.ignore(1); cin >> y;
        lx = min(x,lx);
        ly = min(y,ly);
        mx = max(x,mx);
        my = max(y,my);
    }
    cout << lx-1 << "," << ly-1 << endl;
    cout << mx+1 << "," << my+1 << endl;

    return 0;
}
