// 401. Binary Watch
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                char cres[6];
                string hs = bitset<8>(h).to_string();
                string ms = bitset<8>(m).to_string();
                if (count(hs.begin(),hs.end(),'1') + count(ms.begin(),ms.end(),'1') == turnedOn) {
                    snprintf(cres,sizeof(cres), "%d:%02d", h, m);
                    res.push_back(cres);
                }
            }
        }
        return res;
    }
};

// int main() {
//     for (string s: Solution::readBinaryWatch(10)) {
//         cout << s << endl;
//     }
    
//     return 0;
// }
