// CCC '16 S2 - Tandem Bicycle
#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q; cin >> Q;
    int N; cin >> N;
    vector<int> D(N),P(N); for(int i=0;i<N;i++) cin>>D[i]; for(int i=0;i<N;i++) cin>>P[i];
    
    if (Q == 1) { sort(D.begin(),D.end()); sort(P.begin(),P.end()); }
    else { sort(D.begin(),D.end(),greater<int>()); sort(P.begin(),P.end()); }
    int res = 0; for(int i=0;i<N;i++) {res += max(D[i],P[i]);}
    cout << res << "\n";

    return 0;
}
