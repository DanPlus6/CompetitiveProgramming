/**
 * Author: DanPlus6 // David Fu
 * Problem Name: VM7WC '16 #6 Gold - Cold War Telecom
 * Problem Code: vmss7wc16c6p3
 * Problem URL:  https://dmoj.ca/problem/vmss7wc16c6p3
 */
#include <bits/stdc++.h>
using namespace std;
char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int ,int, int> ti;
typedef pair<pi, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pl;
typedef tuple<ll,ll,ll> tl;
typedef pair<ll,pl> pll;
typedef pair<string, int> psi;
typedef vector<int> vi;
typedef unordered_set<int> si;
typedef set<ll> sl;
typedef queue<int> qi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<pi> vii;
typedef vector<ti> vti;
typedef vector<pl> vll;
typedef vector<tl> vtl;
typedef vector<bool> vb;
#define FILL(a, b) memset(a, b, sizeof(a))
#define pb push_back

constexpr int MM = 1e5+5;

int N,M; 
vvi adj;
bool vis[MM], inStk[MM];
int idx, dfn[MM], low[MM], res;
void tarjan(int u) {
    vis[u] = true;
    dfn[u] = low[u] = idx++;
    stack<int> stk; stk.push(u);

    for (int &v: adj[u]) {
        if (!vis[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inStk[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u]) {
        while (!stk.empty()) {
            int v = stk.top(); stk.pop();
            if (u == v) break;
            ++res;
        }
    }
}

int main() {
    scanf("%d %d",&N,&M);
    adj.reserve(N);
    for (int x,y; M--;) {
        scanf("%d %d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }

    for (int i=0;i<N;++i) {
        if (!vis[i]) tarjan(i);
    }

    printf("%d\n",res);

    return 0;
}
