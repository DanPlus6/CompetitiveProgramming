// Permutation Order - oly23practice33
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
#define endl '\n'
#define pb push_back
#define FOUNDANS(res) {cout << res << endl; return 0;}


constexpr ll precomp[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000 };

void listmapintinputsplit(vl &arr) {
    string ln; getline(cin, ln);
    
    istringstream ss(ln);
    int x;
    while (ss >> x) arr.pb(x);
}

int N;
ll compute(vl perm, int start, int avail) {
    ll total = 0;
    ll v, smaller;

    for (int i = start; i < N; i++) {
       v = perm[i];
       smaller = bitset<64>(avail & ((1ll << v) - 1ll)).count();
       total += smaller * precomp[N-1-i];
       avail ^= (1ll << v);
    }

    return total;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N; cin.ignore();
    vl P; listmapintinputsplit(P);
    vl Q; listmapintinputsplit(Q);

    ll avail = (1ll << (N+1ll)) - 2ll;
    ll shared = 0;
    for (int i = 0; i < N; i++) {
        int p = P[i], q = Q[i];
        if (p == q) {
            shared += bitset<64>(avail & ((1ll << p) - 1ll)).count() * precomp[N-1-i];
            avail ^= (1ll << p);
        } else {
            ll avail_q = avail;

            FOUNDANS(abs((shared + compute(P, i, avail)) - compute(Q, i, avail_q)))
        }
    }

    cout << "0\n";
    return 0;
}

