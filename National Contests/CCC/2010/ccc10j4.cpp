// CCC '10 J4 - Global Warming
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define pb push_back


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        if (n == 1) {cin >> n; cout << "0\n"; continue;}

        int last; cin >> last;
        vi dif;
        LOOP(n-1) {
            int tmp; cin >> tmp;
            dif.pb(tmp-last);
            last = tmp;
        }

        vi seq; seq.pb(dif[0]);
        int I = 1;
        for (int i = 0; i < dif.size() && I < dif.size() && seq.size() < dif.size(); i++) {
            if (seq[i % seq.size()] != dif[i]) {
                seq.pb(dif[I]);
                I++;
                i = 0;
            }
        }

        cout << seq.size() << endl;
    }

    return 0;
}
