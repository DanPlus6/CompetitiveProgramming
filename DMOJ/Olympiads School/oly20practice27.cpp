// Stack of Blocks
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef vector<int> vi;
#define endl '\n'
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define FOUNDANS(res) {cout << res << endl; return 0;}

constexpr int INF = 0x3F3F3F3F;

int N,T;
vi H;
int res = INF;
void dpLol(int idx, int cur) {
    if (cur >= T) {res = min(res, abs(cur-T)); return;}
    if (idx == N) {if (cur >= T) res = min(res, abs(cur-T)); return;}

    dpLol(idx + 1, cur + H[idx]);
    dpLol(idx + 1, cur);
}

/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> T;
    H.resize(N);
    PRIMLOOP(N) cin >> H[i];


    dpLol(0,0);

    cout << res << endl;

    return 0;
}
