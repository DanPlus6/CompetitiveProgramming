// Sword Art Online Judge
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N; cin >> N;
    __int128_t n = N, n2 = N*N;
    n = n * (n2 * (n2 * (21 + 21*n + 6*n2) - 7) + 1) / 42 % 1000000000;
    cout << (int)n << "\n";
    
    return 0;
}
