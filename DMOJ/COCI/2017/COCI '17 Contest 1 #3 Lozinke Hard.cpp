/**
 * Author: DanPlus6 // David Fu
 * Problem Name: COCI '17 Contest 1 #3 Lozinke Hard
 * Problem Code: coci17c1p3hard
 * Problem URL:  https://dmoj.ca/problem/coci17c1p3hard
 */
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#define endl '\n'
#define LOOP(n) for (int _ = 0; _ < n; _++)

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    unordered_map<string,int> db;

    int Q; cin >> Q;
    LOOP(Q) {
        int t; cin >> t;
        string s; cin >> s;
        if (t == 1) {
            unordered_set<string> subs;
            for (int p=0;p<s.length();++p) {
                for (int n=1;n<=s.length();++n) {
                    subs.insert(s.substr(p,n));
                }
            }

            for (auto &s: subs) ++db[s];
        } else {
            cout << db[s] << endl;
        }
    }

    return 0;
}
