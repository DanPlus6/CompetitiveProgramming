/**
 * Author: DanPlus6 // David Fu
 * Problem Name: Hardcore Grinding
 * Problem Code: grind
 * Problem URL:  https://dmoj.ca/problem/grind
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int ,int, int> ti;
typedef vector<pi> vii;
typedef vector<ti> vti;
#define ALL(x) x.begin(), x.end()

int main() {
    int N; scanf("%d",&N);
    vii T(N);
    for (int i=0;i<N;++i)
        scanf("%d %d", &T[i].first, &T[i].second);
    sort(ALL(T));

    priority_queue<pi, vii, greater<>> q;
    q.push({T[0].second,0});
    for (int i=1;i<N;++i) {
        auto [f,m] = q.top();
        if (T[i].first >= q.top().first) {
            f = T[i].second;
            q.pop();
            q.push({f,m});
        } else {
            q.push({T[i].second,q.size()+1});
        }
    }

    printf("%d\n",(int)q.size());

    return 0;
}
