/**
 * Author: DanPlus6 // David Fu
 * Problem Name: COCI '20 Contest 3 #1 Knjige
 * Problem Code: coci20c3p1
 * Problem URL:  https://dmoj.ca/problem/coci20c3p1
 */
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

typedef vector<int> vi;
typedef vector<string> vs;
#define pb push_back

int main() {
    int N; scanf("%d",&N);
    if (N==1) { printf("0\n"); return 0; }

    vi right(1); vs res;
    scanf("%d",&right[0]);
    res.pb("UZMI D L\n"); res.pb("STAVI D D\n");
    for (int b, _=1;_<N;++_) {
        scanf("%d",&b);
        res.pb("UZMI D L\n");
        if (right.empty() || b >= right.back()) {
            right.pb(b);
            res.pb("STAVI D D\n");
        } else {
            int i = right.size()-1;
            for (;i >= 0 && b < right[i];--i) {
                res.pb("UZMI L D\n");
                res.pb("STAVI L L\n");
            }
            
            res.pb("STAVI D D\n");
            right.insert(right.begin()+i+1,b);

            for (i = right.size()-i-2;i--;) {
                res.pb("UZMI D L\n");
                res.pb("STAVI D D\n");
            }
        }
    }

    for (;N--;) {
        res.pb("UZMI L D\n");
        res.pb("STAVI L L\n");
    }

    printf("%zu\n",res.size());
    for (string &s: res) printf("%s",s.c_str());

    return 0;
}
