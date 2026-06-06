// Q3. Maximum Total Value of Covered Indices
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int ,int, int> ti;
typedef pair<pi, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pl;
typedef tuple<ll,ll,ll> tl;
typedef pair<ll,pl> pll;
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
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define pb push_back

constexpr ll NEG_INF = LLONG_MIN / 2;

class Solution {
public:
ll maxTotal(vi& nums, string s) {
        vi tk;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '1') tk.pb(i);
        if (tk.empty()) return 0;

        ll stay = nums[tk[0]];
        ll move = (tk[0] > 0) ? (ll)nums[tk[0] - 1] : NEG_INF;

        for (int j = 1; j < tk.size(); j++) {
            int cur = tk[j], prv = tk[j - 1];

            ll best = ((move != NEG_INF) ? max(stay, move) : stay);

            ll cstay = best + nums[cur], cmove;
            if (cur == prv + 1) {
                ll opt1 = stay, 
                    opt2 = (move != NEG_INF) ? move + nums[prv] : NEG_INF;
                cmove = (opt2 != NEG_INF) ? max(opt1, opt2) : opt1;
            } else {
                cmove = best + nums[cur - 1];
            }

            stay = cstay;
            move = cmove;
        }

        return (move != NEG_INF) ? max(stay, move) : stay;

        
        // ll res = (s[0] == '1' ? nums[0] : 0);
        // for (int i = 1; i < s.length(); i++) {
        //     if (s[i] == '1') 
        //         if (nums[i-1] > nums[i] && s[i-1] != '1') {
        //             s[i-1] = '1'; s[i] = '0';
        //             res += nums[i-1];
        //         } else {
        //             res += nums[i];
        //         }
        // }
        
        // return res;
    }
};
