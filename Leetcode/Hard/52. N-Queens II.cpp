// 52. N-Queens II
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

class Solution {
public:
    int N;
    vi row; vb col, lft, rit;
    int res = 0;

    void putQueen(int r) {
        if (r == N) {
            ++res;
            return;
        }
        for (int c = 0; c < N; c++) {
            if (!col[c] && !lft[r+c] && !rit[r-c + (N-1)]) {
                row[r] = c;

                int lpos = r+c, rpos = r-c+(N-1);
                col[c] = lft[lpos] = rit[rpos] = true;
                putQueen(r+1);
                col[c] = lft[lpos] = rit[rpos] = false;
            }
        }
    }

    int totalNQueens(int n) {
        N = n;
        row.resize(n,0);
        col.resize(n,false); 
        lft.resize(2*n-1,false);
        rit.resize(2*n-1,false);

        putQueen(0);
        return res;
    }
};
