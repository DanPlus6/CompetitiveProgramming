// CCC '11 J3 - Sumac Sequences
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FOUNDANS(res) {cout << res << endl; return 0;}


int sumacseq(int T1, int T2, int terms) {
    if (T1 < T2) return terms+1;
    return sumacseq(T2, (T1-T2), (terms+1));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T1,T2; cin >> T1 >> T2;
    if (T1 < T2) FOUNDANS(1)
    cout << sumacseq(T2,T1-T2,2) << endl;

    return 0;
}
