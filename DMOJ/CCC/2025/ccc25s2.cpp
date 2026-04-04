// CCC '25 S2 - Cryptogram Cracking Club
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;
#define endl '\n'
#define CLOOP(s) for (char c: s)
#define pb push_back
#define FOUNDANS(res) {cout << res << endl; return 0;}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string pattern; cin >> pattern;
    ll C; cin >> C;

    vector<pair<char,ll>> ranges;
    ll LEN = 0; {
        char curChar;
        string buildnum = "";
        CLOOP(pattern+'|') {
            if (isalpha(c) || c == '|') {
                if (!buildnum.empty()) {
                    ll y = stoll(buildnum);
                    ranges.pb({curChar,y});
                    LEN += y;
                }
                curChar = c;
                buildnum = "";
            } else {
                buildnum += c;
            }
        }
    }


    C %= LEN;
    for (int i = 0; i < size(ranges); i++) {
        auto &[x,y] = ranges[i];

        if (C < y) FOUNDANS(x)

        C -= y;
    }

    return 0;
}
