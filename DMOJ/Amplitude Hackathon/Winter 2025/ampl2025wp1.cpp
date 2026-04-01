// Amplitude Hackathon Winter '25 Problem 1 - One-Letter Variable Names
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (uint16_t i = 0, N = (cin >> N,N); i < N; i++){
        char S[52]; cin >> S;
        if (strlen(S) == 1) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}
