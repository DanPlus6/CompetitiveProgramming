// Bob and Bus Stops - oly20practice82
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define ILOOP(n) for (int i = 0; i < n; i++)


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, Q; cin >> N >> Q;
    vi stops(N); ILOOP(N) {cin >> stops[i];}
    sort(ALL(stops));

    ILOOP(Q) {
        int l,r; cin >> l >> r;
        cout << distance(lower_bound(ALL(stops),l),upper_bound(ALL(stops),r)) << endl;
    }

    return 0;
}
