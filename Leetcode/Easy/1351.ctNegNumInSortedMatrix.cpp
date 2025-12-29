#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid[0].size()-1;

        int res = 0;
        for (vector<int> &row: grid) {        
            int l = 0, h = m;
            while (l <= h) {
                int mid = l + (h-l) / 2;
                if (mid > 0 && row[mid] < 0 && row[mid-1] < 0) {h = mid-1;}
                else if (row[mid] >= 0) {l = mid+1;}
                else if (mid == 0 && row[mid] < 0) {res += m+1; break;}
                else if (row[mid] < 0 && row[mid-1] >= 0) {res += (m+1)-mid; break;}
                else if (mid == 0 && row[mid] >= 0) {break;}
            }
        }
        return res;
    }
};

// int main() {
//     vector<vector<int>> grid = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
//     int m = grid[0].size()-1;

//     int res = 0;
//     for (vector<int> &row: grid) {        
//         int l = 0, h = m;
//         while (l <= h) {
//             int mid = l + (h-l) / 2;
//             if (mid > 0 && row[mid] < 0 && row[mid-1] < 0) {h = mid-1;}
//             else if (row[mid] >= 0) {l = mid+1;}
//             else if (mid == 0 && row[mid] < 0) {res += m+1; break;}
//             else if (row[mid] < 0 && row[mid-1] >= 0) {res += (m+1)-mid; break;}
//             else if (mid == 0 && row[mid] >= 0) {break;}
//         }
//     }
//     cout << res << "\n";

//     return 0;
// }
