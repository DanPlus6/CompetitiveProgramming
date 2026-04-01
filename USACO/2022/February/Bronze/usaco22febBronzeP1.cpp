// USACO 2022 February Bronze P1 - Sleeping in Class
#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <sys/types.h>
using namespace std;


int minMods(const int N, vector<int> M, const int sum) {
    if (sum == 0) {return 0;}

    set<int> toset(M.begin(),M.end());
    if (toset.size() == 1 && N&1) {return N-1;}


    set<int> psa; int prevSum = 0;
    for (int i: M) {
        psa.insert(i+prevSum);
        prevSum += i;
    }

    vector<int> factors;
    for (int i = 1; i*i <= sum; i++) {
        if (sum % i == 0) {
            factors.push_back(i);
            if (i*i != sum) {factors.push_back(sum/i);}
        }
    }; sort(factors.begin(),factors.end());

    for (int i: factors) {
        bool broken = false;
        for (int j = i; j <= sum; j+=i) {
            if (!psa.count(j)) {
                broken = true;
                break;
            }
        }
        if (!broken) {return N-sum/i;}
    }
    return N-1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    int endi = T-1;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;

        vector<int> A(N);
        int sum = 0;
        for (uint32_t j = 0; j < N; j++) {
            int ai; cin >> ai;
            A[j] = ai;
            sum += ai;            
        }

        if (i != endi) { cout << minMods(N,A,sum) << "\n"; } else { cout << minMods(N,A,sum) << endl; }
    }
    
    return 0;
}
