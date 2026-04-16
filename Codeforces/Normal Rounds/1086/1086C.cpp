// C. Stamina and Tasks
#include <bits/stdc++.h>
using namespace std;

typedef long double myfl;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; 
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N; 
        cin >> N;
        vector<int> points(N), difc(N);
        for (int i = 0; i < N; i++) {
            cin >> points[i] >> difc[i];
        }

        myfl x = 0;
        for (int i = N - 1; i >= 0; i--) {
            if ((myfl)points[i] * 100 >= (myfl)difc[i] * x) x = points[i] + (1.0 - difc[i] / 100.0) * x;
        }
        
        cout << fixed << setprecision(10) << x << "\n";
    }

    return 0;
}
