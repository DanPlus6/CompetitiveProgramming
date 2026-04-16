// B. Cyclists
#include <bits/stdc++.h>
using namespace std;

#define ALL(i) i.begin(), i.end()
#define int long long

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; 
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n,p,k,m;
        cin >> n >> k >> p >> m;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int target_cost = a[p - 1];
        vector<int> Af;
        for (int i = 0; i < p - 1; ++i) {
            Af.push_back(a[i]);
        }

        vector<int> B;
        for (int i = 0; i < n; ++i) {
            if (i != p - 1) {
                B.push_back(a[i]);
            }
        }

        int cost1 = 0;
        int cards_to_play_1 = max(0ll, p - k);
        if (cards_to_play_1 > 0) {
            sort(ALL(Af));
            for (int i = 0; i < cards_to_play_1; ++i) {
                cost1 += Af[i];
            }
        }

        int first_play_cost = cost1 + target_cost;
        bool cont = true;
        if (m < first_play_cost) {
            cout << 0 << "\n";
            cont = false;
        }

        if (cont) {
            int cost_steady = 0;
            int cards_to_play_steady = max(0ll, n - k);
            if (cards_to_play_steady > 0) {
                sort(ALL(B));
                for (int i = 0; i < cards_to_play_steady; ++i) {
                    cost_steady += B[i];
                }
            }

            int steady_play_cost = cost_steady + target_cost;
            int remaining_m = m - first_play_cost;
            int additional_plays = remaining_m / steady_play_cost;

            cout << 1 + additional_plays << "\n";
        }
    }

    return 0;
}
