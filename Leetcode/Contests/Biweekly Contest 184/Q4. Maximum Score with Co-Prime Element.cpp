// Q4. Maximum Score with Co-Prime Element
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define ALL(x) x.begin(), x.end()

class Solution {
public:
    int maxScore(vector<int>& nums, int maxVal) {
        int n = nums.size(), M = max(maxVal, *max_element(ALL(nums)));

        vi freq(M+1, 0);
        for (int &i: nums) freq[i]++;

        spf.resize(M+1);
        for (int i = 0; i <= M; i++) spf[i] = i;

        for (int i = 2; i * i <= M; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= M; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }
        
        cntDiv.resize(M + 1, 0);
        for (int d = 1; d <= M; d++) {
            for (int multiple = d; multiple <= M; multiple += d) {
                cntDiv[d] += freq[multiple];
            }
        }

        int res = 0;
        for (int i = 1; i <= M; i++) {
            int bad = ct(i);

            if (freq[i] > 0) {
                int cost = bad - (i>1?1:0);
                res = max(res, i - cost);
            } 
            else if (i <= maxVal) {
                int cost = max(1, bad);
                res = max(res, i - cost);
            }
        }

        return res;
    }
private:
    vi spf, cntDiv;

    vi getPrimes(int x) {
        vi primes;
        while (x > 1) {
            int p = spf[x];
            primes.push_back(p);
            while (x % p == 0) x /= p;
        }
        return primes;
    };

    int ct(int x) {
        if (x == 1) return 0;

        vi primes = getPrimes(x);
        int k = primes.size();

        int res = 0;
        for (int mask = 1; mask < (1 << k); mask++) {
            long long prod = 1;
            int bits = 0;

            for (int i = 0; i < k; i++) {
                if (mask & (1 << i)) {
                    prod *= primes[i];
                    bits++;
                }
            }

            if (bits & 1) res += cntDiv[(int)prod];
            else res -= cntDiv[(int)prod];
        }

        return res;
    };
};
