// CCC '23 J5 - CCC Word Hunt
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    char W[200]; cin >> W;
    int R,C; cin >> R >> C;
    int N; N = strlen(W);
    //  0:up, 1:up-right, 2:right, 3:down-right, 4:down, 5:down-left, 6:left, 7:up-left
    int dr[8] = {-1,-1,0,1,1,1,0,-1};
    int dc[8] = {0,1,1,1,0,-1,-1,-1};

    vector<vector<char>> grid(R);
    vector<pair<int,int>> start;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char tmp; cin >> tmp;
            grid[i].push_back(tmp);
            if (tmp == W[0]) {start.push_back({i,j});}
        }
    }


    int res = 0;
    for (pair<int,int> curHeader: start) {
        char word[200];
        vector<vector<bool>> v(R,vector<bool>(C,false));
        queue<vector<int>> q;

                        // r, c, i (index of word), dir, turned
        //  0:up, 1:up-right, 2:right, 3:down-right, 4:down, 5:down-left, 6:left, 7:up-left
        q.push({curHeader.first,curHeader.second,0,0,0});
        v[curHeader.first][curHeader.second] = true;

        int res = 0;
        while (!q.empty()) {
            int row = q.front()[0], column = q.front()[1], ind = q.front()[2], dir = q.front()[3], turned = q.front()[4]; q.pop();
            
            
        }
    }

    cout << res << "\n";

    return 0;
}
