// CCC '05 J3 - Returning Home
#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
#define endl '\n'
#define pb push_back

/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    vs ipt;
    { string word; while (cin >> word) ipt.pb(word); }

    for (int i = ipt.size()-2; i >= 0; i -= 2) 
        cout << "Turn " << (ipt[i] == "R" ? "LEFT" : "RIGHT") << (i != 0 ? " onto " + ipt[i-1] + " street." : " into your HOME.") << endl;

    return 0;
}
