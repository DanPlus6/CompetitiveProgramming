// CCC '19 J3 - Cold Compress
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define LOOP(n) for (int i = 0; i < n; i++)


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    LOOP(N) {
        string S; cin >> S; int N1 = S.size();
        string res = "";
        char hold = S[0]; int ct = 1;
        for (int j = 1; j < N1; j++) {
            char c = S[i];
            if (c == hold) ct++;
            else if (hold && c != hold) {
                res = res + to_string(ct) + " " + hold + " ";
                hold = c; ct = 1;
            }
            if (j == N1) {
                res = res + to_string(ct) + " " + hold + " ";
            }
        }
        cout << res << endl;
    }
    

    return 0;
}
