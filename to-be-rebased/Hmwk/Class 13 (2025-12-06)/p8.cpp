// COCI '13 Contest 5 #3 Eksplozjia
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string M;
    getline(cin,M);
    string B;
    getline(cin,B);
    vector<char> listB(B.begin(),B.end());
    
    int lenBomb = B.size();

    vector<char> stk;
    for (const char& i: M) {
        stk.push_back(i);
        int len = stk.size();

        vector<char> sliced(stk.begin()+(len-lenBomb),stk.end());
        if (len >= lenBomb && sliced == listB) {
            for (int i = 0; i < lenBomb; i++) {
                stk.pop_back();
            }
        }
    }
    
    if (stk.empty()) {
        cout << "FRULA" << endl;
    } else {
        for (const char& i: stk) {cout << i;}
        cout << endl;
    }

    return 0;
}
