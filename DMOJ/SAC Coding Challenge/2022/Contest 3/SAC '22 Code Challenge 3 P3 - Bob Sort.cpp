// SAC '22 Code Challenge 3 P3 - Bob Sort
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int N;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int R = (log10(*max_element(A.begin(),A.end())) + 1);
    for (int r = 1; r <= R; r++) {
        // when c++ is TLE by python isn't :sob: :pray: :wilted_rose: :broken_heart:
        // sort(A.begin(),A.end(),[r](int A, int B){
        //     string a = to_string(A);
        //     string b = to_string(B);
            
        //     return stoi(a.substr((r > a.length()) ? 0 : a.length() - r)) < stoi(b.substr((r > b.length()) ? 0 : b.length() - r));
        // });
        
        sort(A.begin(),A.end(),[r](int A, int B){
            long long base = static_cast<long long>(pow(10,r));
            return A % base < B % base;
        });

        if (r != R) {
            for (int j = 0; j < N; j++) {
                cout << A[j];
                if (j != N-1) {cout << ' ';} else {cout << '\n';}
            }
        } else {
            for (int j = 0; j < N; j++) {
                cout << A[j];
                if (j != N-1) {cout << ' ';}
            }
        }
    }

    cout << endl;
    return 0;
}
