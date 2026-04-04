// CCC '25 J5 - Connecting Territories
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int R,C,M; cin >> R >> C >> M;
    if ((R*C) <= M) {
        long long res = 0;
        for (int r = 0; r < R; r++) {
            res += (r*C) % M + 1;
        }
        cout << res << "\n"; return 0;
    }

    // orz bruce
    vector<long long> pre(C,0);
    for (int r = 0; r < R; r++) {
        vector<long long> cur(C,0);
        for (int c = 0; c < C; c++) {
            long long cell = (r*C+c) % M + 1;
            if (c == 0) {
                cur[c] = min(pre[c],pre[c+1]) + cell;
            }
            else if (c < C-1) {
                cur[c] = min({pre[c-1],pre[c],pre[c+1]}) + cell;
            }
            else {
                cur[c] = min(pre[c-1],pre[c]) + cell;
            }
        }
        swap(pre,cur);
    }
    
    cout << *min_element(pre.begin(),pre.end()) << "\n";

    return 0;
}
