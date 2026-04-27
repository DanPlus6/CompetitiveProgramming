// CCC '17 S2 - High Tide, Low Tide
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define PRIMLOOP(N) for (int i = 0; i < N; i++)


/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    vi arr(N); PRIMLOOP(N) cin >> arr[i];

    sort(ALL(arr));

    int mid = N/2;
    if (N&1) {
        for (int i = 0; i < mid; i++) {
            cout << arr[mid-i] << " ";
            cout << arr[mid+1+i] << " ";
        }
        cout << arr[0] << endl;
    } else {
        for (int i = 0; i < mid; i++) {
            cout << arr[mid-1-i] << " ";
            cout << arr[mid+i] << " \n"[i == mid-1];
        }
    }

    return 0;
}
