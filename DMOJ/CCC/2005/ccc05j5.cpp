// CCC '05 J5 - Bananas
#include <bits/stdc++.h>
using namespace std;

bool ismonkey(string word) {
    if (word == "A") return true;

    bool pos = true;
    while (pos) {
        pos = false;

        int p = word.find("ANA");
        if (p != string::npos) {
            word.replace(p,3,"A");
            pos = true;
            continue;
        }

        p = word.find("BAS");
        if (p != string::npos) {
            word.replace(p,3,"A");
            pos = true;
            continue;
        }
    }

    return word == "A";
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string word;
    while (true) {
        cin >> word;
        if (word == "X") break;
        cout << (ismonkey(word) ? "YES\n" : "NO\n");
    }

    return 0;
}

