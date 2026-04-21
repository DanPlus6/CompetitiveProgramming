// Bulgarian OI '09 P5 - Special Sequence
#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
#define endl '\n'
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;

    vs bank;
    
    auto add_to_bank = [&](string base, int min_zeros) {
        for (int p = min_zeros; p <= 22 - (int)base.length(); ++p) {
            bank.push_back(base + string(p, '0'));
        }
    };

    add_to_bank("7", 1);

    for (int k = 2; k <= 22; ++k) {
        string base(k, '9');
        base.back() = '7';
        add_to_bank(base, 0);
    }

    for (int m = 1; m <= 10; ++m) {
        string base = "2" + string(m - 1, '0') + "1" + string(m - 1, '0') + "2";
        int min_z = (m == 1) ? 1 : 0; 
        add_to_bank(base, min_z);
    }

    add_to_bank("3148", 0);
    add_to_bank("3074003", 0);
    add_to_bank("953671853653", 0);
    add_to_bank("2118984413357", 0);
    add_to_bank("2121179131852", 0);

    add_to_bank("6328428636000007", 0);
    add_to_bank("99704560597822753", 0);

    sort(ALL(bank), [](const string& a, const string& b) {
        if (a.length() != b.length()) return a.length() < b.length();
        return a < b;
    });

    bank.erase(unique(ALL(bank)), bank.end());

    if (N > 0 && N <= bank.size()) {
        cout << bank[N - 1] << endl;
    }

    return 0;
}
