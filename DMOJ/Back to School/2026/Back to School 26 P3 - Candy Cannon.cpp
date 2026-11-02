/**
 * Author: DanPlus6 // David Fu
 * Problem Name: Back to School '26 P3 - Candy Cannon
 * Problem URL:  https://dmoj.ca/problem/bts26p3
 * Problem Code: bts26p3
 */
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;
typedef vector<ll> vl;
#define ALL(x) x.begin(), x.end()
#define pb push_back

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M; cin >> N >>  M;
    
    ll rres = 0, bres = 0;
    if (!(M&1)) {
        for (int i=0;i<N;++i) {
            vl row(M);
            for (int j = 0; j < M; ++j) {
                cin >> row[j];
            }
            sort(row.begin(), row.end());
            
            for (int j = 0; j < M; ++j) {
                if (j % 2 == 0) {
                    rres += row[j];
                } else {
                    bres += row[j];
                }
            }
        }
    } else {
        vl S(N);
        ll pairF = 0, pairS = 0;
        for (int i = 0; i < N; ++i) {
            vl row(M);
            for (int j=0;j<M;++j) cin >> row[j];
            sort(ALL(row));
            
            S.pb(row[0]);
            for (int j=1;j<M;++j) {
                if (j&1) pairF += row[j];
                else pairS += row[j];
            }
        }

        sort(ALL(S),greater<>());
        for (int k = 0; k < N; ++k) {
            if (!(k&1)) rres += S[k];
            else bres += S[k];
        }

        if (!(N&1)) {
            rres += pairF;
            bres += pairS;
        } else {
            bres += pairF;
            rres += pairS;
        }
    }

    if (rres > bres) cout << "RED\n";
    else if (bres > rres) cout << "BLUE\n";
    else cout << "TIE\n";

    return 0;
}
