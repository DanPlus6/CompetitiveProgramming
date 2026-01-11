// DMOPC '16 Contest 4 P1 - Fast Exponents
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 0, N = (cin >> N, N); i < N; i++) {
        long long ni = (cin >> ni,ni);
        if (ni == 0) cout << "F\n";
        else if ((ni & (ni-1)) == 0) cout << "T\n";
        else cout << "F\n";
    }
    
    return 0;
}
