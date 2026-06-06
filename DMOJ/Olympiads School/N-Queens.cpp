// N-Queens - backtrack2
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

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

int main() {
    scanf("%d",&N);

    row.resize(N,0);
    col.resize(N,false); 
    lft.resize(2*N-1,false);
    rit.resize(2*N-1,false);

    putQueen(0);
    printf("%d\n",res);

    return 0;
}
