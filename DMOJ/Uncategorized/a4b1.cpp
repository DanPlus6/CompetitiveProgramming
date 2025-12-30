// Sorting
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; i++) {cin >> A[i];}
    sort(A.begin(),A.end());
    for (int &i: A) {cout << i << "\n";}

    return 0;
}
