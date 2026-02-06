// CCC '01 J1 - Dressing Up
#include <bits/stdc++.h>
using namespace std;

#define PRIMLOOP(N) for (int n = 0; n < N; n++)
#define SECLOOP(M) for (int m = 0; m < M; m++)
#define RLOOP(N) for (int n = N; n >= 0; n--)

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int H; cin >> H;

    int half = H/2;
    PRIMLOOP(half) {
        int numAsterisk = n*2+1;
        SECLOOP(numAsterisk) {cout << "*";}
        SECLOOP((H-numAsterisk)*2) {cout << ' ';}
        SECLOOP(numAsterisk) {cout << '*';}
        cout << '\n';
    }
    
    PRIMLOOP(H*2) {cout << "*";}
    cout << '\n';

    RLOOP(half-1) {
        int numAsterisk = n*2+1;
        SECLOOP(numAsterisk) {cout << "*";}
        SECLOOP((H-numAsterisk)*2) {cout << ' ';}
        SECLOOP(numAsterisk) {cout << '*';}
        cout << '\n';
    }
}
