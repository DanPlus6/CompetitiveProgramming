// 2379. Minimum Records to Get K Consecutive Black Blocks
#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 0x3F3F3F3F;


class Solution {
public:
    static int minimumRecolors(string blocks, int k) {
        blocks += ' ';

        int black = 0, white = 0;
        int res = INF;
        for (int i = 0; i < blocks.size(); i++) {            
            if (i >= k) {
                if (!white) return 0;
                res = min(res, white);

                if (blocks[i-k] == 'B') black--;
                else white--;
            }

            if (blocks[i] == 'B') black++;
            else white++;
        }

        return res;
    }
};
