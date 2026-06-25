// DMOPC '17 Contest 4 P4 - Cops and Robbers
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back

void print(vi arr, bool isRes=false) {
    if (!isRes) {
        printf("[");
        for (int i=0;i<arr.size();i++)
            printf("%d%s", arr[i], (((i+1)<arr.size()) ? ", " : "]\n"));
    } else {
        for (int i=0;i<arr.size();i++)
            printf("%d%c", arr[i], (((i+1)<arr.size()) ? ' ' : '\n'));
    }
}


int main() {
    int N; scanf("%d",&N);
    vb robbed(N+1,false); vi res(N, -1); 
    int toRob = 1;

    vi D, pos(N+1,-1); for (int b, i=0;i<N;++i) {
        scanf("%d", &b);
        if (pos[b] == -1) {
            D.pb(b);
            pos[b] = i;
        }
    }

    if (D.size() == 1) { printf("-1\n"); return 0; }

    for (int cur, prev, i = 0; i < D.size(); i++) {
        cur = D[i];
        prev = D[(i-1+D.size()) % D.size()];

        res[pos[cur]] = prev; robbed[prev] = true;
    }
    
    for (int i=0;i<N;i++) {
        if (res[i] != -1) continue;
        for (; toRob <= N; toRob++)
            if (!robbed[toRob]) { 
                res[i] = toRob; 
                robbed[toRob] = true;
                break;
            }
    }

    print(res,true);

    return 0;
}
