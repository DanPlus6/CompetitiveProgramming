// A. Another Puzzle from Papyrus
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    for (int N,C, suma, sumb, dif, res; T--;) {
        cin >> N >> C;
        vi a(N), b(N);
        suma = 0; sumb = 0;
        for (int i=0;i<N;i++) {cin >> a[i]; suma += a[i];}
        for (int i=0;i<N;i++) {cin >> b[i]; sumb += b[i];}
        dif = suma-sumb;
        if (dif < 0) {cout << -1 << endl; continue;}

        res = INT_MAX;
        bool noreoder = true;
        for (int i=0;i<N;i++) {
            if (a[i] < b[i]) {
                noreoder = false;
                break;
            }
        }
        if (noreoder) res = min(dif, res);

        sort(ALL(a));
        sort(ALL(b));
        bool reoder = true;
        for (int i=0;i<N;i++) {
            if (a[i] < b[i]) {
                reoder = false;
                break;
            }
        }
        if (reoder) res = min(C + dif, res);

        cout << ((res != INT_MAX) ? res : -1) << endl;
    }

    return 0;
}
