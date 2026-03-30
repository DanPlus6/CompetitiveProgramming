// CCC '09 J2 - Old Fishin' Hole
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int B,N,Y,T; cin >> B >> N >> Y >> T;
    int res = 0;
    
    for (int b = 0; b <= T/B; b++) {
        for (int n = 0; n <= T/N; n++) {
            for (int y = 0; y <= T/Y; y++) {
                if ((b || n || y) && (b*B + n*N + y*Y <= T)) {
                    cout << b << " Brown Trout, " << n << " Northern Pike, " << y << " Yellow Pickerel\n";
                    res++;
                }
            }
        }
    }

    cout << "Number of ways to catch fish: " << res << endl;


    return 0;
}
