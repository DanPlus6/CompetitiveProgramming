// VMSS Pre-Windsor P7 - Going Back to the Definitions
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int N;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    vector<string> A(N);
    for (int i = 0; i < N; i++) {cin >> A[i];}
    sort(A.begin(),A.end(),[](string A, string B){
        // 😭😭
        // int n = A.size(); int m = B.size();
        // for (int i = 0; i <min(n,m); i++) {
        //     if (A[i] != B[i]) {return A[i] > B[i];}
        // }
        // return n < m;

        // WAIT WHAT
        // WHAT THE DUCK YOU CAN DO THIS
        // WHY DO THEY LET YOU COMPARE STRINGS IN C++
        // MY ENTIRE LIFE HAS BEEN A LIE
        // AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
        return A + B > B + A;
    });

    for (string &i: A) {cout << i;}
    cout << endl;
    
    return 0;
}
