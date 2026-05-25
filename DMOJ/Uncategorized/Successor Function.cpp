// Successor Function - successor
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    ll x;
    while (T--) {
        cin >> x;
        cout << (~(~x)) << endl;
    }

    int a = 5, b = 6;
    while (true) {
        int sum = a ^ b, carry = a & b;
        if (!carry) {printf("%d\n",sum); break; }
        a = sum;
        b = carry << 1;
    }

    return 0;
}
