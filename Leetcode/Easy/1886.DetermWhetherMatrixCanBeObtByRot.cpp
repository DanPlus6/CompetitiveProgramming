// 1886. Determine Whether Matrix Can Be Obtained By Rotation
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define PRIMLOOP(N) for (int i = 0; i < N; i++)


class Solution {
public:
    static void rotate(vvi& matrix) {
        PRIMLOOP(matrix.size()) {
            for (int j = i+1; j < matrix.size(); j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        PRIMLOOP(matrix.size()) {
            reverse(ALL(matrix[i]));
        }
    }

    static bool findRotation(vvi& mat, vvi& target) {
        if (mat == target) return true;
        LOOP(3) {
            rotate(mat);
            if (mat == target) return true;
        }
        
        return false;
    }
};

// int main() {
//     vvi MAT = {{0,0,0},{0,1,0},{1,1,1}}, TAR = {{1,1,1},{0,1,0},{0,0,0}};
//     cout << (Solution::findRotation(MAT,TAR) ? "true\n" : "false\n");
// }

