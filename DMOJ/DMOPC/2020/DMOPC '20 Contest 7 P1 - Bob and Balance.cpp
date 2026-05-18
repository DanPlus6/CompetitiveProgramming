// DMOPC '20 Contest 7 P1 - Bob and Balance
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
#define ALL(x) x.begin(), x.end()
#define pb push_back

/* Orz bruce */
int main() {
    int N; scanf("%d",&N); 
    int half = N; N*=2;    
    vii arr(N); for (int i = 0; i < N; i++) { scanf("%d",&arr[i].first); arr[i].second = i+1; }
    

    sort(ALL(arr));

    int M = 0;
    vii res;
    int opp;
    for (int i = 0; i < N/2; i++) {
        opp = i+half;
        if (arr[i].first != arr[opp].first) ++M;
        res.pb({arr[i].second,arr[opp].second});
    }

    printf("%d\n",M);
    for (auto &[i,j]: res) printf("%d %d\n",i,j);

    return 0;
}
