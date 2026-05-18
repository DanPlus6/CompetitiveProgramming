// 303. Range Sum Query
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

class NumArray {
public:
    vector<int> psa;

    NumArray(vector<int>& nums) {
        psa.resize(nums.size());
        psa[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            psa[i] = nums[i] + psa[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return psa[right];
        return psa[right] - psa[left-1];
    }
};
