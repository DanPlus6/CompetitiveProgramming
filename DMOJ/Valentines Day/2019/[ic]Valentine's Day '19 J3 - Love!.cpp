// Valentine's Day '19 J3 - Love!
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    map<char,int> ct = {
        {'e',0},
        {'v',0},
        {'o',0},
        {'l',0}
    };
    char word[10002];
    cin >> word;
    // char cur[2] = "e";
    for (int i = strlen(word)-1; i >= 0; i--) {
        ct[word[i]]++;
        // if (word[i] == cur[0]) {ct[word[i]]++;}
        // else if (cur[0] == 'e' && word[i] == 'v') {cur[0] = 'v'; ct[word[i]]++;}
        // else if (cur[0] == 'v' && word[i] == 'o') {cur[0] = 'o'; ct[word[i]]++;}
        // else if (cur[0] == 'o' && word[i] == 'l') {cur[0] = 'l'; ct[word[i]]++;}
    }

    cout << ct['e']*ct['v']*ct['o']*ct['l'] << "\n";

    return 0;
}
