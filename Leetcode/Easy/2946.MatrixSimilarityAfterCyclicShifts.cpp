// 2946. Matrix Similarity After Cyclic Shifts
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    static bool areSimilar(vvi &mat, int k) {
        #define N size(mat[0])
        #define M size(mat)
        k %= N;
        for (int r = 0; r < M; r++) {
            if (r & 1) {
                for (int c = 0; c < N; c++) {
                    if (mat[r][c] != mat[r][(c + k) % N]) return false;
                }
            } else {
                for (int c = 0; c < N; c++) {
                    if (mat[r][c] != mat[r][(c - k + N) % N]) return false;
                }
            }
        }
        return true;
    }
};

// int main() {
//     vvi mat = {{1,2,1,2},{5,5,5,5},{6,3,6,3}};
//     Solution::areSimilar(mat, 2);
// }
