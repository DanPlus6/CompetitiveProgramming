// Infection
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef vector<int> vi;
#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define pb push_back


struct M {
    int u, v, d;
    bool operator<(const M &o) const {
        return d < o.d;
    }
};

map<int, vi> i;
bool s(int p, int d) {
    if (!i.count(p) || i[p].empty()) return false;

    auto it = lower_bound(ALL(i[p]), d);
    if (it != i[p].begin()) {
        --it;
        if (d > *it && d <= *it + 3) return true;
    }

    return false;
}


int main() {
    int TP, TD; cin >> TP >> TD;
    int N; cin >> N;

    vector<M> m(N);
    for (int j = 0; j < N; ++j) {
        cin >> m[j].u >> m[j].v >> m[j].d;
    }
    sort(ALL(m));
    
    i[0].pb(0);
    for (auto &x : m) {
        bool su = s(x.u, x.d);
        bool sv = s(x.v, x.d);

        if (su && !sv) {
            if (i[x.v].empty() || i[x.v].back() != x.d) i[x.v].push_back(x.d);
        }
        if (sv && !su) {
            if (i[x.u].empty() || i[x.u].back() != x.d) i[x.u].push_back(x.d);
        }
    }

    if (s(TP,TD)) cout << "true\n";
    else cout << "false\n";

    return 0;
}

