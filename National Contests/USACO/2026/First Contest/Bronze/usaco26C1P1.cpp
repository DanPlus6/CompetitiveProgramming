// USACO 2026 First Contest, Bronze Problem 1. Chip Exchange
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int t = 0, T = (cin >> T,T); t < T; t++) {
        long long A,B,CA,CB,fA; cin >> A >> B >> CA >> CB >> fA;
        if (A>=fA) {cout << "0\n"; continue;}

        cout << max(0ll,(long long)(((fA-A+CA-1)/CA) * CB - B)) << "\n";
    }
    
    return 0;
}

