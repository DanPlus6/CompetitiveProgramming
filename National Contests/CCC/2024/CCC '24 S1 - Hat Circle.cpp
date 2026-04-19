// CCC '24 S1 - Hat Circle
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int dist = N/2;
    
    vector<int> table(N+1); 
    for (int i = 1; i <= N; i++) {
        cin >> table[i];
    }

    int res = 0;
    for (int i = 1; i <= N; i++) {
        int target = (i+dist);
        if (table[i] == table[(target <= N) ? target : target%N]) res++;
    }

    cout << res << endl;

    return 0;
}
