// CCC '08 S1 - It's Cold Here!
#include <bits/stdc++.h>
using namespace std;


typedef pair<int,string> tempCity;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string city; int temp;
    priority_queue<tempCity, vector<tempCity>, greater<>> q;
    while (city != "Waterloo") {
        cin >> city >> temp;
        q.push(tempCity({temp,city}));
        if (city == "Waterloo") break;
    }

    cout << q.top().second;

    return 0;
}
