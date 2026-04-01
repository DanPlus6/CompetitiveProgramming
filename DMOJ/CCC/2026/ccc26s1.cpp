// CCC '26 S1 - Baby Hop, Giant Hop
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define endl '\n'

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll A,B,K,T; cin >> A >> B >> K >> T;

    ll dist = abs(A-B), leaps = dist / K;
    ll rem = dist % K;

    ll basic = leaps+rem, overshootandback = (leaps+1)+(K-rem);
    vl res = {basic, overshootandback, basic+2, overshootandback+2, overshootandback+K};
    if (leaps) res.pb(((leaps-1)+(K+rem)));


    sort(ALL(res));
    {auto t = unique(ALL(res));}
    if (T == 1) cout << res[0] << endl;
    else cout << res[1] << endl;

    return 0;
}
