// GFSSOC '15 Fall J5 - Nightmare-a-thon
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N,Q; cin >> N >> Q;
    vi episodes(N+2);
    
    for (int i = 1; i <= N; i++) cin >> episodes[i];
    
    // fahhhhhhhhhh
    vi pma(N+2, 0), sma(N+2, 0), pmfa(N+2,0), smfa(N+2,0);
    for (int i = 1; i <= N; i++) {
        if (episodes[i] > pma[i-1]) {
            pma[i] = episodes[i];
            pmfa[i] = 1;
        } else if (episodes[i] == pma[i-1]) {
            pma[i] = pma[i-1];
            pmfa[i] = pmfa[i-1] + 1;
        } else {
            pma[i] = pma[i-1];
            pmfa[i] = pmfa[i-1];
        }
    }
    
    for (int i = N; i >= 1; i--) {
        if (episodes[i] > sma[i+1]) {
            sma[i] = episodes[i];
            smfa[i] = 1;
        } else if (episodes[i] == sma[i+1]) {
            sma[i] = sma[i+1];
            smfa[i] = smfa[i+1] + 1;
        } else {
            sma[i] = sma[i+1];
            smfa[i] = smfa[i+1];
        }
    }

    for (int q = 0; q < Q; q++) {
        int a,b; cin >> a >> b;

        if (pma[a-1] > sma[b+1]) {
            cout << pma[a-1] << " " << pmfa[a-1] << endl;
        } else if (pma[a-1] < sma[b+1]) {
            cout << sma[b+1] << " " << smfa[b+1] << endl;
        } else {
            cout << sma[b+1] << " " << pmfa[a-1]+smfa[b+1] << endl;
        }
    }

    return 0;
}
