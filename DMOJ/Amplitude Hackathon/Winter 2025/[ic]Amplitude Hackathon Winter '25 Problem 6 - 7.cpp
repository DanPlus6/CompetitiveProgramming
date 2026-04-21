// Amplitude Hackathon Winter '25 Problem 6 - 7
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // 🕕️🕖️ (for those who dont get the joke, the clock's are pointing to 6 o clock and 7 o clock respectively)

    // 🙏

    // int N; cin >> N;
    // vector<long long> dp(67, 0), next_dp(67, 0);
    // dp[0] = 1;

    // // what the duck am I doing
    // // publicly declaring my intention to cheat was a calculated risk, but **boy am I bad at math**
    // long long res = 0;
    // for (int len = 1; len <= N; ++len) {
    //     fill(next_dp.begin(), next_dp.end(), 0);

    //     for (int r = 0; r < 67; ++r) {
    //         if (dp[r] == 0) continue;

    //         int r6 = (10 * r + 6) % 67;
    //         int r7 = (10 * r + 7) % 67;

    //         next_dp[r6] += dp[r];
    //         next_dp[r7] += dp[r];
    //     }

    //     dp.swap(next_dp);

    //     res += dp[0];
    // }

    // cout << res % 67676767 << "\n";
    return 0;
}
