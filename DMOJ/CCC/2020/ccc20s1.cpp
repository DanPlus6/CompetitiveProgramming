// CCC '20 S1 - Surmising a Sprinter's Speed
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;

    vector<pair<int,int>> arr(N); // initialize vector of empty pairs to store input
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second; // read T,X pairs directly into the intialized empty pairs
    }

    sort(arr.begin(), arr.end()); // sort pairs in ascending order by time as lowest time is "starting position"

    double res = 0.0; // value to keep track of maxspeed
    for (int i = 0; i < N-1; i++) {
        // get current speed
        double speed = abs((double)arr[i].second - arr[i+1].second) / abs((double)arr[i].first - arr[i+1].first);
        res = max(speed, res); // update max speed value if current speed is greater
    }

    cout << res << '\n';

    return 0;
}
