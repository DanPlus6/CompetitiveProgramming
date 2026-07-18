/**
 * Author: DanPlus6 // David Fu
 * Problem Name: Q4. Minimum Cost to Convert String III
 * Problem Code: minimum-cost-to-convert-string-iii
 * Problem URL:  https://leetcode.com/problems/minimum-cost-to-convert-string-iii/description
 */
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
#define ALL(x) x.begin(), x.end()
#define pb push_back

constexpr ll INFL = 0x3F3F3F3F3F3F3F3FLL;

typedef tuple<string,string,int> t;

class Solution {
public:
    int minCost(string src, string tg, vector<vs> &R, vi &C) {
        int n = src.length(), m = R.size();
        
        map<int,vector<t>> rbl;
        for (int i=0;i<m;++i) {
            rbl[R[i][0].length()].pb({R[i][0], R[i][1], (C[i] + count(ALL(R[i][0]),'*'))});
        }

        vl dp(n+1,INFL); dp[0] = 0;
        
        for (int i=1;i<=n;++i) {
            if (src[i-1] == tg[i-1]) dp[i] = dp[i-1];
                
            for (auto &[len, rl]: rbl) {
                if (i >= len) {
                    int start = i-len;
                    string xtg = tg.substr(start,len),
                    xsrc = src.substr(start,len);
                    
                    for (auto &[pat, rep, rc]: rl) {
                        if (rep == xtg) {
                            bool match = true;
                            for (int j=0;j<len;++j) {
                                if (pat[j] != '*' && pat[j] != xsrc[j]) {
                                    match = false;
                                    break;
                                }
                            }
                            
                            if (match) {
                                if (dp[start] != INFL && (dp[start] + rc) < dp[i])
                                    dp[i] = dp[start] + rc;
                            }
                        }
                    }
                }
            }
        }
                                    
        return ((dp[n] != INFL) ? (int)dp[n] : -1);
    }
};
