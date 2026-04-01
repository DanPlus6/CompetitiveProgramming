// CCC '14 J3 - Double Dice
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ILOOP(n) for (int i = 0; i < n; i++)


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N; cin >> N;
    int A = 100, D = 100;
    ILOOP(N) {
        int a,d; cin >> a >> d;
        if (a < d) A -= d;
        else if (d < a) D -= a;
    }

    cout << A << endl << D << endl;

    return 0;
}
