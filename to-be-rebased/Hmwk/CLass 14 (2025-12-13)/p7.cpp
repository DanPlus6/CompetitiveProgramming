// Mock CCC '14 S3 - Spreadsheet Sorting
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int R,C; cin >> R >> C;
    int R1 = R-1; int C1 = C-1;
    vector<vector<int>> S(R,vector<int>(C));
    for (int i = 0; i < R; i++) {for (int j = 0; j < C; j++) {cin >> S[i][j];}}

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int c; cin >> c; int c1 = c-1;

        // why doesn't normal sort work 😭😭
        stable_sort(S.begin(),S.end(),[&c1](const vector<int> &A, const vector<int> &B){return A[c1] < B[c1];});
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (j != C1) {cout << S[i][j] << " ";}
            else {cout << S[i][j];}
        }
        if (i != R1) {cout << "\n";}
    }
    cout << endl;
    return 0;
}

