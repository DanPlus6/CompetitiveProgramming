// Back To School '18: Letter Frequency
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string LN; getline(cin,LN);
    map<char,vector<int>> psa = {{'a',{0}},{'b',{0}},{'c',{0}},{'d',{0}},{'e',{0}},{'f',{0}},{'g',{0}},{'h',{0}},{'i',{0}},{'j',{0}},{'k',{0}},{'l',{0}},{'m',{0}},{'n',{0}},{'o',{0}},{'p',{0}},{'q',{0}},{'r',{0}},{'s',{0}},{'t',{0}},{'u',{0}},{'v',{0}},{'w',{0}},{'x',{0}},{'y',{0}},{'z',{0}}};
    for (char c: LN) {
        for (char ci = 'a'; ci <= 'z'; ci++) {
            if (ci != c) psa[ci].push_back(psa[ci].back());
            else psa[ci].push_back(psa[ci].back()+1);
        }
    }

    int Q; cin >> Q;
    int i, j; char c;
    for (int q = 0; q < Q; q++) {
        cin >> i >> j >> c;
        if (i == j) {cout << ((LN[i-1] == c) ? 1 : 0) << "\n"; continue;}
        cout << psa[c][j] - psa[c][i-1] << "\n";
    }

    return 0;
}
