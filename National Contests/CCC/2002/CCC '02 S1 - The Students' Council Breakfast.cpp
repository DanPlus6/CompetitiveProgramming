// CCC '02 S1 - The Students' Council Breakfast
#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef tuple<int,int,int,int> myT;

int p, g, r, o, N;
int combs = 0, tickmin = INT_MAX;
set<myT> vis;
void combination(int cp, int cg, int cr, int co, int csum) {
    if (csum == N) {
        myT cur = {cp,cg,cr,co};
        if (vis.count(cur)) return;
        vis.insert(cur);

        printf("# of PINK is %lld # of GREEN is %lld # of RED is %lld # of ORANGE is %lld\n",cp,cg,cr,co);
        ++combs;
        tickmin = min(tickmin, (cp+cg+cr+co));   
        return;
    }
    if (csum > N) return;

    combination(cp+1,cg,cr,co,csum+p);
    combination(cp,cg+1,cr,co,csum+g);
    combination(cp,cg,cr+1,co,csum+r);
    combination(cp,cg,cr,co+1,csum+o);
}

signed main() {
    scanf("%lld\n%lld\n%lld\n%lld\n%lld",&p,&g,&r,&o,&N);

    combination(0,0,0,0,0);

    printf("Total combinations is %lld.\n",combs);
    printf("Minimum number of tickets to print is %lld.\n",tickmin);

    return 0;
}
