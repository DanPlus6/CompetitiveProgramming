// USACO 2023 December Bronze P2 - Cowntact Tracing 2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    string S; cin >> S;
    set<char> chkSet(S.begin(),S.end());

    if (chkSet == set{'1'}) {cout << 1 << "\n"; return 0;}
    else if (chkSet == set{'0'}) {cout << 0 << "\n"; return 0;}
    
    S.insert(0,"0"); S += "0"; N++;
    vector<int> wlens;
    int l = 0, maxNights = 1e9;
    for (int r = 1; r <= N; r++) {
        if (S[r] != S[r-1]) {
            if (S[r] == '1') l = r;
            else {
                wlens.push_back(r-l);
                if (l == 1 || r == N) maxNights = min(maxNights,r-l-1);
                else {maxNights = min(maxNights,(r-l-1)/2);}
            }
        }
    }

    int res = 0, twoK = maxNights * 2;
    int denom = twoK + 1;
    for (int &wlen: wlens) 
        res += (wlen + twoK)/denom;
    cout << res << "\n";

    return 0;
}
