// Lights On
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // TWINNN YOU CANNOT BE SERIOUS
    // I GOT THE QUESTION WRONG CUZ I MIXED SCANF AND CIN
    // I COULDA GOTTEN ONE MORE QUESTION CORRECT 😭😭😭
    // char S[1000000]; scanf("%999999s",S);
    string S; cin >> S;
    int N = S.size();
    int K; cin >> K;

    int l = 0;
    int off = 0;
    int res = 0;
    for (int r = 0; r < N; r++) {
        if (S[r] == '0') {
            off++;
        }
        
        while (off > K) {
            if (S[l] == '0') {
                off--;
            }
            l++;
        }

        res = max(res,r-l+1);
    }

    cout << res << endl;
    return 0;
}
