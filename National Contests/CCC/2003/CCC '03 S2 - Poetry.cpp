// CCC '03 S2 - Poetry
#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define pb push_back


bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);  
    
    int N; cin >> N; cin.ignore();
    LOOP(N) {
        vs rhymes;
        string ln, word, syl;
        int ls, lv = 0;
        PRIMLOOP(4) {
            {
                getline(cin,ln);
                ls = ln.find_last_of(' '); 
                word = ((ls == string::npos) ? ln : ln.substr(ls+1));
            }

            for (lv = word.length()-1; lv >= 0; lv--) {
                if (isVowel(word[lv])) {
                    syl = word.substr(lv);
                    transform(ALL(syl),syl.begin(), ::tolower);
                    rhymes.pb(syl);
                    break;
                }
            }

            if (lv < 0) {
                transform(ALL(word),word.begin(), ::tolower);
                rhymes.pb(word);
            }
        }

        if (rhymes[0] == rhymes[1] && rhymes[1] == rhymes[2] && rhymes[2] == rhymes[3]) cout << "perfect\n";
        else if (rhymes[0] == rhymes[1] && rhymes[2] == rhymes[3]) cout << "even\n";
        else if (rhymes[0] == rhymes[2] && rhymes[1] == rhymes[3]) cout << "cross\n";
        else if (rhymes[0] == rhymes[3] && rhymes[1] == rhymes[2]) cout << "shell\n";
        else cout << "free\n";
    }

    return 0;
}
