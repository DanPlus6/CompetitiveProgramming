// List Minimum
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    priority_queue<int,vector<int>,greater<int>> A; for (int i = 0; i < N; i++) {int tmp; cin >> tmp; A.push(tmp);}
    for (int i = 0; i < N; i++) {cout << A.top() << "\n"; A.pop();}

    return 0;
}
