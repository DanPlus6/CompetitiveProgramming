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
    
    return 0;
}
