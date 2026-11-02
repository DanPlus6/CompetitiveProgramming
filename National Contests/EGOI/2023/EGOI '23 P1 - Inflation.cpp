/**
 * Author: DanPlus6 // David Fu
 * Problem Name: EGOI '23 P1 - Inflation
 * Problem Code: egoi23p1
 * Problem URL:  https://dmoj.ca/problem/egoi23p1
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
#define endl '\n'

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    unordered_map<int,int> freq;
    int sum = 0;
    for (int p, _=0;_<N;++_) {
        cin >> p;
        sum += p;
        ++freq[p];
    }

    int Q; cin >> Q;
    for (int x,y,inf = 0; Q--;) {
        string s; cin >> s >> x;
        if (s == "SET") {
            cin >> y;
            if (x != y) {
                x -= inf, y -= inf;
                sum += freq[x] * (y-x);
                freq[y] = freq[y]+freq[x];
                freq[x] = 0;
            }
        } else {
            inf += x;
        }

        cout << sum+N*inf << endl;
    }

    return 0;
}
