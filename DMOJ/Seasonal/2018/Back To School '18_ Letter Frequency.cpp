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



    // :spongebob_sob:
    // void buildPsa(map<char,map<int,int>> psa) {
    //     map<char,int> lastVal;
    //     string ln; getline(cin,ln);
    //     for (int si = 0; si < ln.size(); si++) {
    //         char c = ln[si];
    //         if (c == ' ') continue;
    //         if (c == '\n') {break;}

    //         if (!psa.count(c)) {psa[c][si] = 1; lastVal[c] = si;}
    //         else {psa[c][si] = psa[c][lastVal[c]] + 1; lastVal[c] = si;}
    //     }
    // }

    // map<char,map<int,int>> psa;
    // map<char,int> lastVal;
    // string ln; getline(cin,ln);
    // for (int si = 0; si < ln.size(); si++) {
    //     char c = ln[si];
    //     if (c == ' ') continue;
    //     if (c == '\n') {lastVal.clear(); break;}

    //     if (!psa.count(c)) {psa[c][si] = 1; lastVal[c] = 1;}
    //     else {psa[c][si] = lastVal[c] + 1; lastVal[c]++;}
    // }


    // int Q; cin >> Q;
    // int i, j; char c;
    // int left = 0, right;
    // for (int q = 0; q < Q; q++) {
    //     cin >> i >> j >> c;
    //     if (!psa.count(c)) {cout << 0 << "\n"; continue;}
    //     i--; j--;
    //     if (i == j) {cout << ((ln[i] == c) ? 1 : 0) << "\n"; continue;}        
    //     i--;

    //     reverse_iterator it = psa[c].rbegin();
    //     for (;it != psa[c].rend(); it++) {
    //         if (it->first <= j) {right = it->second; break;}            
    //     }

    //     if (i) {
    //     for (;it != psa[c].rend(); it++) {
    //         if (it->first <= i) {left = it->second; break;}            
    //     }
    //     }

    //     cout << right - left << "\n";
    // }

    return 0;
}
