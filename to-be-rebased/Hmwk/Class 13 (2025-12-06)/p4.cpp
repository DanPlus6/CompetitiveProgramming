// CCC '20 S1 - Surmising a Sprinter's Speed
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long N;
    cin >> N;

    // long long t,d;
    // cin >> t >> d;
    
    // double res = 0.0;
    // for (long long i = 1; i < N; i++) {
    //     long long ct, cd;
    //     cin >> ct >> cd;

    //     if (ct != t) { res = max(abs((double)cd-d)/abs((double)ct-t),res); };
    //     t = ct; d = cd;
    // }

    vector<vector<long long>> arr(N, vector<long long>(2));
    for (long long i = 0; i < N; i++) {
        long long t,d;
        cin >> t >> d;
        arr[i] = {t, d};
    }

    sort(arr.begin(), arr.end());

    double res = 0.0;
    for (long long i = 0; i < N-1; i++) {
        res = max(abs((double)arr[i][1]-arr[i+1][1])/abs((double)arr[i][0]-arr[i+1][0]),res);
    }

    cout << res << endl;

    return 0;
}
