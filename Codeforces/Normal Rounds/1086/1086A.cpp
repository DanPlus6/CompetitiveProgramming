// A. Bingo Candies
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int n; cin >> n;
        map<int,int> freq; {
            int x;
            for (int i = 0; i < n*n; i++) {
                cin >> x;
                freq[x]++;
            }
        }
        
        bool pos = true;
        int bound = n*n-n;
        for (const pair<int,int> p: freq) {
            if (p.second > bound) {pos = false; break;}
        }

        if (pos) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
