// B. Right Maximum
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef vector<int> vi;
#define endl '\n'
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define PRIMLOOP(N) for (int i = 0; i < N; i++)


/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    LOOP(T) {
        int n; cin >> n;
        vi a(n);
        PRIMLOOP(n) {
            cin >> a[i];
        }

        int ops = 0;
        int cur = 0;
        PRIMLOOP(n) {
            if (a[i] >= cur) {ops++; cur = a[i];}
        }

        cout << ops << endl;
    }

    return 0;
}

