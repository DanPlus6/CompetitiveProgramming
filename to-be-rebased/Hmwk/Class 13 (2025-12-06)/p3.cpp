// Alice's Shopping Trip
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long T,N;
    cin >> T >> N;

    vector<long long> arr(N, 0);
    for (long long i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), [](long long x, long long y){return abs(x) < abs(y);});

    long long res = 0;
    long long last = 0;
    for (long long store: arr) {
        long long cost = abs(store-last);
        if (cost <= T) {
            T -= cost;
            res += 1;
            last = store;
        } else {break;}
    }

    cout << res << endl;

    return 0;
}
