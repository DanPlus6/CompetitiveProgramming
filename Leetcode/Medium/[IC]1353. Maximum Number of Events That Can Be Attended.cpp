/**
 * Author: DanPlus6 // David Fu
 * Problem Name: 1353. Maximum Number of Events That Can Be Attended
 * Problem Code: maximum-number-of-events-that-can-be-attended
 * Problem URL:  https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/
 */
#include <bits/stdc++.h>
using namespace std;
char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

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

class Solution {
public:
    int maxEvents(vvi &events) {
        int n = events.size();
        sort(ALL(events), [](vi a, vi b){return a[0] < b[0];});

        vb open(n,true);
        int res = 0;
        for (int last=0,i=0;i<n;++i) {
            if (events[i][0] >= last) {
                ++res;
                last = events[i][1];
            }
        }

        return res;
    }
};
