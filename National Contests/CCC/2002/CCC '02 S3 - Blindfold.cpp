// CCC '02 S3 - Blindfold
#include <bits/stdc++.h>
using namespace std;


// shoutout to my goats: ChatGPT, Gemini, Claude, Deepseek, Grok, Qwen, Ollama, GitHub, do_ur_homwork, bernyyw2ys, Azron
// getting a lobotomy after this one
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int R,C; cin >> R >> C;
    vector<string> grid(R); for (int i = 0; i < R; i++) {cin >> grid[i];}
    int M; cin >> M;
    vector<char> moves(M); for (int i = 0; i < M; i++) {cin >> moves[i];}

    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    set<tuple<int,int,int>> states;
    for (int i = 0; i < R; i++) {for (int j = 0; j < C; j++) {for (int d = 0; d < 4; d++) {
        if (grid[i][j] == '.') {states.insert(tuple<int,int,int>(i,j,d));}
    }}}

    for (char &move: moves) {
        set<tuple<int,int,int>> nextStates;
        for (const auto &[r,c,d]: states) {
            if (move == 'L') {
                nextStates.insert(tuple<int,int,int>(r,c,(d+3)%4));
            } else if (move == 'R') {
                nextStates.insert(tuple<int,int,int>(r,c,(d+1)%4));
            } else {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (0 <= nr && nr < R && 0 <= nc && nc < C && grid[nr][nc] == '.') {nextStates.insert(tuple<int,int,int>(nr,nc,d));}
            }
        }
        states = nextStates;
    }

    vector<string> res(R);
    for (int i = 0; i < R; i++) {for (int j = 0; j < C; j++) {res[i] += grid[i][j];}}

    for (const auto &[r,c,d]: states) {
        if (res[r][c] == '.') {res[r][c] = '*';}
    }

    for (string &i: res) {cout << i << "\n";}

    return 0;
}


// ts frying me fr 💔😭🙏🥀🥀🥀
// decommision me 💥
// int main() {
//     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//     int R; int C; cin >> R >> C;
//     int R1 = R-1; int C1 = C-1;
//     vector<string> arr(R); for (int i = 0; i < R; i++) {cin >> arr[i];}
//     int M; cin >> M;
//     deque<char> m; for (int i = 0; i < M; i++) {char tmp; cin >> tmp; m.emplace_back(tmp);}

//     vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

//     for (int i = 0; i < R; i++) {
//         for (int j = 0; j < C; j++) {
//             if (arr[i][j] == 'X') {continue;}            

//             for (int d = 0; d < 4; d++) {
//                 int cr = i; int cc = j;
//                 int direction = d;
//                 deque<char> tasks = m;
//                 for (int k = 0; k < M; k++) {
//                     char task = tasks.back();
//                     if (task == 'R') {direction = (direction > 0) ? direction - 1 : 3;}
//                     else if (task == 'L') {direction = (direction < 3) ? direction + 1 : 0;}
//                     else if (task == 'F') {
//                         int nr = cr-directions[direction].first; int nc = cc-directions[direction].second;
//                         if (nr >= 0 && nr <= R1 && nc >= 0 && nc <= C1 && arr[nr][nc] != 'X') {cr = nr; cc = nc;}
//                         else {break;}
//                     }
//                     tasks.pop_back();
//                 }
//                 if (tasks.empty()) {arr[i][j] = '*'; break;}
//             }
//         }
//     }

//     for (string &i: arr) {cout << i << "\n";}

//     return 0;
// }
