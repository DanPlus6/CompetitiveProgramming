// Palindromic Integer Partition
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;
typedef vector<int> vi;
#define pb push_back
#define endl '\n'


/* 🤯 */
int main() {
    ll N; cin >> N;

    cout << (1ll << (N/2)) << endl;
    // cout << pow(2ll,(ll)(N/2)) << endl;
}



/* ---------------- working recursion + memoization solution ------------- */
// ll memoiz[64];
// ll fun(ll rem) {
//     if (memoiz[rem]) return memoiz[rem];

//     ll res = 1;
//     for (int i = 1; i <= rem/2; i++) {
//         res += fun(rem - 2ll*i);
//     }

//     memoiz[rem] = res;
//     return res;
// }

// int main() {
//     int N; cin >> N;

//     cout << fun(N) << endl;
// }


/* ------------------------ old solution, TLE --------------------------- */
// int N, res = 1;
// /* orz bruce */
// void fun(int sum, vi sol) {
//     if (sum == N) {
//         for (int i = 0; i < sol.size()/2; i++) {
//             if (sol[i] != sol[sol.size()-1-i]) return;
//         }

//         res++;
//         return;
//     }

//     for (int cur = 1; cur + sum <= N; cur++) {
//         vi tmp = sol; tmp.pb(cur);
//         fun(sum+cur, tmp);
//     }
// }

// int main() {
//     cin >> N;

//     for (int i = 1; i < N; i++) {
//         fun(i, {i});
//     }

//     cout << res << endl;
// }
