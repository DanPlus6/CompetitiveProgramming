// COCI '07 Contest 4 #2 Veci
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FOUNDANS(res) {cout << res << endl; return 0;}

/* Orz bruce */
int main() {
    string X; cin >> X;

    int swapLeft = -1;
    for (int i = X.size() - 2; i >= 0; i--) {
        if (X[i] < X[i + 1]) {
            swapLeft = i;
            break;
        }
    }

    if (swapLeft == -1) FOUNDANS(0)

    int swapRight = swapLeft + 1;
    for (int i = swapLeft + 2; i < (int)X.size(); i++) {
        if (X[i] > X[swapLeft] && X[i] <= X[swapRight])
            swapRight = i;
    }

    swap(X[swapLeft], X[swapRight]);

    sort(X.begin()+swapLeft+1, X.end());

    cout << X << endl;
    return 0;
}

