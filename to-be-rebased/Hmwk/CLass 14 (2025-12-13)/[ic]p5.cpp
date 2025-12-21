// USACO 2022 February Bronze P2 - Photoshoot 2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    // TLE 😭
    // deque<int> a,B;
    // map<int,int> MB;
    // for (int i = 0; i < N; i++) {int tmp; cin >> tmp; a.push_back(tmp);}
    // for (int i = 0; i < N; i++) {int tmp; cin >> tmp; B.push_back(tmp); MB[tmp] = i;}

    // if (a == B) {cout << 0 << endl; return 0;}
    
    // int res = 0;
    // while (a != B) {
    //     for (int i = N-1; i >= 0; --i) {
    //         int cur = a[i];
    //         if (cur != B[i]) {
    //             if (MB[cur] == 0) {
    //                 a.pop_back();
    //                 a.push_front(cur);
    //                 res += 1;
    //                 break;
    //             }
    //             else {
    //                 a.erase(a.begin()+i);
    //                 a.insert(a.begin()+MB[cur],cur);
    //                 res += 1;
    //                 break;
    //             }
    //         }
    //     }
    // }

    // cout << res << endl;


    // 🥀💔
    vector<int> A(N),B(N);
    for (int i = 0; i < N; i++) {cin >> A[i];}
    for (int i = 0; i < N; i++) {cin >> B[i];}

    int i = N-1; int j = N-1;
    while (i >= 0 && j >= 0) {
        if (A[i] == B[j]) {j--;}
        i--;
    }

    cout << j+1 << endl;

    return 0;
}