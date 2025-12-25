// CCC '02 S3 - Blindfold
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int R; int C; cin >> R >> C;
    int R1 = R-1; int C1 = C-1;
    vector<string> arr(R); for (int i = 0; i < R; i++) {cin >> arr[i];}
    int M; cin >> M;
    deque<char> m; for (int i = 0; i < M; i++) {char tmp; cin >> tmp; m.emplace_back(tmp);}

    vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] == 'X') {continue;}            

            for (int d = 0; d < 4; d++) {
                int cr = i; int cc = j;
                int direction = d;
                deque<char> tasks = m;
                for (int k = 0; k < M; k++) {
                    char task = tasks.back();
                    if (task == 'R') {direction = (direction > 0) ? direction - 1 : 3;}
                    else if (task == 'L') {direction = (direction < 3) ? direction + 1 : 0;}
                    else if (task == 'F') {
                        int nr = cr-directions[direction].first; int nc = cc-directions[direction].second;
                        if (nr >= 0 && nr <= R1 && nc >= 0 && nc <= C1 && arr[nr][nc] != 'X') {cr = nr; cc = nc;}
                        else {break;}
                    }
                    tasks.pop_back();
                }
                if (tasks.empty()) {arr[i][j] = '*'; break;}
            }
        }
    }

    for (string &i: arr) {cout << i << "\n";}

    return 0;
}
