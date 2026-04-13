// Google Code Jam '22 Round 1B Problem A - Pancake Deque
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int D; cin >> D;
        deque<int> pc;
        for (int d = 0; d < D; d++) {int cake; cin >> cake; pc.emplace_back(cake);}
            if (sizeof(set<int>(pc.begin(),pc.end())) == 1) {printf("Case #%d: %d\n",t+1,D); continue;}

            int res = 0, hold = 0;

            while (!pc.empty()) {
                int v;
                if (pc.front() < pc.back()) {v = pc.front(); pc.pop_front();}
                else {v = pc.back(); pc.pop_back();}

                if (v >= hold) {res++; hold = v;}
            }
        printf("Case #%d: %d\n",t+1,res);
    }

    return 0;
}
