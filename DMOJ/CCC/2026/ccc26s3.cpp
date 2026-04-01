// CCC '26 S3 - Common Card Choice
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define PRIMLOOP(N) for (int i = 0; i < N; i++)


mt19937 rng;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vl A(N);
    PRIMLOOP(N) cin >> A[i];

    if (A[0] != -1) {
        N = min(N, 4);
        for (int i = 1; i < (1 << N) - 1; i++) {
            for (int j = 1; j < (1 << N) - 1; j++) {
                if (i & j) continue;

                ll sum1 = 0, sum2 = 0;
                for (int k = 0; k < N; ++k) {
                    if (i & (1 << k)) sum1 += A[k];
                    if (j & (1 << k)) sum2 += A[k];
                }

                if (gcd(sum1, sum2) > 1) {
                    cout << "YES\n";
                    cout << __builtin_popcount(i) << ' ' << __builtin_popcount(j) << '\n';
                    
                    vi idx, masks = {i, j};
                    for (int mask : masks) {
                        for (int k = 0; k < N; ++k) {
                            if (mask & (1 << k)) idx.push_back(k);
                        }
                        for (int k = 0 ; k < idx.size(); ++k) {
                            cout << idx[k]+1 << " \n"[k == idx.size() - 1];
                        }
                        idx.clear();
                    }
                    return 0;
                }
            }
        }
        cout << "NO\n";
    } 
    else {
        vi idx;
        for (int i = 0; i < N; ++i) {
            idx.push_back(i);
        }

        shuffle(idx.begin(), idx.end(), rng);
        cout << "100\n";
        PRIMLOOP(100) {
            cout << "2 2\n";
            cout << idx[4*i] << ' ' << idx[4*i+1] << '\n';
            cout << idx[4*i+2] << ' ' << idx[4*i+3] << '\n';
        }
    }
    return 0;
}
