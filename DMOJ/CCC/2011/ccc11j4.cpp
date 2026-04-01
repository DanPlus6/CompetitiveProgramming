// CCC '11 J4 - Boring Business
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef vector<pi> vii;
typedef vector<bool> vb;
#define ILOOP(n) for (int i = 0; i < n; i++)


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<vb> vis(201,vb(500,false));
    vii starting = {{0,-1},{0,-2},{0,-3},{1,-3},{2,-3},{3,-3},{3,-4},{3,-5},{4,-5},{5,-5},{5,-4},{5,-3},{6,-3},{7,-3},{7,-4},{7,-5},{7,-6},{7,-7},{6,-7},{5,-7},{4,-7},{3,-7},{2,-7},{1,-7},{0,-7},{-1,-7},{-1,-6},{-1,-5}};
    for (pi cc: starting) {
        vis[-cc.second][cc.first+200] = true;
    }

    int row = 5, col = 199;
    while (true) {
        char dir; int dist;
        cin >> dir >> dist;

        int runrow = row, runcol = col;
        bool danger = false;
        if (dir == 'q') return 0;
        else if (dir == 'd') {
            ILOOP(dist) {
                runrow++;
                if (!(0 <= runrow && runrow <= 200) || !(0 <= runcol && runcol <= 499) || vis[runrow][runcol]) {danger = true; break;}
                vis[runrow][runcol] = true;
            }
        } else if (dir == 'u') {
            ILOOP(dist) {
                runrow--;
                if (!(0 <= runrow && runrow <= 200) || !(0 <= runcol && runcol <= 499) || vis[runrow][runcol]) {danger = true; break;}
                vis[runrow][runcol] = true;
            }
        } else if (dir == 'l') {
            ILOOP(dist) {
                runcol--;
                if (!(0 <= runrow && runrow <= 200) || !(0 <= runcol && runcol <= 499) || vis[runrow][runcol]) {danger = true; break;}
                vis[runrow][runcol] = true;
            }
        } else if (dir == 'r') {
            ILOOP(dist) {
                runcol++;
                if (!(0 <= runrow && runrow <= 200) || !(0 <= runcol && runcol <= 499) || vis[runrow][runcol]) {danger = true; break;}
                vis[runrow][runcol] = true;
            }
        }

        switch (dir) {
            case 'l': col -= dist; break;
            case 'r': col += dist; break;
            case 'u': row -= dist; break;
            case 'd': row += dist; break;
            case 'q': return 0;
        }
        
        
        cout << col-200 << " " << -row << " ";
        if (!danger) cout << "safe\n";
        else {cout << "DANGER\n"; return 0;}
    }

    return 0;
}
