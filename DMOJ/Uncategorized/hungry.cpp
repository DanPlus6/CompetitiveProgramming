// Hungry
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<pair<int,int>> F(N),T(N);
    for (int i = 0 ; i < N; i++) {
        int f,t; cin >> f >> t;
        F[i] = {f,i}; T[i] = {t,i};
    }
    sort(F.begin(),F.end()); sort(T.begin(),T.end());
    
    for (int i=0;i<N;i++){cout << ++F[i].second << " ";} cout << "\n";
    for (int i=0;i<N;i++){cout << ++T[i].second << " ";} cout << "\n";

    // int N; cin >> N;
    // map<int,int> fillingAdr, tastyAdr;
    // vector<int> filling, tasty;
    // for (int i = 1 ; i <= N; i++) {
    //     int ai,bi; cin >> ai >> bi;
    //     fillingAdr[ai] = i; tastyAdr[bi] = i;
    //     filling.push_back(ai); tasty.push_back(bi);
    // }
    // sort(filling.begin(),filling.end()); sort(tasty.begin(),tasty.end());

    // for (int i=0;i<N;i++){if (i < N-1) cout << fillingAdr[filling[i]] << " "; else cout << fillingAdr[filling[i]] << "\n";}
    // for (int i=0;i<N;i++){if (i < N-1) cout << tastyAdr[tasty[i]] << " "; else cout << tastyAdr[tasty[i]] << "\n";}
    
    return 0;
}
