// CCC '15 J3 - Rövarspråket
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string S; cin >> S;
    string res = "";
    set<char> vowels = {'a','e','i','o','u'};
    set<int> vowels_a = {100,104,110,116};
    for (char i: S) {
        res += i;
        if (vowels.find(i) != vowels.end()) continue;
        
        int ascii = (int)i;
        if (ascii > 97 && ascii <= 99) {res += 'a';}
        else if (ascii > 99 && ascii <= 103) {res += 'e';}
        else if (ascii > 103 && ascii <= 108) {res += 'i';}
        else if (ascii > 108 && ascii <= 114) {res += 'o';}
        else if (ascii > 114) {res += 'u';}

        if (i == 'z') {res += 'z';}
        else {
            if (vowels_a.find(ascii) == vowels_a.end()) { res += (char)(ascii+1); }
            else { res += (char)(ascii+2); }
        }

    }
    cout << res << "\n";
    return 0;
}
