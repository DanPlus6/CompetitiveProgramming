// CCC '11 J1 - Which Alien?
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int A,E; /* cin >> A >> E; */
    cout << "How many antennas?\n";
    cin >> A;
    cout << "How many eyes?\n";
    cin >> E;

    if (A >= 3 && E <= 4) cout << "TroyMartian\n";
    if (A <= 6 && E >= 2) cout << "VladSaturnian\n";
    if (A <= 2 && E <= 3) cout << "GraemeMercurian\n";
    return 0;
}
