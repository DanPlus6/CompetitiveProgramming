// VM7WC '16 #4 Silver - Tests or Test Cases?
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef vector<string> vs;
#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define CLOOP(s) for (char c: s)
#define pb push_back
#define pq priority_queue
#define vc vector


int N,L;
vc<vc<char>> restrictedSet;
vector<string> res;
void findWords(int i, string cur) {
    if (i >= N || cur.length() >= L) {res.pb(cur); return;}

    if (!cur.empty()) findWords(i+1, cur);
    CLOOP(restrictedSet[i]) {
        findWords(i+1, cur+c);
    }
}

/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> L;
    restrictedSet.resize(N);
    PRIMLOOP(N) {
        int M; cin >> M;
        LOOP(M) {
            char c; cin >> c;
            restrictedSet[i].pb(c);
        }
    }

    findWords(0,"");
    sort(ALL(res));

    for (string &s: res) cout << s << endl;
    
    return 0;
}
