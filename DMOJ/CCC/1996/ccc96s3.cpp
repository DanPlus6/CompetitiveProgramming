// CCC '96 S3 - Pattern Generator
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)


int n,k;
void func(string cur, int rem) {
    if (n-cur.length() < rem) return;
    if (cur.length() == n) {
        if (!rem) cout << cur << endl;
        return;
    }
    
    func(cur + '1', rem-1);
    func(cur + '0', rem);
}

/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        cout << "The bit patterns are\n";
        
        cin >> n >> k;
        if (!k) {
            LOOP(n) cout << '0';
            cout << endl;
            if (T) cout << endl;
            continue;
        } else if (!n) {
            cout << endl;
            if (T) cout << endl;
            continue;
        } else if (n == k) {
            LOOP(n) cout << '1';
            cout << endl;
            if (T) cout << endl;
            continue;
        }

        func("", k);

        if (T) cout << endl;
    }

    return 0;
}
