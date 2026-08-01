// D. Storming Arasaka
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define endl '\n'

constexpr int MM = 1e6+5;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    vi spf(MM);
    for (int i=0; i < MM; ++i) spf[i] = i;

    for (int i=2; i*i < MM; ++i) {
        if (spf[i] == i) {
            for (int j=i*i; j < MM; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    int T; cin >> T;
    for (int N, o, m, last, p; T--;) {
        cin >> N;
        
        o = 0; m = 0; last = -1;
        
        while (N > 1) { 
            p = spf[N];
            if (p != last) { m++; last = p; }
            o++;
            N /= p; 
        }

        cout << (o+m-1) << endl;
    }
    
    return 0;
}
