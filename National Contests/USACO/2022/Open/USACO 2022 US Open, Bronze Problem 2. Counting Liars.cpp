/**
 * Author: DanPlus6 // David Fu
 * Problem Name: https://dmoj.ca/problem/usaco22openb2
 * Problem Code: usaco22openb2
 * Problem URL:  https://dmoj.ca/problem/usaco22openb2
 */
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

typedef vector<int> vi; 
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define pb push_back

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    vi L,G;
    LOOP(N) {
        char t; int v;
        cin >> t >> v;
        if (t == 'L') L.pb(v);
        else G.pb(v);
    }
    sort(ALL(L)); sort(ALL(G));

    int truth = 0;
    for (int i=0,j=0;i<G.size();++i) {
        while (j < L.size() && L[j] < G[i]) ++j;
        truth = max(truth, i+1 + (int)L.size()-j);
    }

    printf("%d\n",N-truth);

    return 0;
}
