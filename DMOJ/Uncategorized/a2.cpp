// Mirrored Pairs
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cout << "Ready\n";
    while (true) {
        string pair;
        getline(cin,pair);
        if (pair == "  ") {break;}
        if (pair == "qp" || pair == "db" || pair == "pq" || pair == "bd") {cout << "Mirrored pair\n";}
        else {cout << "Ordinary pair\n";}
    }

    return 0;    
}
