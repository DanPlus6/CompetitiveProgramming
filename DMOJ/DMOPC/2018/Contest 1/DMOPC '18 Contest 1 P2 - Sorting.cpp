// DMOPC '18 Contest 1 P2 - Sorting
#include <bits/stdc++.h>
using namespace std;

int N,K;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    if (K == 1) {cout << "YES" << endl; return 0;}
    vector<int> P(N);
    for (int i = 0; i < N; i++) {cin >> P[i];}
    
    for (int i = 0; i < K; i++) {
        vector<int> v;
        for (int j = i; j < N; j += K)  {
            v.push_back(P[j]);
        }

        sort(v.begin(),v.end());

        int cj = i;
        for (const int &j: v) {
            P[cj] = j;
            cj += K;            
        }
    }

    for (int i = 0; i < N-1; i++) {if (P[i] > P[i+1]) {cout << "NO" << endl; return 0;}}
         
    cout << "YES" << endl;
    return 0;
}
