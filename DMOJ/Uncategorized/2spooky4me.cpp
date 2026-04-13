// 2spooky4me
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define pb push_back


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    int N,RES,MAX; cin >> N >> RES >> MAX;

    vii houses = {{RES+1,0}}; {
        map<int,int> prehouses;
        int l,r,s;
        PRIMLOOP(N) {
            cin >> l >> r >> s;
            prehouses[l] += s;
            prehouses[r+1] -=s;
        }

        for (auto &[location, spook]: prehouses) {
            houses.pb({location,spook});
        }

        sort(ALL(houses),[](const pi a, const pi b){
            return a.first < b.first;
        });
    }
    

    int cur = 0;
    PRIMLOOP(houses.size()-1) {
        cur += houses[i].second;
        if (cur >= MAX) RES -= (houses[i+1].first - houses[i].first);
    }
    
    cout << RES << endl;

    return 0;
}
