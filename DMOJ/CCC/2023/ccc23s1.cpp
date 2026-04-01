// CCC '23 S1 - Trianglane
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n';


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vi r1(N);
    vi r2(N);
    for (int i = 0; i < N; i++) { cin >> r1[i]; } 
    for (int i = 0; i < N; i++) { cin >> r2[i]; }
    
    // orz bruce
    int res = 0;
    for (int i = 0; i < N; i++) {
        if (r1[i]) res += 3;
        if (r2[i]) res += 3;
        if (i > 0 && r1[i] && r1[i-1]) res -= 2;
        if (i > 0 && r2[i] && r2[i-1]) res -= 2;
        if (!(i&1) && r1[i] && r2[i]) res -= 2;
    }
    cout << res << endl;

    return 0;
}
