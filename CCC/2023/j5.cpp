// CCC '23 J5 - CCC Word Hunt
#include <bits/stdc++.h>
using namespace std;

string W;
int R,C;
int N;
int main() {
    getline(cin,W);
    N = W.length();
    cin >> R >> C;
    vector<vector<char>> grid(R);
    vector<pair<int,int>> start;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
            start.push_back({i,j});
        }
    }

    int res = 0;
    for (pair<int,int> curHeader: start) {
        
    }

    return 0;
}
