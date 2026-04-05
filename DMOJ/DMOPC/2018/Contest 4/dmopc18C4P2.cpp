// DMOPC '18 Contest 4 P2 - Dr. Henri and Responsibility
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

// typedef vector<int> vi;
// typedef vector<bool> vb;
// #define endl '\n'
// #define ALL(x) x.begin(), x.end()
#define PRIMLOOP(N) for (int i = 0; i < N; i++)

// constexpr int INF = 0x3F3F3F3F;



static bitset<1000005> dp;

/* orz relyks */
int main() {
    int N; scanf("%d", &N);

    int total = 0;
    dp[0] = 1;
    PRIMLOOP(N) {
        int val; scanf("%d", &val);
        total += val;
        dp |= (dp << val);
    }

    int res = total;
    for (int i = 0; i <= total; i++) {
        if (dp[i]) {
            int diff = total - 2 * i;
            if (diff < 0) {
                diff = -diff;
            }
            res = min(res, diff);
        }
    }

    printf("%d\n", res);

    return 0;
}


// /* Orz bruce */
// int main() {
//     ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

//     int N; cin >> N;
//     vi A(N); int total = 0;
//     PRIMLOOP(N) {cin >> A[i]; total += A[i];}
    
//     vb dp(total+1,false);
    
//     dp[0] = true;
//     PRIMLOOP(N) {
//         for (int s = total; s >= A[i]; s--) {
//             int peek = s - A[i];
//             if (dp[peek]) dp[s] = true;
//         }
//     }

//     int res = INF;
//     for (int s = 0; s <= total; s++) {
//         if (dp[s]) res = min(res, abs(total - 2*s));
//     }

//     cout << res << endl;

//     return 0;
// }
