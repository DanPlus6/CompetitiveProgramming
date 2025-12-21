// Modulo Sort
#include <bits/stdc++.h>
using namespace std;

int N,K;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    int less = N-1;
    vector<int> M(N);
    for (int i = 0; i < N; i++) {cin >> M[i];}
    sort(M.begin(),M.end(),[](int A, int B){
        int amod = A%K; int bmod = B%K;
        if (amod == bmod) {
            return A < B;
        }
        return A%K < B%K;
    });
    for (int i = 0; i < N; i++) {if (i != less) {cout << M[i] << " ";} else {cout << M[i];}}
    cout << endl;
    
    return 0;
}
