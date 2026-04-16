// TSS Club Fair 2017 Problem B
#include <bits/stdc++.h>
using namespace std;

typedef vector<long long> vl;
#define endl '\n';
#define ALL(x) x.begin(), x.end()
#define LOOP(n) (int i = 0; i < n; i++)
#define pb push_back


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N,Q; cin >> N >> Q;
    vl houses;
    for LOOP(N) {
        long long x,y; cin >> x >> y;
        houses.pb(x*x + y*y);
    }
    sort(ALL(houses));

    for LOOP(Q) {
        long long r; cin >> r;
        cout << distance(houses.begin(),upper_bound(ALL(houses), r*r)) << "\n";
    }

    return 0;
}
