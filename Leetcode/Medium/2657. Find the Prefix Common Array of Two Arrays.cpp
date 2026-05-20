// 2657. Find the Prefix Common Array of Two Arrays
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class Solution {
public:
    static vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vi PCA(A.size(), 0), freq(A.size()+1,0);

        ++freq[A[0]];
        if (++freq[B[0]] == 2) ++PCA[0];
        for (int i = 1; i < A.size(); i++) {
            PCA[i] = PCA[i-1];
            if (++freq[A[i]] == 2) ++PCA[i];
            if (++freq[B[i]] == 2) ++PCA[i];
        }

        return PCA;
    }
};

