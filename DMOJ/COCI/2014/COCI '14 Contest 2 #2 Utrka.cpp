/**
 * Author: DanPlus6 // David Fu
 * Problem Name: COCI '14 Contest 2 #2 Utrka
 * Problem URL:  https://dmoj.ca/problem/coci14c2p2
 * Problem Code: coci14c2p2
 */
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#define endl '\n'

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    unordered_map<string,int> entry,race;
    string s;
    for (int i=0;i<N;++i) {
        cin >> s;
        ++entry[s];
    }
    for (int i=1;i<N;++i) {
        cin >> s;
        ++race[s];
    }

    for (const auto &[k,v]: entry) {
        if (race[k] != v) { cout << k << endl; return 0; }
    }

    return 0;
}
