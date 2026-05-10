// USACO 2023 January Bronze P2 - Air Cownditioning II
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define pb push_back

constexpr int INF = 0x3F3F3F3F;

vii cows;
vi reqs;
vii conditioners;
vi cost;
vi power;
int res = INF;
int N,M;

int check(string run) {
    vi cold(105);
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j < conditioners.size(); j++) {
            if (run[j] == '1' && conditioners[j].first <= i && conditioners[j].second >= i) cold[i] += power[j];
        }
    }

    bool can = true;
    for (int i = 0; i < N; i++) {
        for (int j = cows[i].first; j <= cows[i].second; j++) {
            if (cold[j] < reqs[i]) can = false;
        }
    }

    int price = 0;
    for (int i = 0; i < run.length(); i++) {
        if (run[i] == '1') price += cost[i];
    }

    if (can) return price;
    return INF;
}

void solve(string run) {
    if (run.length() == M) {
        res = min(res, check(run));
    } else {
        solve(run + '1');
        solve(run + '0');
    }
}

/* Orz Mythreya Dharani */
int main() {
    scanf("%d %d",&N,&M);
    {
        int s,t,c;
        PRIMLOOP(N) {
            scanf("%d %d %d",&s,&t,&c);
            cows.pb({s,t});
            reqs.pb(c);
        }
    }

    {
        int a,b,p,m;
        PRIMLOOP(M) {
            scanf("%d %d %d %d",&a,&b,&p,&m);
            conditioners.pb({a,b});
            power.pb(p);
            cost.pb(m);
        }
    }

    solve("");

    cout << res << endl;
    return 0;
}
