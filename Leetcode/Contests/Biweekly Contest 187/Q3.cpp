/**
 * Author: DanPlus6 // David Fu
 * Problem Name: Q3. Minimum Adjacent Swaps to Partition Array
 * Problem Code: minimum-adjacent-swaps-to-partition-array
 * Problem URL:  https://leetcode.com/problems/minimum-adjacent-swaps-to-partition-array/description
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
typedef pair<string, int> psi;
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

constexpr int MM = 1e5+5;
constexpr int INF = 0x3F3F3F3F;
constexpr ll INFL = 0x3F3F3F3F3F3F3F3FLL;
constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int minAdjacentSwaps(vi &nums, int a, int b) {
        ll res = 0;
        for (ll ct1=0,ct2=0,i=0;i<nums.size();++i) {
            if (nums[i] < a) {
                res = ((res%MOD) + (ct1%MOD) + (ct2%MOD)) % MOD;
            } else if (nums[i] <= b) {
                res = ((res%MOD) + (ct2%MOD)) % MOD;
                ++ct1;
            } else {
                ++ct2;
            }
        }

        return res;
    }
};
