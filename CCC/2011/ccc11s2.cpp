// CCC '11 S2 - Multiple Choice
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define PRIMLOOP(N) for (int i = 0; i < N; i++)


char ans[10001];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    PRIMLOOP(N) cin >> ans[i];
    
    int res = 0;
    char tmp;
    PRIMLOOP(N) {
        cin >> tmp;
        if (tmp == ans[i]) res++;
    }

    cout << res << endl;

    return 0;
}
