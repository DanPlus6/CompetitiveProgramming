// DWITE '11 R5 #5 - Binary Weight
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ILOOP(n) for (int i = 0; i < n; i++)
#define endl '\n'
#define FOUNDANS(res) {cout << res << endl; break;}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ILOOP(5) {
        ll N; cin >> N;
        ll lowest = N & -N;
        ll right = N + lowest;
        cout << ((((right ^ N) >> 2) / lowest) | right) << endl;

        // int Ncp = N;
        // int Nct = 0;
        // // int Nct = __builtin_popcount(N);
        // while (Ncp) {
        //     Ncp &= (Ncp-1);
        //     Nct++;
        // }

        // for (int res = N+1;;res++) {
        //     // if (__builtin_popcount(res) == Nct) FOUNDANS(res)
        //     int rescp = res;
        //     int ct = 0;
        //     while (rescp) {
        //         rescp &= (rescp-1);
        //         ct++;
        //     }
        //     if (ct == Nct) FOUNDANS(res)
        // }
    }
    
    return 0;
}
