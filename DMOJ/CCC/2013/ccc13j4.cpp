// CCC '13 J4 - Time on task
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'
#define ILOOP(n) for (int i = 0; i < n; i++)
#define FOUNDANS(res) {cout << res << endl; return 0;}



int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    int C; cin >> C;
    priority_queue<int, vi, greater<int>> minheap;
    ILOOP(C) {
        int c; cin >> c;
        minheap.push(c);
    }

    int res = 0;
    while (!minheap.empty()) {
        T -= minheap.top(); minheap.pop();
        if (T < 0) FOUNDANS(res)
        res++;
    }
    
    cout << C << endl;

    return 0;
}
