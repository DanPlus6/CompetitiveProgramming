// COCI '08 Contest 2 #3 Perket
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

short N; int res = INT_MAX;
int ing[11][2];
void bruteForce_blobcreep_(int idx, int sour = 1, int bitter = 0, bool taken = false) {
    if (idx == N) {
        if (taken) res = min(res,abs(sour-bitter)); 
        return;
    }

    bruteForce_blobcreep_(idx+1, sour, bitter, taken);
    bruteForce_blobcreep_(idx+1, sour * ing[idx][0], bitter + ing[idx][1], true);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (short i = 0; i < N; i++) cin >> ing[i][0] >> ing[i][1];
    if (N == 1) {
        cout << abs(ing[0][0] - ing[0][1]) << endl;
        return 0;
    }
    
    bruteForce_blobcreep_(0);

    cout << res << endl;

    return 0;
}
