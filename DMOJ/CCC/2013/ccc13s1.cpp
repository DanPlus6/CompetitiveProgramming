// CCC '13 S1 - From 1987 to 2013
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define CLOOP(s) for (char c: s)
#define FOUNDANS(res) {cout << res << endl; return 0;}


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int Y; cin >> Y;
    for (int D = Y+1; D > Y; D++) {
        string as_string = to_string(D);
        set<char> as_set; 
        CLOOP(as_string) as_set.emplace(c);
        if (as_string.length() == as_set.size()) FOUNDANS(D)
    }

    return 0;
}
