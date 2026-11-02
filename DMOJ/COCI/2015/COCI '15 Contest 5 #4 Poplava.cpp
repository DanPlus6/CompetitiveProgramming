/**
 * Author: DanPlus6 // David Fu
 * Problem Name: COCI '15 Contest 5 #4 Poplava
 * Problem Code: coci15c5p4
 * Problem URL:  https://dmoj.ca/problem/coci15c5p4
 */
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#define int long long
typedef vector<int> vi;
#define pb push_back

signed main() {
    int N,X; scanf("%lld %lld",&N,&X);

    if ((N-2) * (N-1) / 2 < X) { printf("-1\n"); return 0; }
    vi lst = {N}, nvals;
    for (int i = 1; i < N-1; ++i) {
        if (int v = (N-1-i); X >= v) {
            lst.pb(i);
            X -= v;
        } else {
            nvals.pb(i);
        }
    }
    lst.pb(N-1);

    for (int i=0;i<nvals.size();++i) printf("%lld ",nvals[i]);
    for (int i=0;i<lst.size();++i)
        printf("%lld%c",lst[i],(i == lst.size()-1 ? '\n' : ' '));

    return 0;
}
