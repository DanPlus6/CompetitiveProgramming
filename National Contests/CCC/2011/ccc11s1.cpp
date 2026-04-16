// CCC '11 S1 - English or French?
#include <bits/stdc++.h>
using namespace std;

#define LOOP(n) for (int _ = 0; _ < n; _++)
#define CLOOP(s) for (char c: s)


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N; cin.ignore(); // ohhh so cin doesn't read the \n character after finishing reading N so it consumes a loop iteration 😭
    int S = 0, T = 0;
    LOOP(N) {
        string ln;
        getline(cin,ln);
        
        CLOOP(ln) {
            if (c == 's' || c == 'S') S++;
            else if (c == 't' || c == 'T') T++;
        }
    }

    if (T > S) cout << "English\n";
    else cout << "French\n";

    return 0;
}
