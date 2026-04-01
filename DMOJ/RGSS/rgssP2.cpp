// Richmond Green P2 - LOL
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N;
    cin >> N;

    vector<int> X,Y;
    set<int> SX,SY;
    for (int i = 0; i < N; i++) {
        int cx,cy; cin >> cx >> cy;
        SX.insert(cx);
        SY.insert(cy);
        X.push_back(cx);
        Y.push_back(cy);
    }

    if (SX.size() == 1 || SY.size() == 1) {cout << 0 << endl; return 0;}
    cout << ((*max_element(X.begin(),X.end()) - *min_element(X.begin(),X.end())) * (*max_element(Y.begin(),Y.end()) - *min_element(Y.begin(),Y.end()))) << endl;

    return 0;
}
