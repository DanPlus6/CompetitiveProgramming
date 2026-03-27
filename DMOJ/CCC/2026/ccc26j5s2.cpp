// Problem J5/S2: Beams of Light
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef pair<int,int> pi;
typedef set<pi> sii;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int N, L, Q; cin >> N >> L >> Q;
    vi markedRanges(N+2);
    vb illuminated(N+2,false);
    int l,r;
    for (int _ = 0; _ < L; _++) {
        cin >> l >> r;
        int left = max(1,l-r);
        markedRanges[left]++;

        int right = min(N+1,l+r+1);
        markedRanges[right]--;
    }

    int ct = 0;
    for (int i = 1; i <= N; i++) {
        ct += markedRanges[i];
        if (ct > 0) illuminated[i] = true;
    }
    
    int q;
    for (int _ = 0; _ < Q; _++) {
        cin >> q;
        if (illuminated[q]) cout << "Y\n";
        else cout << "N\n";
    }
    
    return 0;
}


