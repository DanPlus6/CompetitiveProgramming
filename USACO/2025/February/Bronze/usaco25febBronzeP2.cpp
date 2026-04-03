// USACO 2025 February Bronze P2 - Making Mexes
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef vector<int> vi;
#define endl '\n'
#define LOOP(n) for (int _ = 0; _ < n; _++)


/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    
    vi freq(N+1,0); {
        int ai;
        LOOP(N) {
            cin >> ai;
            freq[ai]++;
        }
    }

    int missing = 0;
    for (int i = 0; i <= N; i++) {
        cout << max(missing, freq[i]) << endl;
        if (!freq[i]) missing++;
    }

    return 0;
}

