// CCC '13 S2 - Bridge Transport
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ILOOP(n) for (int i = 0; i < n; i++)
#define FOUNDANS(res) {cout << res << endl; return 0;}


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int W, N;
    cin >> W >> N;
    vector<int> C(N);
    ILOOP(N) {cin >> C[i];}

    if (C[0] > W) FOUNDANS(0)

    int res = 0, weight = 0, l = 0, r = 4;
    ILOOP(((N < 4) ? N : 4)) {
        weight += C[i];
        if (weight > W) FOUNDANS(res)
        res++;
    }

    while (r < N) {
        weight += C[r];
        weight -= C[l]; l++;
        if (weight > W) FOUNDANS(res)
        res++;
        r++;
    }
    
    cout << res << endl;

    return 0;
}
