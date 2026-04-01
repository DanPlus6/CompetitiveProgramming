// Problem J3: Creative Candy Consumption
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    queue<char> NL; {
        string S; cin >> S; for (char c: S) NL.push(c);
    }
    queue<char> ML; {
        string S; cin >> S; for (char c: S) ML.push(c);
    }
    {
        int N = NL.size();
        int M = ML.size();
        if (NL.empty() && ML.empty()) {cout << 0 << endl << 0; return 0;}
        else if (NL.empty()) {cout << 0 << endl << M; return 0;}
        else if (ML.empty()) {cout << N << endl << 0; return 0;}
    }

    int resn = 0, resm = 0;
    while (!NL.empty() && !ML.empty()) {
        char nc = NL.front(), mc = ML.front(); 
        
        if (nc == mc) {resn++; resm++; NL.pop(); ML.pop();}
        // Ngoc win
        else if ((nc == 'R' && mc == 'G') || (nc == 'G' && mc == 'B') || (nc == 'B' && mc == 'R')) {resn++; ML.pop();}
        // Minh win
        else if ((mc == 'R' && nc == 'G') || (mc == 'G' && nc == 'B') || (mc == 'B' && nc == 'R')) {resm++; NL.pop();}
    }

    if (NL.empty()) {resm += ML.size();}
    else if (ML.empty()) {resn += NL.size();}


    cout << resn << endl << resm;
    return 0;
}   


    
