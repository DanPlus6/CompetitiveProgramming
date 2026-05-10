// CCCHK '15 S2 - Matching Problem
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
#define endl '\n'

/* Orz jz */
signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N,M; cin >> N >> M;
    string S,T; cin >> S >> T;

    int g = __gcd(S.size(), T.size());
    ll L = N * (ll)S.size();

    ll periodical = 0;
    for (int r = 0; r < g; r++) {
        ll counterS[26]{}, counterT[26]{};
        for (int j = r; j < S.size(); j += g) counterS[S[j]-'a']++;
        for (int k = r; k < T.size(); k += g) counterT[T[k]-'a']++;
        for (int c = 0; c < 26; c++) periodical += counterS[c] * counterT[c];
    }

    cout << periodical * (L / (S.size() / g * T.size())) << endl;

    return 0;
}
