// MALD Contest 1 P2 - Scratch Cat and Examinations
#include <bits/stdc++.h>
using namespace std;

#define ILOOP(n) for (int i = 0; i < n; i++)


int main() {
    #define int long long
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    ILOOP(T) {
        int grade, full; cin >> grade >> full;
        int mark = (grade*100 + full - 1)/full;

        if (mark < 90) cout << "find a new home\n";
        else if (90 <= mark && mark <= 94) cout << "don't come home\n";
        else if (95 <= mark && mark <= 97) cout << "can't eat dinner\n";
        else if (98 <= mark && mark <= 99) cout << "below average\n";
        else if (mark == 100) cout << "average\n";
        else if (mark > 100) cout << "sus\n";
    }

    return 0;
}
