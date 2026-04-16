// CCCJQR P3
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    uint64_t tmp; cin >> tmp;
    uint64_t res = tmp;
    
    cin >> tmp;
    res += tmp;

    cin >> tmp;
    res += tmp;

    cout << res % 42069900169420 << "\n";
    return 0;
}
