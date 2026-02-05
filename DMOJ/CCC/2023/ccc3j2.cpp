// CCC '23 J2 - Chili Peppers
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ILOOP(n) for (int i = 0; i < n; i++)


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    map<string,int> spice = {{"Poblano",1500},{"Mirasol",6000},{"Serrano",15500},{"Cayenne",40000},{"Thai",75000},{"Habanero",125000}};
    int N; cin >> N;
    long long res = 0;
    ILOOP(N) {
        string pepper; cin >> pepper;
        res += spice[pepper];
    }
    
    cout << res << endl;

    return 0;
}
