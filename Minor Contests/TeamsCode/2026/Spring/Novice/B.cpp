// Flower Ring
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define pb push_back


/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;

    int N;
    LOOP(T) {
        cin >> N;
        vi arr(N); PRIMLOOP(N) cin >> arr[i];

        if (N == 1) {cout << "1\n"; continue;
        }

        vi conflicts; PRIMLOOP(N) if (arr[i] == arr[(i+1) % N]) conflicts.pb(i);

        int M = conflicts.size();
        if (!M) {
            cout << "1\n"; 
            continue;
        }

        int x = 0;
        int start,end, len;
        PRIMLOOP(M) {
            start = (conflicts[(i-1+M) % M] + 1) % N, end = conflicts[i];

            len = (end >= start? (end-start+1) : (N-start+end+1));

            if (len >= 3 && (arr[start] == arr[end])) ++x;
        }

        cout << M+x << "\n";
    }

    return 0;
}
