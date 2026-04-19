// Problem J4: Snail Path
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
#define endl "\n"

map<char,pi> dir = {{'N',{0,-1}}, {'S',{0,1}}, {'W',{-1,0}}, {'E',{1,0}}};
int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    set<pi> vis;

    pi pos = {0,0}; vis.emplace(pos);
    int M; cin >> M;
    int res = 0;
    for (int m = 0; m < M; m++) {
        string instruction; cin >> instruction;
        int dist = stoi(instruction.substr(1));
        
        pi cdir = dir[instruction[0]];
        
        for (int d = 0; d < dist; d++) {
            pos.first += cdir.first;
            pos.second += cdir.second;

            if (vis.count(pos)) res++;
            else vis.emplace(pos);
        }
    }

    cout << res << endl;

    return 0;
}

// int MM = 1203;
// vector<vector<bool>> vis(MM,vector<bool>(MM,false));
// map<char,pi> dir = {{'N',{0,-1}}, {'S',{0,1}}, {'W',{-1,0}}, {'E',{1,0}}};
// int main() {
//     ios::sync_with_stdio(false); cin.tie(0);

//     int pos_x = 601, pos_y = 601; vis[601][601] = true;
//     int M; cin >> M;
//     int res = 0;
//     for (int m = 0; m < M; m++) {
//         string instruction; cin >> instruction;
//         int dist = stoi(instruction.substr(1));
        
//         pi cdir = dir[instruction[0]];
        
//         for (int d = 0; d < dist; d++) {
//             pos_x += cdir.first;
//             pos_y += cdir.second;

//             if (vis[pos_x][pos_y]) res++;
//             else vis[pos_x][pos_y] = true;
//         }
//     }

//     cout << res << endl;

//     return 0;
// }   


    
