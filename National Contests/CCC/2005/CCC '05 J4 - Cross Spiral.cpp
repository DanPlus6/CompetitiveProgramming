// CCC '05 J4 - Cross Spiral
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

bool g[22][22];
int w, h, cw, ch, steps;
int c, r, direction;
bool moving;

int main() {
    cin >> w >> h >> cw >> ch >> steps;

    for (int i = 0; i <= 21; i++) {
        for (int j = 0; j <= 21; j++) {
            if (i >= 1 && i <= h && j >= 1 && j <= w &&
                !((i <= ch && (j <= cw || j > w - cw)) ||
                  (i > h - ch && (j <= cw || j > w - cw)))) {
                g[i][j] = true;
            } else {
                g[i][j] = false;
            }
        }
    }

    c = cw + 1;
    r = 1;
    direction = 0;

    for (int i = 1; i <= steps; i++) {
        g[r][c] = false;
        moving = true;

        if (direction == 0) {
            if (g[r - 1][c]) {
                r--;
                direction = 90;
            } else if (g[r][c + 1]) {
                c++;
                direction = 0;
            } else if (g[r + 1][c]) {
                r++;
                direction = 270;
            } else if (g[r][c - 1]) {
                c--;
                direction = 180;
            } else {
                moving = false;
            }
        } else if (direction == 90) {
            if (g[r][c - 1]) {
                c--;
                direction = 180;
            } else if (g[r - 1][c]) {
                r--;
                direction = 90;
            } else if (g[r][c + 1]) {
                c++;
                direction = 0;
            } else if (g[r + 1][c]) {
                r++;
                direction = 270;
            } else {
                moving = false;
            }
        } else if (direction == 180) {
            if (g[r + 1][c]) {
                r++;
                direction = 270;
            } else if (g[r][c - 1]) {
                c--;
                direction = 180;
            } else if (g[r - 1][c]) {
                r--;
                direction = 90;
            } else if (g[r][c + 1]) {
                c++;
                direction = 0;
            } else {
                moving = false;
            }
        } else if (direction == 270) {
            if (g[r][c + 1]) {
                c++;
                direction = 0;
            } else if (g[r + 1][c]) {
                r++;
                direction = 270;
            } else if (g[r][c - 1]) {
                c--;
                direction = 180;
            } else if (g[r - 1][c]) {
                r--;
                direction = 90;
            } else {
                moving = false;
            }
        }

        if (!moving) break;
    }

    cout << c << endl;
    cout << r << endl;

    return 0;
}
