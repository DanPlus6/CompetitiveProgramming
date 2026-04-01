// CCC '04 J4 - Simple Encryption
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int myint;

map<char,int> alpha = {{'A',0},{'B',1},{'C',2},{'D',3},{'E',4},{'F',5},{'G',6},{'H',7},{'I',8},{'J',9},{'K',10},{'L',11},{'M',12},{'N',13},{'O',14},{'P',15},{'Q',16},{'R',17},{'S',18},{'T',19},{'U',20},{'V',21},{'W',22},{'X',23},{'Y',24},{'Z',25}};
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string keyword;
    getline(cin, keyword);

    string raw;
    getline(cin,raw);
    int i = 0; char c;
    for (myint j = 0; j < raw.length(); j++) {
        c = raw[j];
        if (isalpha(c)) {
            int res = ((int)c + alpha[keyword[i%keyword.length()]]) % 91;
            cout << ((res >= 65) ? (char)res : (char)(res+65));
            i++;
        }
    }


    return 0;
}
