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

// UZMI for **take**
// STAVI for **put**
// L for **left**
// D for **right**
// format: take/put hand shelf

int main() {
    int N; scanf("%d",&N);
    if (N==1) return 0;

    stack<int> left; vi right;
    for (int b,i=0;i<N;++i) {
        scanf("%d",&b);
        left.push(b);
    }

    vs res;
    right.pb(left.top()); left.pop();
    res.pb("UZMI D L\n"); res.pb("STAVI D D\n");
    for (int nb; !left.empty();) {
        nb = left.top(); left.pop();
        res.pb("UZMI D L\n");
        if (right.empty() || nb >= right.back()) {
            right.pb(nb);
            res.pb("STAVI D D\n");
        } else {
            int i = right.size()-1;
            for (;i >= 0 && nb < right[i];--i) {
                res.pb("UZMI L D\n");
                res.pb("STAVI L L\n");
            }
            
            res.pb("STAVI D D\n");
            i = right.size()-i-1;
            right.insert(right.begin()+i+1,nb);

            for (;i--;) {
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
