// CCC '10 J3 - Punchy
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


int A = 0, B = 0;
int op, n; char x,y;

int& det(char X) {
    if (X == 'A') return A;
    else return B;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while (op != 7) {
        cin >> op;
        switch (op) {
            case 1:
                cin >> x >> n;
                det(x) = n;
                break;
            case 2:
                cin >> x;
                cout << det(x) << endl;
                break;
            case 3:
                cin >> x >> y;
                det(x) += det(y);
                break;
            case 4:
                cin >> x >> y;
                det(x) *= det(y);
                break;
            case 5:
                cin >> x >> y;
                det(x) -= det(y);
                break;
            case 6:
                cin >> x >> y;
                det(x) /= det(y);
                break;
            case 7: return 0;
        }
        
    }

    return 0;
}
