// Arcadia Computing Contest 2 P1 - Rejected
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int X,Y,Z; cin >> X >> Y >> Z;
    for (int i = 0; i < 6; i++) {
        int q; cin >> q;
        X -= q;
        if (q) Z--;
        if (q == 100) Y--;
    }
    if (X <= 0 && Y <= 0 && Z <= 0) {
        cout << "MASTER\n";
    } else {cout << "REJECTED AGAIN\n";}
    
    return 0;
}
