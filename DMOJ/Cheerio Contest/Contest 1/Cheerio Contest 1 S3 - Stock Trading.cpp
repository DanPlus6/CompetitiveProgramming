// Cheerio Contest 1 S3 - Stock Trading
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

int main() {
    int N; scanf("%d",&N);
    vl time(N), stocks(N); for (int i = 0; i < N; i++) scanf("%lld %lld",&time[i],&stocks[i]);

    ll res = 0;
    for (int i = 0; i < N; i++) {
        ll min_n = stocks[i+1]-stocks[i], min_d = time[i+1]-time[i];
        ll max_n = stocks[i+1]-stocks[i], max_d = time[i+1]-time[i];
        ll cur_n, cur_d;
        for (int j = i+1; j < N; j++) {
            cur_n = stocks[j]-stocks[i], cur_d = time[j]-time[i];
            if (cur_n*min_d <= cur_d*min_n || cur_n*max_d >= cur_d*max_n) ++res;

            if (cur_n*min_d < cur_d*min_n) { min_n = cur_n; min_d = cur_d; }
            if (cur_n*max_d > cur_d*max_n) { max_n = cur_n; max_d = cur_d; }
        }
    }
    
    printf("%lld\n",res);

    return 0;
}
