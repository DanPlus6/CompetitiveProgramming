// WC '96 P6 - Bases Multiplication
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)

ll lpow(ll base, ll exp) {
    ll res = 1;
    
    for (ll i = 0; i < exp; i++) res *= base;
    
    return res;
}

ll toBase10(string num, int base) {
    ll res = 0;

    for (ll i = 0; i < num.length(); i++) {
        res += (num[i]-'0') * lpow(base, num.length()-i-1ll);
    }

    return res;
}

string base10To(ll num, int base) {
    if (!num) return "0";
    string res = "";
    
    while (num) {
        res += to_string(num % base);
        num /= base;
    }

    reverse(ALL(res));
    return res;
}

/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    LOOP(5) {
        string fnum; ll fbase; cin >> fnum >> fbase;
        string snum; ll sbase; cin >> snum >> sbase;
        ll tbase; cin >> tbase;

        ll first = (fbase != 10 ? toBase10(fnum, fbase) : stoll(fnum));
        ll second = (sbase != 10 ? toBase10(snum, sbase) : stoll(snum));
        cout << base10To(first*second, tbase) << endl;
    }

    return 0;
}
