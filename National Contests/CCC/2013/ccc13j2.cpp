// CCC '13 J2 - Rotating letters
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string whitelist = "IOSHZXN";
    string S; cin >> S;

    if (S.find_first_not_of(whitelist) != std::string::npos) cout << "NO\n";
    else cout << "YES\n";

    return 0;
}
