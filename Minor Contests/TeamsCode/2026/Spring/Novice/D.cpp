// Convex
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
typedef vector<pl> vll;
#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define pb push_back


int N,M;
string immeasurablyCookedForTC26() {
    cin >> N >> M;
    vll lines(N); PRIMLOOP(N) cin >> lines[i].first >> lines[i].second;
    vl S(M); PRIMLOOP(M) cin >> S[i];

    if (M == 0 || N == 1) return "YES\n";

    sort(ALL(S));
    S.erase(unique(ALL(S)), S.end());

    if (S.size() > 1) {
        for (int i = 1; i < N; i++) {
            if (lines[i].first != lines[0].first || lines[i].second != lines[0].second) return "NO\n";
        }
        return "YES\n";
    } else {
        ll x = S[0];
        ll target_y = lines[0].first * x + lines[0].second;

        for (int i = 1; i < N; i++) {
            ll cur = lines[i].first * x + lines[i].second;
            if (cur != target_y) return "NO\n";
        }
        return "YES\n";
    }

    return "😨";
}

// skeleton bang shield rah rah rah
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    LOOP(T) {
        cout << immeasurablyCookedForTC26();
    }

    return 0;
}
