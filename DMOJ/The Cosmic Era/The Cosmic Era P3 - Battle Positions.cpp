// The Cosmic Era P3 - Battle Positions
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int I; cin >> I;
    int N; cin >> N;
    int J; cin >> J;

    vector<int> setup(I,0);
    int xi,xf,k; cin >> xi >> xf >> k;
    for (int i = xi-1; i < xf; i++) {
        setup[i] = k;
    }
    if (J == 1) {int res = 0; for (int &i: setup) {if (i < N) {res++;}}; cout << res << "\n"; return 0;}
    vector<int> dif(I+1); dif[0] = setup[0];
    for (int i = 1; i < I; i++) {
        dif[i] = setup[i] - setup[i-1];
    }
    for (int j = 1; j < J; j++) {
        int xi,xf,k; cin >> xi >> xf >> k;
        dif[xi-1] += k; dif[xf] -= k;
    }

    int res = (dif[0] < N) ? 1 : 0, hold = dif[0];
    for (int i = 1; i < I; i++) {
        hold += dif[i];
        if (hold < N) {res++;}
    }
    cout << res << "\n";



    // naieve O(I*J)
    // vector<int> stations(I,0);
    // for (int j = 0; j < J; j++) {
    //     int xi,xf,k; cin >> xi >> xf >> k;
    //     for (int i = xi; i <= xf; i++) {stations[i]+=k;}
    // }

    // int res = 0;
    // for (int &i: stations) {if (i < N) {res++;}}
    // cout << res << "\n";
    
    return 0;
}
