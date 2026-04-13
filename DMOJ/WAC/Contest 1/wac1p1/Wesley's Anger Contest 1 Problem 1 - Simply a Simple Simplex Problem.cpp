// Wesley's Anger Contest 1 Problem 1 - Simply a Simple Simplex Problem
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        long long M; cin >> M;
        // 🙏
        long long l = 1, r = 2000000000LL;
        while (l < r) {
            long long mid = (l + r) >> 1;
            __int128_t e = ( (__int128_t)mid * (mid - 1) ) / 2;
            if (e >= M) r = mid;
            else l = mid + 1;
        }

        cout << l << "\n";

        // float point inprecision :blobsad:
        // long long tosqrt = 1+8*M;
        // long double above = sqrt(tosqrt); above += 1.0;
        // long double ceiling = ceil(above/2);
        // cout << static_cast<int>(ceiling) << "\n";


        // tle who coulda guessed
        // long long twom = 2*M;
        // long long V = 1;
        // while ((V * (V-1)) < twom) {V++;}
        // cout << V << "\n";
    }
    
    return 0;
}
