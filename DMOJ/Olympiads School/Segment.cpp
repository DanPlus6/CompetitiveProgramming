// Segment - oly18novp1
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef vector<pi> vii;
#define endl '\n'
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    vii lines(N); 
    for (int i=0;i<N;++i) 
        cin >> lines[i].first >> lines[i].second;
    sort(ALL(lines), [](pi a, pi b){return a.second < b.second;});

    int res = 0;
    for (int last = 0, i=0;i<N;++i) {
        if (lines[i].first >= last) {
            ++res;
            last = lines[i].second;
        }
    }

    cout << res << endl;

    return 0;
}
