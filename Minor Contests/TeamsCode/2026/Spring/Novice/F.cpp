// Turtles
#include <bits/stdc++.h>
using namespace std;
char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

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
typedef vector<pii> viii;
typedef vector<bool> vb;
typedef priority_queue<int, vi> ipq;
typedef priority_queue<int, vi, greater<>> ripq;
#define endl '\n'
#define FILL(a, b) memset(a, b, sizeof(a))
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define SECLOOP(M) for (int j = 0; j < M; j++)
#define RLOOP(n) for (int i = n; i >= 0; i--)
#define ILOOP(arr) for (int &i: arr)
#define CLOOP(s) for (char c: s)
#define pb push_back
#define FOUNDANS(res) {cout << res << endl; return 0;}
#define vc vector

constexpr int MM = 1e5+5;
constexpr int INF = 0x3F3F3F3F;
constexpr ll INFL = 0x3F3F3F3F3F3F3F3FLL;
constexpr int MOD = 1e9 + 7;


struct Seg {
    ll fixed_coord, min, max;
};

bool horizvert(const vc<Seg>& horiz, const vc<Seg>& vert) {
    struct Event {
        ll x;
        int type;
        ll y1, y2;
        bool operator<(const Event& o) const {
            if (x != o.x) return x < o.x;
            return type < o.type;
        }
    };
    vc<Event> events;
    for(const auto& h : horiz) {
        events.pb({h.min, 1, h.fixed_coord, 0});
        events.pb({h.max, 3, h.fixed_coord, 0});
    }
    for(const auto& v : vert) {
        events.pb({v.fixed_coord, 2, v.min, v.max});
    }
    sort(events.begin(), events.end());
    set<ll> active;
    for(const auto& ev : events) {
        if(ev.type == 1) {
            active.insert(ev.y1);
        } else if(ev.type == 3) {
            active.erase(ev.y1);
        } else {
            auto it = active.lower_bound(ev.y1);
            if(it != active.end() && *it <= ev.y2) {
                return true;
            }
        }
    }
    return false;
}

bool horiz(vc<Seg> h1, vc<Seg> h2) {
    sort(h1.begin(), h1.end(),[](const Seg& a, const Seg& b) {
        return a.fixed_coord < b.fixed_coord;
    });
    sort(h2.begin(), h2.end(),[](const Seg& a, const Seg& b) {
        return a.fixed_coord < b.fixed_coord;
    });

    size_t i = 0, j = 0;
    while(i < h1.size() && j < h2.size()) {
        if(h1[i].fixed_coord < h2[j].fixed_coord) {
            i++;
        } else if(h1[i].fixed_coord > h2[j].fixed_coord) {
            j++;
        } else {
            ll overlap_min = max(h1[i].min, h2[j].min);
            ll overlap_max = min(h1[i].max, h2[j].max);
            if(overlap_min <= overlap_max) return true;
            i++; j++;
        }
    }
    return false;
}

/** big bwain amogus jaja */
bool vert(vc<Seg> v1, vc<Seg> v2) {
    sort(v1.begin(), v1.end(),[](const Seg& a, const Seg& b) {
        return a.fixed_coord < b.fixed_coord;
    });
    sort(v2.begin(), v2.end(),[](const Seg& a, const Seg& b) {
        return a.fixed_coord < b.fixed_coord;
    });

    size_t i = 0, j = 0;
    while(i < v1.size() && j < v2.size()) {
        if(v1[i].fixed_coord < v2[j].fixed_coord) {
            i++;
        } else if(v1[i].fixed_coord > v2[j].fixed_coord) {
            j++;
        } else {
            ll overlap_min = max(v1[i].min, v2[j].min);
            ll overlap_max = min(v1[i].max, v2[j].max);
            if(overlap_min <= overlap_max) {
                if(v1[i].fixed_coord == 0 && overlap_min == 0 && overlap_max == 0) {
                } else {
                    return true;
                }
            }
            i++; j++;
        }
    }
    return false;
}

void solve() { 
    int N, M; cin >> N >> M;

    vc<ll> a(N), b(M);
    for(int i = 0; i < N; ++i)cin >> a[i];
    for(int i = 0; i < M; ++i)cin >> b[i];

    vc<Seg> rhoriz, rvert;
    ll cx = 0, cy = 0;
    int dir = 0; // 0:n 1:e 2:s 3:w
    for(int i = 0; i < N; ++i) {
        ll nx = cx, ny = cy;
        if(dir == 0) ny += a[i];
        else if(dir == 1) nx += a[i];
        else if(dir == 2) ny -= a[i];
        else if(dir == 3) nx -= a[i];

        if(dir % 2 == 0) rvert.pb({cx, min(cy, ny), max(cy, ny)});
        else rhoriz.pb({cy, min(cx, nx), max(cx, nx)});

        cx = nx; cy = ny;
        dir = (dir + 1) % 4;
    }

    vc<Seg> bhoriz, bvert;
    cx = 0; cy = 0;
    dir = 0; // 0:s 1:w 2:n 3:e
    for(int i = 0; i < M; ++i) {
        ll nx = cx, ny = cy;
        if(dir == 0) ny -= b[i];
        else if(dir == 1) nx -= b[i];
        else if(dir == 2) ny += b[i];
        else if(dir == 3) nx += b[i];

        if(dir % 2 == 0) bvert.pb({cx, min(cy, ny), max(cy, ny)});
        else bhoriz.pb({cy, min(cx, nx), max(cx, nx)});

        cx = nx; cy = ny;
        dir = (dir + 1) % 4;
    }

    if(horizvert(rhoriz, bvert)) { cout << "YES\n"; return; }
    if(horizvert(bhoriz, rvert)) { cout << "YES\n"; return; }
    if(horiz(rhoriz, bhoriz)) { cout << "YES\n"; return; }
    if(vert(rvert, bvert)) { cout << "YES\n"; return; }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    LOOP(T) solve();

    return 0;
}
