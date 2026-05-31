// 51. N-Queens
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
#define pb push_back

class Solution {
public:
    int N;
    vi row; vb col, lft, rit;
    vector<vs> res;

    void putQueen(int r) {
        if (r == N) {
            vs tmpres; string cur;
            for (int i=0;i<N;i++) {
                for (int j=0;j<N;j++) cur += (j != row[i] ? '.' : 'Q');
                tmpres.pb(cur); cur = "";
            }
            res.pb(tmpres);
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

    vector<vs> solveNQueens(int n) {
        N = n;
        row.resize(n,0);
        col.resize(n,false); 
        lft.resize(2*n-1,false);
        rit.resize(2*n-1,false);

        putQueen(0);
        return res;
    }
};
