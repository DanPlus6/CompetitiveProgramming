// MALD Contest 1 P1 - Scratch Cat and DDoS
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    array<string,10001> websites;
    set<string> res;
    bool found = false;
    for (int i = 1; i <= N; i++) {
        cin >> websites[i];
        if (websites[i].find("yubo") != string::npos) {
            if (!websites[i-1].empty()) res.emplace(websites[i-1]);
            res.emplace(websites[i]);
            found = true;
        } else if (found) {
            res.emplace(websites[i]);
            found = false;
        }
    }

    for (string s: res) {cout << s << "\n";}

    return 0;
}
