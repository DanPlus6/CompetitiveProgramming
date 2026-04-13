// Sword Art Online Judge
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // 🏌️🕳️1️⃣⛳️
    int N; cin >> N;
    __int128_t n = N, n2 = N*N;
    n = n * (n2 * (n2 * (21 + 21*n + 6*n2) - 7) + 1) / 42 % 1000000000;
    cout << (int)n << "\n";


    // twin there was no need to do allat🥀
    // static const long long MOD = 1000000000LL;
    // int N; cin >> N;
    // long long n = N;
    // long long n2 = n * n;
    // long long n3 = n2 * n;
    // long long n4 = n2 * n2;

    // long long big = 3*n4 + 6*n3 - 3*n + 1;

    // long long factors[4] = {
    //     N,
    //     N+1,
    //     2*N+1,
    //     (long long)big
    // };

    // long long denom = 42;
    // for (int i = 0; i < 4 && denom > 1; ++i) {
    //     long long f = gcd(factors[i], denom);
    //     factors[i] /= f;
    //     denom /= f;
    // }

    // long long res = 1;
    // // (a*b) MOD C = ((a MOD C)*(b MOD C)) MOD
    // //                                   A           b   MOD C    mod C         
    // for (int i = 0; i < 4; ++i) {res = (res * (factors[i] % MOD)) % MOD;}

    // cout << (long long)(res % MOD) << "\n";
    
    return 0;
}
