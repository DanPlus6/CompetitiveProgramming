// CCC '20 S1 - Surmising a Sprinter's Speed
#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define endl '\n'

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;

    vector<pair<int,int>> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(ALL(arr));

    double res = 0.0;
    for (int i = 0; i < N-1; i++) {
        res = max(abs((double)arr[i].second-arr[i+1].second)/abs((double)arr[i].first-arr[i+1].first), res);
    }

    cout << res << endl;

    return 0;
}
