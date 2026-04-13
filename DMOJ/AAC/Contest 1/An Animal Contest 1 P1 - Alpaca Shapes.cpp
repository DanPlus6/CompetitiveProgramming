// An Animal Contest 1 P1 - Alpaca Shapes
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int S,R; cin >> S >> R;
    if (S*S > 3.14*(R*R)) {cout << "SQUARE\n";}
    else {cout << "CIRCLE\n";}
    
    return 0;
}
