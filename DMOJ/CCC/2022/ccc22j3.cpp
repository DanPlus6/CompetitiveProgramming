// CCC '22 J3 - Harp Tuning
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string S; cin >> S;
    bool tuning = false;
    for (char &i: S) {
        if (i == '+') cout << " tighten ";
        else if (i == '-') cout << " loosen ";
        else if ('0' <= i && i <= '9') {cout << i; tuning = true;}
        else if (tuning) {cout << "\n" << i; tuning = false;}
        else cout << i;
    }

    return 0;
}
