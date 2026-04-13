// 16 BIT S/W ONLY
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        long A,B; cin >> A >> B;
        long long P; cin >> P;
        if (A*B == P) {cout << "POSSIBLE DOUBLE SIGMA\n";}
        else {cout << "16 BIT S/W ONLY\n";}
    }
}
